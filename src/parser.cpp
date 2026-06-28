#include "parser.h"
#include <fstream>
#include <algorithm>

JdatParser::JdatParser() {}

JdatParser::~JdatParser() {
    data_store.clear();
    conf_store.clear();
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (std::string::npos == first) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

std::string strip_quotes(const std::string& str) {
    if (str.length() >= 2 && str.front() == '"' && str.back() == '"') {
        return str.substr(1, str.length() - 2);
    }
    return str;
}

bool JdatParser::load_conf(const std::string& path) {
    if (path.empty()) return false;
    
    return true;
}

bool JdatParser::load_data(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) return false;

    std::string line;
    int state = 0; 
    JdatData current_data;
    std::string current_link;

    while (std::getline(file, line)) {
        size_t comment_pos = line.find("//");
        if (comment_pos != std::string::npos) {
            line = line.substr(0, comment_pos);
        }
        
        line = trim(line);
        if (line.empty()) continue;

        if (line == "{") {
            state = 1;
            current_data = JdatData();
            current_link = "";
        } else if (line == "(") {
            state = 2;
        } else if (line == ")") {
            state = 1;
        } else if (line == "}") {
            state = 0;
            if (!current_link.empty()) {
                data_store[current_link] = current_data;
            }
        } else if (state == 1 || state == 2) {
            size_t eq_pos = line.find('=');
            if (eq_pos != std::string::npos) {
                std::string key = trim(line.substr(0, eq_pos));
                std::string val = strip_quotes(trim(line.substr(eq_pos + 1)));

                if (state == 1) {
                    if (key == "name") current_data.name = val;
                    else if (key == "type") current_data.type = val;
                    else if (key == "link") current_link = val;
                } else if (state == 2) {
                    current_data.attributes[key] = val;
                }
            }
        }
    }
    return true;
}

std::string JdatParser::get_variable(const std::string& query) {
    size_t pipe_pos = query.find('|');
    if (pipe_pos != std::string::npos) {
        std::string link_id = query.substr(0, pipe_pos);
        std::string attr = query.substr(pipe_pos + 1);
        
        if (data_store.find(link_id) != data_store.end()) {
            if (data_store[link_id].attributes.find(attr) != data_store[link_id].attributes.end()) {
                return data_store[link_id].attributes[attr];
            }
        }
    }
    return "";
}
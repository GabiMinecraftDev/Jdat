#ifndef JDAT_PARSER_H
#define JDAT_PARSER_H

#include <string>
#include <unordered_map>

struct JdatData {
    std::string name;
    std::string type;
    std::unordered_map<std::string, std::string> attributes;
};

class JdatParser {
public:
    JdatParser();
    ~JdatParser();
    bool load_conf(const std::string& path);
    bool load_data(const std::string& path);
    std::string get_variable(const std::string& link_id);

private:
    std::unordered_map<std::string, JdatData> data_store;
    std::unordered_map<std::string, std::string> conf_store;
};

#endif
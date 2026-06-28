#include "../include/jdat.h"
#include "parser.h"
#include "crypto.h"
#include <vector>
#include <cstring>

struct JdatEngine {
    JdatParser parser;
    JdatCrypto crypto;
};

extern "C" {

JDAT_API JdatEngine* jdat_init(const char* conf_path) {
    if (!conf_path) return nullptr;

    JdatEngine* engine = new JdatEngine();
    if (!engine->parser.load_conf(conf_path)) {
        delete engine;
        return nullptr;
    }
    return engine;
}

JDAT_API int jdat_read_var(JdatEngine* engine, const char* link_id, const char* key, char* output_buffer, int buffer_size) {
    if (!engine || !link_id || !output_buffer || buffer_size <= 0) return -1;

    std::string raw_value = engine->parser.get_variable(link_id);
    if (raw_value.empty()) return 0;

    std::string final_value;
    if (key != nullptr && strlen(key) > 0) {
        engine->crypto.set_key(key);
        std::vector<uint8_t> encrypted_data(raw_value.begin(), raw_value.end());
        final_value = engine->crypto.decrypt(encrypted_data);
    } else {
        final_value = raw_value;
    }

    if (final_value.length() >= static_cast<size_t>(buffer_size)) return -2;

    std::strncpy(output_buffer, final_value.c_str(), buffer_size);
    output_buffer[final_value.length()] = '\0';
    
    return 1;
}

JDAT_API void jdat_close(JdatEngine* engine) {
    if (engine) {
        delete engine;
    }
}

}
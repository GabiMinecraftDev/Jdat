#ifndef JDAT_H
#define JDAT_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
    #define JDAT_API __declspec(dllexport)
#else
    #define JDAT_API __attribute__((visibility("default")))
#endif

typedef struct JdatEngine JdatEngine;

JDAT_API JdatEngine* jdat_init(const char* conf_path);
JDAT_API int jdat_read_var(JdatEngine* engine, const char* link_id, const char* key, char* output_buffer, int buffer_size);
JDAT_API void jdat_close(JdatEngine* engine);

#ifdef __cplusplus
}
#endif

#endif
#ifndef LOG_H
#define LOG_H

#include <stdio.h>

#define LOG_INFO(fmt, ...) \
    printf("[INFO] " fmt, ##__VA_ARGS__)

#define LOG_WARN(fmt, ...) \
    printf("[WARN] " fmt, ##__VA_ARGS__)

#define LOG_ERROR(fmt, ...) \
    printf("[ERROR] " fmt, ##__VA_ARGS__)

#endif
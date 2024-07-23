#pragma once 
#include <cstdio>
#include <cstring>
#include <cstdarg>  // 提取可变参数
#include <ctime>

enum LogLevel
{
    DEBUG = 0,  //0
    NOTICE,
    WARNING,
    ERROR,
    FATAL
};

#define LOGFILE "./log.txt"

// 日志: 默认(日志级别，时间) + 用户自定义(文件，行号)...
void logMessage(enum LogLevel level, const char* format, ...) // 可变参数
{
#ifndef __DEBUG__   // 非DEBUG模式，不显示debug日志信息; 避免命名混淆
    if (level == DEBUG)
    {
        return;
    }
#endif

    static const char* levelMap[5] = { "DEBUG","NOTICE","WARNING","ERROR","FATAL" };
    // 默认(日志级别，时间)
    char baseBuffer[1024] = { 0 };
    time_t tim = time(nullptr);
    struct tm local_time;
    localtime_s(&local_time, &tim);
    snprintf(baseBuffer, sizeof baseBuffer, "log [%s] [%d-%d-%d %02d:%02d:%02d] ",
        levelMap[level], local_time.tm_year + 1900, local_time.tm_mon + 1, local_time.tm_mday,
        local_time.tm_hour, local_time.tm_min, local_time.tm_sec);

    // 用户自定义  --文件，行号 __FILE__, __LINE__显示当前的，所以需要用户自定义
    char userBuffer[1024] = { 0 };
    va_list args;
    va_start(args, format); // 初始化
    _vsnprintf_s(userBuffer, sizeof userBuffer, format, args); // 格式化输入
    va_end(args);
    // todo: 加入错误码和错误码描述

#ifdef __LOG_FILE__
    // 输出到日志文件
    FILE* fp = fopen(LOGFILE, "a");
    if (nullptr == fp)
    {
        perror("log.txt open error");
        exit(1);
    }
    fprintf(fp, "%s%s\n", baseBuffer, userBuffer);
    fclose(fp);
#else
    // 输出到显示器
    printf("%s%s\n", baseBuffer, userBuffer);
#endif
}
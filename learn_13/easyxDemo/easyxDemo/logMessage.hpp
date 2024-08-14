#pragma once 
#include <cstdio>
#include <cstring>
#include <cstdarg>  // ��ȡ�ɱ����
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

// ��־: Ĭ��(��־����ʱ��) + �û��Զ���(�ļ����к�)...
void logMessage(enum LogLevel level, const char* format, ...) // �ɱ����
{
#ifndef __DEBUG__   // ��DEBUGģʽ������ʾdebug��־��Ϣ; ������������
    if (level == DEBUG)
    {
        return;
    }
#endif

    static const char* levelMap[5] = { "DEBUG","NOTICE","WARNING","ERROR","FATAL" };
    // Ĭ��(��־����ʱ��)
    char baseBuffer[1024] = { 0 };
    time_t tim = time(nullptr);
    struct tm local_time;
    localtime_s(&local_time, &tim);
    snprintf(baseBuffer, sizeof baseBuffer, "log [%s] [%d-%d-%d %02d:%02d:%02d] ",
        levelMap[level], local_time.tm_year + 1900, local_time.tm_mon + 1, local_time.tm_mday,
        local_time.tm_hour, local_time.tm_min, local_time.tm_sec);

    // �û��Զ���  --�ļ����к� __FILE__, __LINE__��ʾ��ǰ�ģ�������Ҫ�û��Զ���
    char userBuffer[1024] = { 0 };
    va_list args;
    va_start(args, format); // ��ʼ��
    _vsnprintf_s(userBuffer, sizeof userBuffer, format, args); // ��ʽ������
    va_end(args);
    // todo: ���������ʹ���������

#ifdef __LOG_FILE__
    // �������־�ļ�
    FILE* fp = fopen(LOGFILE, "a");
    if (nullptr == fp)
    {
        perror("log.txt open error");
        exit(1);
    }
    fprintf(fp, "%s%s\n", baseBuffer, userBuffer);
    fclose(fp);
#else
    // �������ʾ��
    printf("%s%s\n", baseBuffer, userBuffer);
#endif
}
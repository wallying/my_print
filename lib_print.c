/**
 * file:    lib_print.c
 * author:  wallying@foxmail.com
 * date:    2019-12-18
 **/


#include "lib_print.h"


static unsigned int str_len(const char *str)
{
    const char *ptr = str;
    for (; *ptr != '\0'; ++ptr);
    return ptr - str;
}


static char *itoa(int val, char *buf, unsigned int base)
{
    char *ptr = buf;
    int neg = 0;
    int dig = 0;

    if (val < 0) {
        neg = 1;
        val = -val;
    }

    do {
        dig = val % base;
        *(ptr++) = (dig < 10 ? dig + '0' : dig - 10 + 'A');
        val /= base;
    } while (val > 0);
    if (neg) {
        *(ptr++)  = '-';
    }
    *ptr = '\0';

    /* reverse it */
    unsigned int len = (ptr - buf);
    for (unsigned int i = 0; i < len / 2; i++) {
        char tmp = buf[i];
        buf[i] = buf[len - i - 1];
        buf[len - i - 1] = tmp;
    }

    return ptr;
}


int vsnprintf(char *buf, unsigned int num, const char *fmt, va_list arg)
{
    char *ptr = buf;
    char *end = buf + num - 1;
    const char *str;
    unsigned int strlen = 0;

    for (; *fmt; ++fmt)
    {
        if (*fmt != '%') {
            if (ptr <= end) {
                *ptr = *fmt;
            }
            ++ ptr;
            continue;
        }

        fmt++;
        switch (*fmt) {
        case 'u':
        case 'd':
            ptr = itoa(va_arg(arg, int), ptr, 10);
            break;

        case 'x':
        case 'X':
            ptr = itoa(va_arg(arg, int), ptr, 16);
            break;

        case 'c':
            if (ptr <= end) {
                *(ptr++) = (char)(va_arg(arg, int));
            }
            *ptr = '\0';
            break;

        case 's':
            str = va_arg(arg, char *);
            strlen = str_len(str);
            while (strlen--) {
                if (ptr <= end) {
                    *ptr = *str;
                }
                ++ptr;
                ++str;
            }
            *ptr = '\0';
            break;

        default:
            if (ptr <= end) {
                *(ptr++) = *fmt;
            }
            *ptr = '\0';
            break;
        }
    }

    return ptr - buf;
}


int sprintf(char *buf, const char *fmt, ...)
{
    va_list arg;
    va_start(arg, fmt);
    int len = vsnprintf(buf, ((unsigned int)(~0)), fmt, arg);
    va_end(arg);
    return len;
}


int snprintf(char *buf, unsigned int num, const char *fmt, ...)
{
    va_list arg;
    va_start(arg, fmt);
    int len = vsnprintf(buf, num, fmt, arg);
    va_end(arg);
    return len;
}


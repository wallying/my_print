/**
 * file:    lib_print.c
 * author:  wallying@foxmail.com
 * date:    2019-12-19
 **/


#include "lib_print.h"


#define SIGN        (1 << 0)    /* signed type for decimal */
#define ZERO        (1 << 1)    /* zero front for decimal or hexadecimal */
#define UPPER       (1 << 2)    /* upper case for hexadecimal */
#define LEFT        (1 << 3)    /* left justified */



static char *print_char(char *buf, char *end, int val, int flag, int width)
{
    char *ptr = buf;
    char tmp = 0;

    tmp = (char)val;

    --width;
    /* space character */
    if (!(flag & LEFT)) {
        while (width > 0) {
            if (ptr < end) {
                *(ptr++) = ' ';
                --width;
                continue;
            }
            break;
        }
    }
    if (ptr < end) {
        *(ptr++) = tmp;
    }
    /* space character */
    while (width > 0) {
        if (ptr < end) {
            *(ptr++) = ' ';
            --width;
            continue;
        }
        break;
    }

    return ptr;
}

static char *print_num(char *buf, char *end, int val, unsigned int base, int flag, int width)
{
    char *ptr = buf;
    char tmp[16];
    int neg = 0;
    int dig = 0;
    int i = 0;

    if ((flag & SIGN) && (val < 0)) {
        neg = 1;
        val = -val;
    }

    i = 0;
    do {
        dig = val % base;
        tmp[i++] = ((dig < 10) ? dig + '0' : dig - 10 + ((flag & UPPER) ? 'A' : 'a'));
        val /= base;
    } while (val > 0);

    width -= (i + neg);

    /* space character */
    if (!(flag & (ZERO | LEFT))) {
        while (width > 0) {
            if (ptr < end) {
                *(ptr++) = ' ';
                --width;
                continue;
            }
            break;
        }
    }

    /* minus character */
    if (neg) {
        if (ptr < end) {
            *(ptr++) = '-';
        }
    }

    /* zero pad character */
    if (!(flag & LEFT)) {
        while (width > 0) {
            if (ptr < end) {
                *(ptr++) = '0';
                --width;
                continue;
            }
            break;
        }
    }

    /* number character */
    while (i--) {
        if (ptr < end) {
            *(ptr++) = tmp[i];
            continue;
        }
        break;
    }

    /* space character */
    while (width > 0) {
        if (ptr < end) {
            *(ptr++) = ' ';
            --width;
            continue;
        }
        break;
    }

    return ptr;
}



int print_vsnprintf(char *buf, unsigned int num, const char *fmt, va_list arg)
{
    char *ptr = buf;
    char *end = buf + num;
    const char *str;
    int flag = 0;
    int width = 0;

    /* make sure end is always >= ptr */
    if (end < ptr) {
        end  = ((char *)-1);
        num = end - ptr;
    }

    for (; *fmt; ++fmt) {
        if (*fmt != '%') {
            if (ptr < end) {
                *(ptr++) = *fmt;
                continue;
            }
            break;
        }

        /* process flag */
        flag = 0;
        while (1) {
            ++fmt; /* skip the first '%' character */
            if (*fmt == '0') {
                flag |= ZERO;
            } else if (*fmt == '-') {
                flag |= LEFT;
            } else {
                break;
            }
        }

        /* get field width */
        width = 0;
        while ((*fmt >= '0') && (*fmt <= '9')) {
            width = width * 10 + (*(fmt++) - '0');
        }

        switch (*fmt) {
        case 'c':
            ptr = print_char(ptr, end, va_arg(arg, int), flag, width);
            break;
        case 's':
            str = va_arg(arg, char *);
            for (; *str != '\0'; ++str) {
                if (ptr < end) {
                    *(ptr++) = *str;
                    continue;
                }
                break;
            }
            break;
        case 'd': /* signed dec */
            flag |= SIGN;
        case 'u': /* unsigned dec */
            ptr = print_num(ptr, end, va_arg(arg, int), 10, flag, width);
            break;
        case 'X': /* unsigned upper hex */
            flag |= UPPER;
        case 'x': /* unsigned lower hex */
            ptr = print_num(ptr, end, va_arg(arg, int), 16, flag, width);
            break;
        default:
            if (ptr < end) {
                *(ptr++) = *fmt;
            }
            break;
        }
    }

    if (num > 0) {
        if (ptr < end) {
            *ptr = '\0';
        } else {
            *(--end) = '\0';
        }
    }

    return ptr - buf;
}


int print_sprintf(char *buf, const char *fmt, ...)
{
    va_list arg;
    va_start(arg, fmt);
    int len = print_vsnprintf(buf, ((unsigned int)(~0)), fmt, arg);
    va_end(arg);
    return len;
}


int print_snprintf(char *buf, unsigned int num, const char *fmt, ...)
{
    va_list arg;
    va_start(arg, fmt);
    int len = print_vsnprintf(buf, num, fmt, arg);
    va_end(arg);
    return len;
}


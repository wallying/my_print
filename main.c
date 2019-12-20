/**
 * file:    main.c
 * author:  wallying@foxmail.com
 * date:    2019-12-19
 **/


#include <stdio.h>
#include <string.h>
#include "lib_print.h"


/*******************************************************************************
lib_print
    support type:
    %%      - single % character
    %c      - single character
    %s      - string of characters
    %d      - signed decimal integer
    %u      - unsigned decimal integer
    %x      - unsigned hexadecimal integer (lowercase)
    %X      - unsigned hexadecimal integer (uppercase)
*******************************************************************************/
#define BUF_LEN (100)

char buf1[BUF_LEN] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char buf2[BUF_LEN] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";



int main(int argc, char *argv[])
{
    printf("hello lib_print!\n\n");

    /*========================================================================*/
#if 1
          snprintf(buf1, sizeof(buf1), "char=%c,%3c,%-5c,%12c,%%\n", 'A', 97, 'X', '%');
    print_snprintf(buf2, sizeof(buf2), "char=%c,%3c,%-5c,%12c,%%\n", 'A', 97, 'X', '%');
    printf("%s", buf1);
    printf("%s", buf2);
    putchar('\n');
#endif
    /*========================================================================*/
#if 1
          snprintf(buf1, sizeof(buf1), "str=%s,%5s,%-5s,%-s\n", "aaa", "bbb", "ccc", "ddd");
    print_snprintf(buf2, sizeof(buf2), "str=%s,%5s,%-5s,%-s\n", "aaa", "bbb", "ccc", "ddd");
    printf("%s", buf1);
    printf("%s", buf2);
    putchar('\n');
#endif
    /*========================================================================*/
#if 1
          snprintf(buf1, sizeof(buf1), "dec=%d,%u,%d,%u\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "dec=%d,%u,%d,%u\n", 123, 123, -123, -123);
    printf("%s", buf1);
    printf("%s", buf2);
    putchar('\n');

          snprintf(buf1, sizeof(buf1), "dec=%12d,%12u,%12d,%12u\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "dec=%12d,%12u,%12d,%12u\n", 123, 123, -123, -123);
    printf("%s", buf1);
    printf("%s", buf2);
    putchar('\n');

          snprintf(buf1, sizeof(buf1), "dec=%012d,%012u,%012d,%012u\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "dec=%012d,%012u,%012d,%012u\n", 123, 123, -123, -123);
    printf("%s", buf1);
    printf("%s", buf2);
    putchar('\n');

          snprintf(buf1, sizeof(buf1), "dec=%-12d,%-12u,%-12d,%-12u\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "dec=%-12d,%-12u,%-12d,%-12u\n", 123, 123, -123, -123);
    printf("%s", buf1);
    printf("%s", buf2);
    putchar('\n');

          snprintf(buf1, sizeof(buf1), "dec=%3d,%03d,%4d,%04d,%5d,%05d\n", -123, -123, -123, -123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "dec=%3d,%03d,%4d,%04d,%5d,%05d\n", -123, -123, -123, -123, -123, -123);
    printf("%s", buf1);
    printf("%s", buf2);
    putchar('\n');
#endif
    /*========================================================================*/
#if 1
          snprintf(buf1, sizeof(buf1), "hex=%x,%X,%x,%X\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "hex=%x,%X,%x,%X\n", 123, 123, -123, -123);
    printf("%s", buf1);
    printf("%s", buf2);
    putchar('\n');

          snprintf(buf1, sizeof(buf1), "hex=%10x,%10X,%10x,%10X\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "hex=%10x,%10X,%10x,%10X\n", 123, 123, -123, -123);
    printf("%s", buf1);
    printf("%s", buf2);
    putchar('\n');

          snprintf(buf1, sizeof(buf1), "hex=%010x,%010X,%010x,%010X\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "hex=%010x,%010X,%010x,%010X\n", 123, 123, -123, -123);
    printf("%s", buf1);
    printf("%s", buf2);
    putchar('\n');
#endif
    /*========================================================================*/

#if 0
//    #define FORMAT          "char=%-6c,%9c,%%,%-5c\n"
//    #define ARGUMENT        'A', 97, '%'

//    #define FORMAT          "dec=%d,%u,%d,%u\n"
//    #define FORMAT          "dec=%12d,%12u,%12d,%12u\n"
//    #define FORMAT          "dec=%012d,%012u,%012d,%012u\n"
//    #define FORMAT          "dec=%-12d,%-12u,%-12d,%-12u\n"
//    #define ARGUMENT        123, 123, -123, -123


//    #define FORMAT          "dec=%d,%u\n"
//    #define FORMAT          "dec=%0d,%0u\n"
//    #define FORMAT          "dec=%1d,%1u\n"
//    #define FORMAT          "dec=%2d,%2u\n"
//    #define FORMAT          "dec=%3d,%3u\n"
//    #define FORMAT          "dec=%4d,%4u\n"
//    #define FORMAT          "dec=%5d,%5u\n"
//    #define FORMAT          "dec=%6d,%6u\n"
#define FORMAT          "dec=%7d,%7u\n"

//    #define ARGUMENT        1234, 1234
#define ARGUMENT        -1234, -1234


    snprintf(buf1, BUF_LEN, FORMAT, ARGUMENT);
    printf("%s", buf1);
    print_snprintf(buf2, BUF_LEN, FORMAT, ARGUMENT);
    printf("%s", buf2);
    if (memcmp(buf1, buf2, BUF_LEN) == 0) {
        printf(" --> Identical!!!\n");
    } else {
        for (int i = 0; i < BUF_LEN; ++i) {
            printf("0x%X 0x%X", buf1[i], buf2[i]);
            if (buf1[i] != buf2[i]) {
                printf(" --> different!!!");
            }
            printf("\n");
        }
    }
#endif


    return 0;
}

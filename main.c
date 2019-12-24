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

char buf1[BUF_LEN] = "0";
char buf2[BUF_LEN] = "0";


void buf_print_cmp(void)
{
    printf("%s%s", buf1, buf2);

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

    putchar('\n');

    memset(buf1, 'X', BUF_LEN);
    memset(buf2, 'X', BUF_LEN);
}

int main(int argc, char *argv[])
{
    printf("hello lib_print!\n\n");

    memset(buf1, 'X', BUF_LEN);
    memset(buf2, 'X', BUF_LEN);
    printf("buf1=%s\nbuf2=%s\n", buf1, buf2);

    /*========================================================================*/
#if 1
          snprintf(buf1, sizeof(buf1), "char=%c,%3c,%-5c,%12c,%%\n", 'A', 97, 'X', '%');
    print_snprintf(buf2, sizeof(buf2), "char=%c,%3c,%-5c,%12c,%%\n", 'A', 97, 'X', '%');
    buf_print_cmp();
#endif
    /*========================================================================*/
#if 1
          snprintf(buf1, sizeof(buf1), "str=%s,%5s,%-5s,%-2s\n", "aaa", "bbb", "ccc", "dddd");
    print_snprintf(buf2, sizeof(buf2), "str=%s,%5s,%-5s,%-2s\n", "aaa", "bbb", "ccc", "dddd");
    buf_print_cmp();
#endif
    /*========================================================================*/
#if 1
          snprintf(buf1, sizeof(buf1), "dec=%d,%u,%d,%u\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "dec=%d,%u,%d,%u\n", 123, 123, -123, -123);
    buf_print_cmp();

          snprintf(buf1, sizeof(buf1), "dec=%12d,%12u,%12d,%12u\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "dec=%12d,%12u,%12d,%12u\n", 123, 123, -123, -123);
    buf_print_cmp();

          snprintf(buf1, sizeof(buf1), "dec=%012d,%012u,%012d,%012u\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "dec=%012d,%012u,%012d,%012u\n", 123, 123, -123, -123);
    buf_print_cmp();

          snprintf(buf1, sizeof(buf1), "dec=%-12d,%-12u,%-12d,%-12u\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "dec=%-12d,%-12u,%-12d,%-12u\n", 123, 123, -123, -123);
    buf_print_cmp();

          snprintf(buf1, sizeof(buf1), "dec=%3d,%03d,%4d,%04d,%5d,%05d\n", -123, -123, -123, -123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "dec=%3d,%03d,%4d,%04d,%5d,%05d\n", -123, -123, -123, -123, -123, -123);
    buf_print_cmp();
#endif
    /*========================================================================*/
#if 1
          snprintf(buf1, sizeof(buf1), "hex=%x,%X,%x,%X\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "hex=%x,%X,%x,%X\n", 123, 123, -123, -123);
    buf_print_cmp();

          snprintf(buf1, sizeof(buf1), "hex=%10x,%10X,%10x,%10X\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "hex=%10x,%10X,%10x,%10X\n", 123, 123, -123, -123);
    buf_print_cmp();

          snprintf(buf1, sizeof(buf1), "hex=%010x,%010X,%010x,%010X\n", 123, 123, -123, -123);
    print_snprintf(buf2, sizeof(buf2), "hex=%010x,%010X,%010x,%010X\n", 123, 123, -123, -123);
    buf_print_cmp();
#endif
    /*========================================================================*/


    return 0;
}

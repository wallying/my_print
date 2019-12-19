/**
 * file:    main.c
 * author:  wallying@foxmail.com
 * date:    2019-12-19
 **/


#include <stdio.h>
#include "lib_print.h"


/*******************************************************************************
lib_print support format:

    %%      - print % character
    %c      - print character
    %s      - print string
    %d      - print signed decimal integer
    %u      - print unsigned decimal integer
    %x      - print unsigned lower hex integer
    %X      - print unsigned upper hex integer
*******************************************************************************/

char buf[100] = "123456789ABCDEFG";



int main(int argc, char *argv[])
{
    printf("hello lib_print!\n\n");

    /*========================================================================*/
    printf("char=%c,%c,%%,%c\n", 'A', 97, '%');
    print_snprintf(buf, sizeof(buf), "char=%c,%c,%%,%c", 'A', 97, '%');
    puts(buf);
    putchar('\n');

    /*========================================================================*/
    printf("str=\"%s\"\n", "hello, myPrint!");
    print_snprintf(buf, sizeof(buf), "str=\"%s\"", "hello, myPrint!");
    puts(buf);
    putchar('\n');

    /*========================================================================*/
    printf("dec=%d,%u,%d,%u\n", 123, 123, -123, -123);
    print_snprintf(buf, sizeof(buf), "dec=%d,%u,%d,%u", 123, 123, -123, -123);
    puts(buf);
    putchar('\n');

    printf("dec=%12d,%12u,%12d,%12u\n", 123, 123, -123, -123);
    print_snprintf(buf, sizeof(buf), "dec=%12d,%12u,%12d,%12u", 123, 123, -123, -123);
    puts(buf);
    putchar('\n');

    printf("dec=%012d,%012u,%012d,%012u\n", 123, 123, -123, -123);
    print_snprintf(buf, sizeof(buf), "dec=%012d,%012u,%012d,%012u", 123, 123, -123, -123);
    puts(buf);
    putchar('\n');

    /*========================================================================*/
    printf("hex=%x,%X,%x,%X\n", 123, 123, -123, -123);
    print_snprintf(buf, sizeof(buf), "hex=%x,%X,%x,%X", 123, 123, -123, -123);
    puts(buf);
    putchar('\n');

    printf("hex=%10x,%10X,%10x,%10X\n", 123, 123, -123, -123);
    print_snprintf(buf, sizeof(buf), "hex=%10x,%10X,%10x,%10X", 123, 123, -123, -123);
    puts(buf);
    putchar('\n');

    printf("hex=%010x,%010X,%010x,%010X\n", 123, 123, -123, -123);
    print_snprintf(buf, sizeof(buf), "hex=%010x,%010X,%010x,%010X", 123, 123, -123, -123);
    puts(buf);
    putchar('\n');
    /*========================================================================*/

    return 0;
}

/**
 * file:    main.c
 * author:  wallying@foxmail.com
 * date:    2019-12-19
 **/


#include <stdio.h>
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

    support flag:
    1. right justification.
    2. only negative numbers are preceded with a - sign

    supported width:
*******************************************************************************/

char buf[100] = "123456789ABCDEFG";



int main(int argc, char *argv[])
{
    printf("hello lib_print!\n\n");

    /*========================================================================*/
    printf("char=%c,%c,%%,%c\n", 'A', 97, '%');
    print_sprintf(buf, "char=%c,%c,%%,%c", 'A', 97, '%');
    puts(buf);
    putchar('\n');

    /*========================================================================*/
    printf("str=\"%s\"\n", "hello, myPrint!");
    print_sprintf(buf, "str=\"%s\"", "hello, myPrint!");
    puts(buf);
    putchar('\n');

    /*========================================================================*/
    printf("dec=%d,%u,%d,%u\n", 123, 123, -123, -123);
    print_sprintf(buf, "dec=%d,%u,%d,%u", 123, 123, -123, -123);
    puts(buf);
    putchar('\n');

    printf("dec=%12d,%12u,%12d,%12u\n", 123, 123, -123, -123);
    print_sprintf(buf, "dec=%12d,%12u,%12d,%12u", 123, 123, -123, -123);
    puts(buf);
    putchar('\n');

    printf("dec=%012d,%012u,%012d,%012u\n", 123, 123, -123, -123);
    print_sprintf(buf, "dec=%012d,%012u,%012d,%012u", 123, 123, -123, -123);
    puts(buf);
    putchar('\n');

    /*========================================================================*/
    printf("hex=%x,%X,%x,%X\n", 123, 123, -123, -123);
    print_sprintf(buf, "hex=%x,%X,%x,%X", 123, 123, -123, -123);
    puts(buf);
    putchar('\n');

    printf("hex=%10x,%10X,%10x,%10X\n", 123, 123, -123, -123);
    print_sprintf(buf, "hex=%10x,%10X,%10x,%10X", 123, 123, -123, -123);
    puts(buf);
    putchar('\n');

    printf("hex=%010x,%010X,%010x,%010X\n", 123, 123, -123, -123);
    print_sprintf(buf, "hex=%010x,%010X,%010x,%010X", 123, 123, -123, -123);
    puts(buf);
    putchar('\n');
    /*========================================================================*/

    return 0;
}

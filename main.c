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

char buf[50] = "123456789ABCDEFG";



int main(int argc, char *argv[])
{
    printf("hello lib_print!\n\n");

    printf("char=%c,%c\n", 'A', 65);
    print_snprintf(buf, sizeof(buf), "char=%c,%c", 'A', 65);
    puts(buf);
    putchar('\n');


    printf("per=%%,%c,%c\n", '%', 37);
    print_snprintf(buf, sizeof(buf), "per=%%,%c,%c", '%', 37);
    puts(buf);
    putchar('\n');


    printf("str=%s%s%s\n", "hello", " ", "myPrint");
    print_snprintf(buf, sizeof(buf), "str=%s%s%s", "hello", " ", "myPrint");
    puts(buf);
    putchar('\n');


    printf("dec=%d,%u,%d,%u\n", 123, 123, -123, -123);
    print_snprintf(buf, sizeof(buf), "dec=%d,%u,%d,%u", 123, 123, -123, -123);
    puts(buf);
    putchar('\n');


    printf("hex=%x,%X,%x,%X\n", 58, 58, -58, -58);
    print_snprintf(buf, sizeof(buf), "hex=%x,%X,%x,%X\n", 58, 58, -58, -58);
    puts(buf);
    putchar('\n');


    return 0;
}

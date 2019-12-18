#include <stdio.h>
#include "lib_print.h"


char buf[30];


int main(void)
{
    printf("Hello world!\n");

    snprintf(buf, sizeof(buf), "testing %d %d %d", 1, 2, 3);
    puts(buf);

    snprintf(buf, sizeof(buf), "faster %s %ccheaper%c", "and", 34, 34);
    puts(buf);

    snprintf(buf, sizeof(buf), "%x %% %X", 100, 0xFF);
    puts(buf);

    snprintf(buf, sizeof(buf), "char=%c", 'A');
    puts(buf);

    snprintf(buf, sizeof(buf), "%d %u %d %u", 123, 123, -123, -123);
    puts(buf);

    return 0;
}

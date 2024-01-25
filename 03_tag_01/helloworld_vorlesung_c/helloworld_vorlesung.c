#include <stdio.h>
int main()
{
    char string[100] = { 'H','E','L','L','O',' ','W','O','R','L','D','\n','\0'};
    printf("Test: %s", string);
    puts("Hello World from puts");
    return 0;
}

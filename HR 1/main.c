#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int i=4;
    double d=4.0;
    char s[]="HackerRank ";

    int a;
    double b;
    char c_array[100];

    scanf("%d%lf %[^\n]", &a, &b, &c_array);

    printf("%d\n%.1lf\n%s%s", i+a, d+b, s, c_array);

    getch();
    return 0;
}

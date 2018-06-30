#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 101

struct stack
{
    char arr[max];
    int top;
};
struct stack s;

void push(char x)
{
   s.top++;
   s.arr[s.top]=x;
}

void pop()
{
    s.top--;
}

void display()
{
    int i;
    for(i=0; i<=s.top; i++)
        printf("%c ", s.arr[i]);
}

int main()
{
    s.top=-1;
    int len, i;
    char str[max];
    scanf(" %[^\n]s", &str);
    len=strlen(str);
    for(i=0; i<len; i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            push(str[i]);
        if(str[i]==')' && s.arr[s.top]=='(')
            pop();
        if(str[i]=='}' && s.arr[s.top]=='{')
            pop();
        if(str[i]==']' && s.arr[s.top]=='[')
            pop();
    }
    display();
    if(s.top==-1)
        printf("\nYes\n");
    else printf("\nNo\n");
    return 0;
}

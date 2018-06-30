#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 101
struct stack
{
    int arr[max];
    int top;
};
struct stack s;

void push(int x)
{
    s.top++;
    s.arr[s.top]=x;
}

char pop()
{
    char x;
    x=s.arr[s.top];
    s.top--;
    return x;
}
void display()
{
    int i;
    for(i=0; i<=s.top; i++)
        printf("%d ", s.arr[s.top]);
}

int main()
{
    int len, i, x, y, z;
    s.top=-1;
    char str[max];
    printf("Enter the expression.\n");
    scanf(" %[^\n]s", &str);
    len=strlen(str);
    for(i=len-1; i>=0; i--)
    {
        if(str[i]=='+' || str[i]=='-' || str[i]=='/' || str[i]=='*')
        {
            if(str[i]=='+')
            {
                x=pop();
                y=pop();
                z=x+y;
                push(z);
            }
            if(str[i]=='-')
            {
                x=pop();
                y=pop();
                z=x-y;
                push(z);
            }
            if(str[i]=='*')
            {
                x=pop();
                y=pop();
                z=x*y;
                push(z);
            }
            if(str[i]=='/')
            {
                x=pop();
                y=pop();
                z=x/y;
                push(z);
            }
        }
        else push(str[i]-48);
    }
    display();
    printf("\n%d\n", s.arr[s.top]);
    return 0;
}

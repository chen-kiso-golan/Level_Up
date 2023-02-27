#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

//task1
unsigned char fun_binary()
{
    unsigned char a=0b00000001;
    unsigned char b=2;

    a = a << b;
    
    return printf("%d", a);


}

//task2
unsigned char fun1()
{
    unsigned char a=1;
    unsigned char b=a&0b00000001;
    unsigned char c = 0;

    return printf("%d", b==c);
}



int main()
{


    return 0;
}

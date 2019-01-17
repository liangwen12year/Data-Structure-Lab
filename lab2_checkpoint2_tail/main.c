#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
int main(int argc, char* argv[])
{
int s,x,y,m,n;
MY_STRING hMy_string = NULL;
MY_STRING hMy_string_2= NULL;
char* word="apple";
 char* word2="appleyy";

hMy_string=my_string_init_c_string(word);
hMy_string_2=my_string_init_c_string(word2);
x=my_string_get_capacity(hMy_string);
printf("capacity is %d\n",x);
y=my_string_get_size(hMy_string);
printf("size is %d\n",y);
m=my_string_get_capacity(hMy_string_2);
printf("capacity is %d\n",m);
n=my_string_get_size(hMy_string_2);
printf("size is %d\n",n);
s=my_string_compare(hMy_string, hMy_string_2);
printf("%d\n",s);

my_string_destroy(&hMy_string);
 my_string_destroy(&hMy_string_2);
return 0;
}
 



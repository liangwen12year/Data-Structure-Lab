#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
int main(int argc, char* argv[])
{
int s,x,y;
MY_STRING hMy_string = NULL;
hMy_string=my_string_init_default();
x=my_string_get_capacity(hMy_string);
printf("capacity is %d\n",x);
y=my_string_get_size(hMy_string);
printf("size is %d\n",y);

s=my_string_compare("app", "apple");
printf("%d\n",s);

my_string_destroy(&hMy_string);
return 0;
}
 



#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
int main(int argc, char* argv[])
{
int i;
MY_STRING hMy_string = NULL;
char* word="apple";

MY_STRING hMy_string2 = NULL;
char* word2="pie";
hMy_string=my_string_init_c_string(word);
hMy_string2=my_string_init_c_string(word2);
printf("%c\n",*my_string_at(hMy_string, 4));
my_string_push_back(hMy_string,'Y');
for(i=0;i<my_string_get_size(hMy_string);i++){
printf("%c\n",*my_string_at(hMy_string, i));
//printf("%p\n",my_string_at(hMy_string, i));
}
printf("%c\n",*my_string_at(hMy_string, 5));
my_string_pop_back(hMy_string);
my_string_concat(hMy_string, hMy_string2);
printf("%p\n",my_string_at(hMy_string, 0));
for(i=0;i<my_string_get_size(hMy_string);i++){
printf("%c\n",*my_string_at(hMy_string, i));
//printf("%p\n",my_string_at(hMy_string, i));
}

//(char*)my_string_c_str(h.My_string);


my_string_destroy(&hMy_string);
my_string_destroy(&hMy_string2);
return 0;
}



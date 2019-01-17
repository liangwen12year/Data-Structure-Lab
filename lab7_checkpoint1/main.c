#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "generic.h"

int main(int argc, char* argv[])
{

int i;
MY_STRING hMy_string = NULL;
GENERIC_VECTOR array1[30];
int a[30] = { 0 };
hMy_string = my_string_init_default();

FILE* fp = fopen("dictionary.txt", "r");
for(i = 0; i < 30; i++){
	array1[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);
}

while (my_string_extraction(hMy_string, fp)) {
	generic_vector_push_back(array1[my_string_get_size(hMy_string)- 1], hMy_string);
	a[my_string_get_size(hMy_string) - 1]++;
}


for(i = 0; i<30; i++){
	printf("wordlength:%d ,   %d\n", i+1, a[i]);
}
my_string_destroy(&hMy_string);
for (i = 0; i < 30; i++) {
		generic_vector_destroy(&array1[i]);
	}

fclose(fp);


}



#include "my_string.h"
#include <stdlib.h>




struct my_string
{
	int size;
	int capacity;
	char* data;
};

typedef struct my_string My_string;




MY_STRING my_string_init_default(void)
{
	My_string* pMy_string;
	pMy_string = (My_string*)malloc(sizeof(My_string));
	if (pMy_string != NULL)
	{
		pMy_string->size = 0;
		pMy_string->capacity = 7;
		pMy_string->data = (char*)(malloc(sizeof(char)*pMy_string->capacity));
		if (pMy_string->data == NULL)
		{
			free(pMy_string);
			pMy_string = NULL;
		}
	}
	return pMy_string;
}




void my_string_destroy(MY_STRING* phMy_string)
{
	My_string* pMy_string = (My_string*)*phMy_string;
	free(pMy_string->data);
	free(pMy_string);
	*phMy_string = NULL;
}


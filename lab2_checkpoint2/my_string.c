#include "my_string.h"
#include <stdlib.h>
#include <string.h>




struct my_string
{
	int size;
	int capacity;
	char* data;
};

typedef struct my_string My_string;



	MY_STRING my_string_init_c_string(const char* c_string) {
		int i;
		
		My_string* pString;
		pString = malloc(sizeof(My_string));
		if (pString == NULL) {
			free(pString); pString = NULL;
			return pString;
		}
		for (i = 0; c_string[i] != '\0'; i++);
		pString->capacity = (i + 1);
		pString->size = i;
		pString->data = (char*)malloc(sizeof(char)*pString->capacity);
		if (pString->data == NULL) {
			free(pString->data); pString->data = NULL;
			return pString->data;
		}
		for (i = 0; i < pString->capacity; i++) {
			pString->data[i] = c_string[i];
		}
		return pString;
	
	}



void my_string_destroy(MY_STRING* phMy_string)
{
	My_string* pMy_string = (My_string*)*phMy_string;
	free(pMy_string->data);
	free(pMy_string);
	*phMy_string = NULL;
}


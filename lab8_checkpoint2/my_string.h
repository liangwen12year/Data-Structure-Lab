#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <stdio.h>
#include "generic.h"
#include <stdlib.h>

enum status {FAILURE, SUCCESS};
typedef enum status Status;

enum boolean {FALSE, TRUE};
typedef enum boolean Boolean;



struct my_string
{
	int size;
	int capacity;
	char* data;
};

typedef struct my_string My_string;

struct nextpass {
  My_string* key;
  int size;
};
typedef struct nextpass NextPass;

typedef void* Item;
typedef void* MY_STRING;
typedef void* GENERIC_VECTOR;

MY_STRING my_string_init_default(void);

MY_STRING my_string_init_c_string(const char* c_string);

int my_string_get_capacity(MY_STRING hMy_string);


int my_string_get_size(MY_STRING hMy_string);

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string);

Status my_string_extraction(MY_STRING hMy_string, FILE* fp);

Status my_string_insertion(MY_STRING hMy_string, FILE* fp);

Status my_string_push_back(MY_STRING hMy_string, char item);

Status my_string_pop_back(MY_STRING hMy_string);

char* my_string_at(MY_STRING hMy_string, int index);

char* my_string_c_str(MY_STRING hMy_string);

//void my_string_destroy(MY_STRING* phMy_string);

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend);

Boolean my_string_empty(MY_STRING hMy_string);

void my_string_destroy(Item* pItem);

void my_string_assignment(Item* pLeft, Item Right);


// init
GENERIC_VECTOR generic_vector_init_default(
  void(*assignment)(Item* pLeft, Item Right),
  void(*destroy)(Item* ppItem));



// size
// capacity

int generic_vector_size(GENERIC_VECTOR hGeneric_vector);
int generic_vector_capacity(GENERIC_VECTOR hGeneric_vector);

// push_back
Status generic_vector_push_back(GENERIC_VECTOR hGeneric_vector, Item item);

// pop_back
Status generic_vector_pop_back(GENERIC_VECTOR hGeneric_vector);

// empty
Boolean generic_vector_is_empty(GENERIC_VECTOR hGeneric_vector);

// at
Item generic_vector_at(GENERIC_VECTOR hGeneric_vector, int index);


// destroy
void generic_vector_destroy(GENERIC_VECTOR* phGeneric_vector);

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess);

#endif


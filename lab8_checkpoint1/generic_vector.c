#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "generic.h"
GENERIC_VECTOR generic_vector_init_default(void(*assignment)(Item* pLeft, Item Right), void(*destroy)(Item* ppItem)){
	Generic_vector* pGeneric_vector;
	int i;
	pGeneric_vector = (Generic_vector*)malloc(sizeof(Generic_vector));
	if (pGeneric_vector != NULL)
	{
		pGeneric_vector->size = 0;
		pGeneric_vector->capacity = 1;
		pGeneric_vector->data = (Item*)malloc(sizeof(Item)*pGeneric_vector->capacity);
		if(pGeneric_vector->data == NULL)
		{
          		free(pGeneric_vector);
			pGeneric_vector = NULL;
		}
		else
		{
			for(i=0; i < pGeneric_vector->capacity; i++)
			{
				pGeneric_vector->data[i] = NULL;
			}
			pGeneric_vector->assignment = assignment;
			pGeneric_vector->destroy = destroy;	
		}
	}
	return pGeneric_vector;
}

int generic_vector_size(GENERIC_VECTOR hGeneric_vector)
{
	Generic_vector* pGeneric_vector = (Generic_vector*)hGeneric_vector;
	return pGeneric_vector->size;	
}

int generic_vector_capacity(GENERIC_VECTOR hGeneric_vector)
{
	Generic_vector* pGeneric_vector = (Generic_vector*)hGeneric_vector;
	return pGeneric_vector->capacity;
}

Status generic_vector_push_back(GENERIC_VECTOR hGeneric_vector, Item item)
{
	Generic_vector* pGeneric_vector = (Generic_vector*)hGeneric_vector;
	Item* pTemp;
	int i;
	//if there is not enough room,fix it
	if (pGeneric_vector->size >= pGeneric_vector->capacity)
	{
		pTemp = (Item*)malloc(sizeof(Item) * pGeneric_vector->capacity * 2);
		if (pTemp == NULL)
		{
			return FAILURE;
		}		
		else
		{
			for (i=0; i < pGeneric_vector->size; i++)
			{
				pTemp[i] = pGeneric_vector->data[i];			
			}
			pGeneric_vector->capacity *= 2;
			//fill the rest with NULL
			for (; i < pGeneric_vector->capacity; i++)
			{
				pTemp[i] = NULL;			
			}
			free(pGeneric_vector->data);
			pGeneric_vector->data = pTemp;
		}
	}

	pGeneric_vector->assignment(&(pGeneric_vector->data[pGeneric_vector->size]), item);
	if (pGeneric_vector->data[pGeneric_vector->size] == NULL)
	{
		return FAILURE;	
	}
	pGeneric_vector->size++;
	return SUCCESS;
}

Status generic_vector_pop_back(GENERIC_VECTOR hGeneric_vector)
{
	Generic_vector* pGeneric_vector = (Generic_vector*)hGeneric_vector;
	
	if(pGeneric_vector->size <= 0)
	{
		return FAILURE;
	}
	pGeneric_vector->size--;
	if (pGeneric_vector->data[pGeneric_vector->size] != NULL)
	{
		pGeneric_vector->destroy(&(pGeneric_vector->data[pGeneric_vector->size]));
	}
	
	return SUCCESS;
}

Item generic_vector_at(GENERIC_VECTOR hGeneric_vector, int index)
{
	Generic_vector* pGeneric_vector = (Generic_vector*)hGeneric_vector;
	
	if (index < 0 || index >= pGeneric_vector->size)
	{
		return NULL;		
	}
	
	return (pGeneric_vector->data[index]);
}

Boolean generic_vector_is_empty(GENERIC_VECTOR hGeneric_vector)
{
	Generic_vector* pGeneric_vector = (Generic_vector*)hGeneric_vector;
	return pGeneric_vector->size == 0;
}

void generic_vector_destroy(GENERIC_VECTOR* phGeneric_vector)
{
	Generic_vector* pGeneric_vector = (Generic_vector*)*phGeneric_vector;
	int i;
	
	for (i = 0; i < pGeneric_vector->size; i++ )
	{
		if (pGeneric_vector->data[i] != NULL)
		{
			pGeneric_vector->destroy(&(pGeneric_vector->data[i]));		
		}
	}
	free(pGeneric_vector->data);
	free(pGeneric_vector);
	
	*phGeneric_vector = NULL;
	
	return;
}






























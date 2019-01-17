#include "my_string.h"
#include <stdlib.h>
#include "generic.h"



//typedef void* Item;
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



int my_string_get_capacity(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
        //pMy_string = (My_string*)malloc(sizeof(My_string));
	return pMy_string->capacity;

};


int my_string_get_size(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
       // pMy_string = (My_string*)malloc(sizeof(My_string));
	return pMy_string->size;

};



int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {
	int lSize, rSize;
	My_string* pLeft_string = (My_string*)hLeft_string;
	My_string* pRight_string = (My_string*)hRight_string;
	lSize = my_string_get_size(hLeft_string);
	rSize = my_string_get_size(hRight_string);
	int i;
	if (lSize > rSize) {
		for (i = 0; i < pLeft_string->size && i < pRight_string->size; i++) {
			if (pLeft_string->data[i] < pRight_string->data[i]) {
				return -1;
				break;
			}
			else if (pLeft_string->data[i] > pRight_string->data[i]) {
				return 1;
				break;
			}
			//return 1;
		}
		return 1;
	}
	if (lSize == rSize) {
		for (i = 0; i < pLeft_string->size && i < pRight_string->size; i++) {
			if (pLeft_string->data[i] < pRight_string->data[i]) {
				return -1;
				break;
			}
			else if (pLeft_string->data[i] > pRight_string->data[i]) {
				return 1;
				break;
			}
			//return 0;
		}
		return 0;
	}

if (lSize < rSize) {
		for (i = 0; i < pLeft_string->size && i < pRight_string->size; i++) {
			if (pLeft_string->data[i] < pRight_string->data[i]) {
				return -1;
				break;
			}
			else if (pLeft_string->data[i] > pRight_string->data[i]) {
				return 1;
				break;
			}
		//return -1;
		}
		return -1;
	}
 return 0;
}
	

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

	
Status my_string_extraction(MY_STRING hMy_string, FILE* fp){
	int num_of_conversions, i, count =0;
	char c;
	char* tempArray;
	My_string* pMy_string = (My_string*)hMy_string;
	//c=fgetc(fp);
	num_of_conversions=fscanf(fp, " %c", &c);
	if (num_of_conversions==1 && num_of_conversions != EOF)
{	
	     while(c != ' ' && c !=EOF && c != '\n') {
		pMy_string->data[count] = c;
		pMy_string->size = count + 1;
		count++;
		if (pMy_string->capacity <= pMy_string->size)
	{
		tempArray = (char*)malloc(sizeof(char)*2*pMy_string->capacity);
			if(tempArray==NULL){
			  free(tempArray);	
			}
			for(i=0; i<pMy_string->capacity;i++){
				tempArray[i]=pMy_string->data[i];
			}
		free(pMy_string->data);
		pMy_string->data=NULL;
		pMy_string->data=tempArray;
		tempArray = NULL;
		pMy_string->capacity*=2;
	}
		c=fgetc(fp);
}
		ungetc(c,fp);
		return SUCCESS;
}
	return FAILURE;	
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
	My_string* pMy_string=(My_string*)hMy_string;
	int i=0;
	while(i<pMy_string->size){
		fprintf(fp, "%c", pMy_string->data[i]);
		i++;
	}
	return SUCCESS;
}

//getc(fp)

//void my_string_assignment(Item* pLeft, Item Right){
//My_string* pMy_string_left = (My_string*)*pLeft;
//My_string* pMy_string_right = (My_string*)*Right;
//int i;
//const char* temp;

//temp = my_string_c_str(MY_STRING)Right;
//if(pMy_string_left==NULL){
	//pMy_string_left = my_string_init_c_string(temp);		
	//}
	//else{
		//pMy_string_left->size = 0;
		//for(i=0; i < pMy_string_right->size+1; i++){
		//	my_string_push_back(pMy_string_left, pMy_string_right->data[i]);			

		//}
	//}
	//*pLeft = pMy_string_left;

//}
//void my_string_destroy(MY_STRING* phMy_string)
//{
//	My_string* pMy_string = (My_string*)*phMy_string;
//	free(pMy_string->data);
//	free(pMy_string);
//	*phMy_string = NULL;
//}

void my_string_destroy(Item* pItem){

My_string* pMy_string = (My_string*)*pItem;
free(pMy_string->data);
pMy_string->data=NULL;
free(pMy_string);
pMy_string=NULL;
//free(Item);
*pItem=NULL;
return;


}

Status my_string_push_back(MY_STRING hMy_string, char item){
	char* tempArray;
	int i;
	My_string* pMy_string =(My_string*)hMy_string;
	if(pMy_string->size>=pMy_string->capacity){
		tempArray=(char*)malloc(sizeof(char)*2*pMy_string->capacity);
		if (tempArray==NULL){
			free(tempArray);
			return FAILURE;
}
			
		for(i=0;i<pMy_string->size;i++){
			tempArray[i]=pMy_string->data[i];
		}
		free(pMy_string->data);
		pMy_string->data=NULL;
		pMy_string->capacity*=2;
		pMy_string->data=tempArray;
		tempArray=NULL;
		}

		pMy_string->data[pMy_string->size]=item;
		pMy_string->size++;
		return SUCCESS;
		
}

Status my_string_pop_back(MY_STRING hMy_string){
	My_string* pMy_string=(My_string*)hMy_string;
	if(pMy_string->size==0)
		return FAILURE;

	pMy_string->size--;
		return SUCCESS;
		
}


char* my_string_at(MY_STRING hMy_string, int index){
	My_string* pMy_string=(My_string*)hMy_string;
	if(index>=0 && index<pMy_string->size){
	return &pMy_string->data[index];
	}
	return NULL;
}



char* my_string_c_str(MY_STRING hMy_string){
	char* tempArray;
	int i;
	My_string* pMy_string=(My_string*)hMy_string;
	if(pMy_string->size+1 > pMy_string->capacity){
   //resize
	tempArray=(char*)malloc(sizeof(char)*2*pMy_string->capacity);
	if(tempArray==NULL){
		free(tempArray);
		return tempArray;
}
	for(i=0;i<pMy_string->capacity;i++){
		tempArray[i]=pMy_string->data[i];
	}
	free(pMy_string->data);
	pMy_string->data=NULL;
	pMy_string->data=tempArray;
	tempArray=NULL;
	pMy_string->capacity*=2;
}
	pMy_string->data[pMy_string->size]='\0';
	return pMy_string->data;
}


Status my_string_concat(MY_STRING hResult, MY_STRING hAppend){
	My_string* pResult=(My_string*)hResult;
	My_string* pAppend=(My_string*)hAppend;
	char* result = pResult->data;
	char* append = pAppend->data;
	char* tempArray;
	int i, j;
	tempArray = (char*)malloc(sizeof(char)*((pResult->capacity-1)+(pAppend->capacity-1)+1));
	if(tempArray==NULL){
	       free(tempArray);
		return FAILURE;
	}
	for (i=0;i<pResult->size;i++){
		tempArray[i]=result[i];

	}
	for(j=0;i<pResult->size+pAppend->size; j++, i++){
	tempArray[i] = append[j];	
	}
	free(pResult->data);
	pResult->data=tempArray;
	pResult->capacity = (pResult->capacity-1)+(pAppend->capacity-1)+1;
	pResult->size= i;
	return SUCCESS;
}


Boolean my_string_empty(MY_STRING hMy_string){
	My_string* pMy_string=(My_string*)hMy_string;
	if(pMy_string->size==0)
		return TRUE;
	return FALSE;
}






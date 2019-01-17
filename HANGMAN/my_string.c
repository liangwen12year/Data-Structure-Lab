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

/*int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string){
int k,m;

k=strlen(hLeft_string);
m=strlen(hRight_string);
if(k<m)	
    return -1;
if(k=m)
    return 0;
if(k>m)
    return 1;

}
*/



int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string){
	int lSize,rSize,minSize,matches;
	char *lString, *rString;
	lSize=my_string_get_size(hLeft_string);
	rSize=my_string_get_size(hRight_string);
	minSize=(lSize<rSize)?lSize:rSize;
	lString=((struct My_string*) hLeft_string)->c_string;
	rString=((struct My_string*) hRight_string)->c_string;
	for(matches=0;matches<minSize;matches++){
	 if(*lString!=*rString){
		break;
	     }else{
		   lString++;
		   rString++;
	     }
	    if(matches == minSize)
			if(lSize == rSize)
				return 0;
			else if(lSize<rSize)
				return -matches;
			else 
				return matches;

	   else
		        return *lString<*rString ?-1 :1;

}


MY_STRING my_string_init_c_string(const char* c_string){
  My_string* pc_string;
  pc_string = (My_string*)malloc(sizeof(My_string));
  int length;
  
  length = strlen(c_string);
  
  pc_string->size = length;
  pc_string->capacity = length+1;
  pc_string->data = (char*)(malloc(sizeof(char)*pc_string->capacity));  
 /* for(i=0;i<pc_string->size;i++){
      pc_string->data[i] = *c_string; */
   pc_string->data[pc_string->capacity]=*c_string;

	if((pc_string->data)==NULL)
	{
             free(pc_string);
	     pc_string=NULL;
	}
 
  
  return pc_string;
 }



void my_string_destroy(MY_STRING* phMy_string)
{
	My_string* pMy_string = (My_string*)*phMy_string;
	free(pMy_string->data);
	free(pMy_string);
	*phMy_string = NULL;
}





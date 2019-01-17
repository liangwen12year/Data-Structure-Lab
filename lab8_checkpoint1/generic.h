#ifndef GENERIC_H
#define GENERIC_H


typedef struct generic_vector Generic_vector;
typedef void* Item;
struct generic_vector{
   void(*assignment)(Item* pLeft, Item Right);
   void(*destroy)(Item* ppItem);//
   int size; // the number of elements in the vector
   int capacity; // the number of elements the vector can hold
   Item* data;
};

  

#endif

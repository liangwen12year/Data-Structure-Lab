#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
 int i,j;
 int *p;
 p = (int*) malloc(sizeof(int)*100);
 printf("Hello world! I have created a dynamic array of 100 integers!\n");
 int a[20][30];
 for(i=0;i<20;i++)
	{
    for(j=0;j<30;j++)
     {
        a[i][j]=j+i;
        printf("%2d ",a[i][j]);}
	printf("\n");
  	}
 free(p);
 return 0;
}




 



#include <iostream>
#include <stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct
{
    int *A;
    int size;
    int length = 0;
}Array_Dynamic;


typedef struct
{
    int A[20];
    int length = 0;
}Array_Static;



void DynamicArray_Increase_Array_Size(Array_Dynamic * arr,int newSize){
	int *newArray = new int[newSize]; // or malloc and casting in C

	for(int i = 0; i<arr->length;i++){
		newArray[i] = arr->A[i];
	}
	delete[] arr->A; //or free in C
	arr->A = newArray;
	newArray = nullptr;
	arr->size = newSize;
}



void StaticArray_Display(Array_Static a){
    printf("[");
    for(int i =0; i< a.length;i++){
        printf("%d",a.A[i]);
        if(i<a.length-1)
            printf(",");
    }
    printf("] \n");
}

void DynamicArray_Display(Array_Dynamic a){
    printf("[");
    for(int i =0; i< a.length;i++){
        printf("%d",a.A[i]);
        if(i<a.length-1)
            printf(",");
    }
    printf("] \n");

}

/*
 * To-Do Linear Search and Binary Search :)
 */

void StaticArray_Append(Array_Static * arr,int x)
{
    arr->A[arr->length++] = x;
}


void StaticArray_Insert(Array_Static * arr,int x,int index)
{
	if (index >= 0 && index < arr->length)
	{
	printf("length array %d \n",arr->length);

    for(int i = arr->length;i>index;i--){
        arr->A[i] = arr->A[i-1];
    }

    arr->A[index] = x;
    arr->length++;

	}

	else{
		printf("Cannot add this element in the Array \n");
	}

}

void StaticArray_Delete(Array_Static * arr,int index){

	if(index >= 0 && index < arr->length){
		// {1,2,3,4,5,6,7,8,9,10}
       for(int i = index; i<arr->length-1; i++){
    	  arr->A[i] = arr->A[i+1];
       }
       arr->length--;
	}
}


/*
 * To-Do 28/12 Inshaallah
 * Linear Search (Easy no need just two notes took into-consideration) for the improvements
 * Binary Search (Array or List shall be sorted)
 */



int Binary_Search(Array_Static * arr,int element ){

	// [1,2,3,4,5]  high = 1       low = 0 0+1/2

	int low = 0; // 0
	int high = (arr->length)-1; //4
	int mid = (high+low)/2; //2


	for(int i = mid; low<=high ; i = (high+low)/2){

		if(element == arr->A[i]){
			return i;
		}
		else if (element < arr->A[i]){
			high = i-1;
		}
		else if (element > arr->A[i]){
			low = i+1;
		}

	}
	return -1;
}

/*
int main() {

    Array_Static  StaticArray;
    Array_Dynamic DynamicArray;

    int size = 20;
    DynamicArray.A = (int *)malloc(size*sizeof(int));
    DynamicArray.size = size;

    for (int i = 0; i<5;i++) {

        DynamicArray.A[i] = i;
        DynamicArray.length++;
        StaticArray.A[i] = i+2;
        StaticArray.length++;

    }



    // Dynamic Array
    printf("Dynamic Array Result \n");
    DynamicArray_Display(DynamicArray);
    printf("Dynamic Array length %d\n",DynamicArray.length);

    DynamicArray_Increase_Array_Size(&DynamicArray,30);
    printf("Dynamic Array Result after increasing size \n");
    DynamicArray_Display(DynamicArray);
    printf("Dynamic Array length after increasing size %d\n",DynamicArray.size);


    printf("Finshing Dynamic Array Calculations \n");
    printf("--------------------------------------------------------- \n");




    //Static Array
    printf("Static Array Result \n");
    StaticArray_Display(StaticArray);
    printf("Static Array length %d\n",StaticArray.length);



    //Appending
    StaticArray_Append(&StaticArray,15);
    printf("Static Array Result after appending \n");
    StaticArray_Display(StaticArray);
    printf("Static Array length after appending %d\n",StaticArray.length);


    // Inserting
    StaticArray_Insert(&StaticArray,17,3);
    printf("Static Array Result after inserting \n");
    StaticArray_Display(StaticArray);
    printf("Static Array length after inserting %d\n",StaticArray.length);


    // Deleting
    StaticArray_Delete(&StaticArray,2);
    printf("Static Array Result after deleting \n");
    StaticArray_Display(StaticArray);
    printf("Static Array length after deleting %d\n",StaticArray.length);


    // Binary Search
     Array_Static  StaticArray_Two = {{1,2,3,4,5},5};

     int x = Binary_Search(&StaticArray_Two,2);

     printf("Static Array Two after Binary Search \n");
     StaticArray_Display(StaticArray);
     printf("the result of the binary search %d",x);

    return 0;
}
*/

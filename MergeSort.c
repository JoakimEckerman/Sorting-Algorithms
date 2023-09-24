#include <stdio.h>
#include <stdlib.h>

void msort(int*, int);
void merge(int*, int, int*, int);

//arbitrary test array
int arrays[] = {10, 9, 8, 7, 11, 31, 12, 6, 5, 4, 3, 2, 1};

int main(){
  //determine size of array
  int size = sizeof(arrays)/sizeof(arrays[0]);

  //print conents of array before sort 
  printf("Array prior to sort: \n");
  for(int i = 0; i < size; i++){
    printf("Array element %d has value of %d\n", i, arrays[i]);
  }
  printf("\n");
  //sort array using array and size 
  msort(arrays, size);

  //print contents of sorted array
  printf("Sorted array contents: \n");
  for(int i = 0; i < size; i++) {
    printf("Arrays element %d has value of %d\n", i, arrays[i]);
  }
  return 0;
}

//merge left array and right array using left and right pointers and sizes
void merge(int* lPtr, int lSize, int* rPtr, int rSize) {

  //create left array on heap
  int *left_array;
  left_array = (int *)malloc(lSize * sizeof(int));

  //create right array on heap 
  int *right_array;
  right_array = (int *)malloc(rSize * sizeof(int));

  //copy elements of left array by using pointer and placing into left array (heap)
  for (int i = 0; i < lSize; i++) {
    left_array[i] = *(lPtr + i);
  }

  //copy elements of right array by using pointer and placing into right array (heap)
  for (int i = 0; i < rSize; i++) {
    right_array[i] = *(rPtr + i);
  }

  //initialize indicies
  int leftIndex = 0;
  int rightIndex = 0;
  //point to lPtr initial index
  int* mergeIndex = lPtr; 

  //iterate through arrays by using their index and size 
  while (leftIndex < lSize && rightIndex < rSize) { 
    //if left array element is less than or equal to right
    if (left_array[leftIndex] <= right_array[rightIndex]) { 
      //merge index pointer takes left array value at left index and increase left index
      *mergeIndex = left_array[leftIndex];
      leftIndex++;
    } else {
      //merge index pointer takes right array value at right index and increase right index
      *mergeIndex = right_array[rightIndex];
      rightIndex++;
    }
    //increase pointer 
    mergeIndex++;
  }

  //remaining elements of left and right
  while (leftIndex < lSize) {
    *mergeIndex = left_array[leftIndex];
    leftIndex++;
    mergeIndex++;
  }

  while (rightIndex < rSize) {
    *mergeIndex = right_array[rightIndex];
    rightIndex++;
    mergeIndex++;
  }
}


void msort(int *a, int n) {
	//will return recurssive call when n <= 1... when elements are in their own array
  if (n <= 1)
    return;

	//determine if size is even
  int isEven = n % 2 == 0;
	//number of left elements using size 
  int lSize = n / 2;
	//number of right elements useing size, if even /2 and if odd +1
  int rSize = isEven ? n / 2 : n / 2 + 1;
	//left pointer starts at beginning of a
  int* lPtr = a;
	//right pointer starts at a[0] + number of left elements 
  int* rPtr = a + lSize;

	//sort left and right using pointer and number of elements 
  msort(lPtr, lSize);
  msort(rPtr, rSize);   
  //create left array on heap
  int *left_array;
  left_array = (int *)malloc(lSize * sizeof(int));

  //create right array on heap 
  int *right_array;
  right_array = (int *)malloc(rSize * sizeof(int));

  //copy elements of left array by using pointer and placing into left array (heap)
  for (int i = 0; i < lSize; i++) {
    left_array[i] = *(lPtr + i);
  }

  //copy elements of right array by using pointer and placing into right array (heap)
  for (int i = 0; i < rSize; i++) {
    right_array[i] = *(rPtr + i);
  }

  //initialize indicies
  int leftIndex = 0;
  int rightIndex = 0;
  //point to lPtr initial index
  int* mergeIndex = lPtr; 

  //iterate through arrays by using their index and size 
  while (leftIndex < lSize && rightIndex < rSize) { 
    //if left array element is less than or equal to right
    if (left_array[leftIndex] <= right_array[rightIndex]) { 
      //merge index pointer takes left array value at left index and increase left index
      *mergeIndex = left_array[leftIndex];
      leftIndex++;
    } else {
      //merge index pointer takes right array value at right index and increase right index
      *mergeIndex = right_array[rightIndex];
      rightIndex++;
    }
    //increase pointer 
    mergeIndex++;
  }

  //remaining elements of left and right
  while (leftIndex < lSize) {
    *mergeIndex = left_array[leftIndex];
    leftIndex++;
    mergeIndex++;
  }

  while (rightIndex < rSize) {
    *mergeIndex = right_array[rightIndex];
    rightIndex++;
    mergeIndex++;
  }
}
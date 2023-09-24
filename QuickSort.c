#include <stdio.h>

void swap(int*, int*);
void printArray(int[], int);
int partition(int*, int);
void qSort2(int*, int);


// main function
int main() {
    int sampleData[] = {10, 12, 15, 20, 9, 99, 16};

    int n = sizeof(sampleData) / sizeof(sampleData[0]);

    printf("Unsorted Array\n");
    printArray(sampleData, n);
  
        qSort2(sampleData, n);
    
    printf("Sorted array in ascending order: \n");
    printArray(sampleData, n);
  
    return 0;
}

// function to swap elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// function to print array elements
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

//function to find the partition position
int partition(int* array, int n) {
    //work in terms of n
    //use pointer for array
    int* rightElement = array + n - 1;
    int* leftElement = array;

    // select the rightmost element as pivot
    int pivot = *rightElement;
    //use i to track iteration through array
    int i = 0;

    //iterate through array
    for (int j = 0; j < n; j++) {
        //compare element to pivot 
        if (array[j] < pivot){  
            //swap element at ith and jth position
            swap(leftElement + i, (leftElement + j)); 
            i++; // increment index of smaller element 
          //printArray(array, n); test
        }
    }
    //swap last element with ith element 
    swap(leftElement + i, rightElement);

    //printArray(array, n); test

    return i + 1;
}


void qSort2(int *array, int n) {
    if (n <= 1) {
        return;
    }

    //printArray(array, n); test
  
    int pivot = partition(array, n);

    //printArray(array, n); test

    qSort2(array, pivot - 1); 
    qSort2(array + pivot, n - pivot); 
}
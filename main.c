#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person{
  char name[50];
  int age;
};

double numbers[] = {645.41,37.59,76.41,5.31,-34.23,1.11,1.10,23.46,635.47,-876.32,467.83,62.25};
struct Person people[] = {{"Hal",20},{"Susann",31},{"Dwight",19},{"Kassandra",21},{"Lawrence",25},{"Cindy",22},{"Cory",27},{"Mac",19},{"Romana",27},{"Doretha",32},{"Danna",20},{"Zara",23},{"Rosalyn",26},{"Risa",24},{"Benny",28},{"Juan",33},{"Natalie",25}};

int compI (const void* x, const void* y){
  if(*(int*)x < *(int*)y) return -1;
  if(*(int*)x > *(int*)y) return 1;
  return 0;
}

int compS (const void* x, const void* y){
  return (strcmp(*(char**)x,*(char**)y));
}

int compD (const void* x, const void* y){
  if(*(double*)x < *(double*)y) return -1;
  if(*(double*)x > *(double*)y) return 1;
  return 0;
}

int compPN (const void* x, const void* y){
  struct Person *s1 = (struct Person *)x;
  struct Person *s2 = (struct Person *)y;
  return strcmp(s1->name,s2->name);
} 

int compPA (const void* x, const void* y){
  struct Person *s1 = (struct Person *)x;
  struct Person *s2 = (struct Person *)y;
  if(s1->age == s2->age) return strcmp(s1->name,s2->name);
  if(s1->age < s2->age) return 1;
  return -1;
} 

void printArray(int a[],int n){
  printf("[");
  
  for(int i = 0; i < n; i++){
    if(i != n-1){

      printf("%d, ", a[i]);

    }else{

      printf("%d", a[i]);

    }
  }

  printf("]\n");
}

void printArrayD(double a[],int n){
  printf("[");
  
  for(int i = 0; i < n; i++){
    if(i != n-1){

      printf("%0.2f, ", a[i]);

    }else{

      printf("%0.2f", a[i]);

    }
  }

  printf("]\n");
}

void printArrayS(char *a[],int n){
  printf("[");
  
  for(int i = 0; i < n; i++){
    if(i != n-1){

      printf("%s, ", a[i]);

    }else{

      printf("%s", a[i]);

    }
  }

  printf("]\n");
}

void printPerson(struct Person people[],int n){
  printf("[");
  
  for(int i = 0; i < n; i++){
    printf("{");
    printf("%s, ", people[i].name);
    printf("%d ", people[i].age);
    printf("}");
    if(i != n-1) printf(", ");
  }

  printf("]\n");
}

int main(void) {

  printf("Before:\nnumbers = ");
  printArrayD(numbers, sizeof(numbers)/sizeof(double));

  qsort(numbers, sizeof(numbers)/sizeof(double), sizeof(double), compD);

  printf("\nAfter:\nnumbers = ");
  printArrayD(numbers, sizeof(numbers)/sizeof(double));

  printf("\nBefore:\npeople = ");
  printPerson(people, sizeof(people)/sizeof(*people));

  qsort(people, sizeof(people)/sizeof(*people), sizeof(*people), compPN);

  printf("\nAfter:\npeople = ");
  printPerson(people, sizeof(people)/sizeof(*people));

  printf("\nBefore:\npeople = ");
  printPerson(people, sizeof(people)/sizeof(*people));

  qsort(people, sizeof(people)/sizeof(*people), sizeof(*people), compPA);

  printf("\nAfter:\npeople = ");
  printPerson(people, sizeof(people)/sizeof(*people));
  
  return 0;
}
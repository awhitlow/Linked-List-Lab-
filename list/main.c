#include <stdio.h>

#include "list.h"

int main() { 
  //Create list pointer
  list_t *ptr; 
  int length, index;
  bool inOrOut;
  elem returnedElem;
  printf("\nTests for linked list implementation:\n");
    
  //Allocate space for list 
  ptr = list_alloc();
  
  //Add values to the front of the list
  list_add_to_front(ptr, 4);
  list_add_to_front(ptr, 2);
  
  //Add value to the back of the list
  list_add_to_back(ptr, 3);
  
  //Add value at certain index
  list_add_at_index(ptr, 5, 2);
  
  //Print the list
  list_print(ptr);
  
  //Get the length of the list
  length = list_length(ptr);
  printf("\nLength of list is %d ", length);
    
  //Check if certain value is in the list
  printf("\nIs 4 is in the list?: ");
  inOrOut = list_is_in(ptr, 4);
  if (inOrOut == 1){
      printf("True");
  }
  else{
      printf("False");
  }
  
  printf("\nIs 23 is in the list?: ");
  inOrOut = list_is_in(ptr, 23);
  if (inOrOut == 1){
      printf("True\n");
  }
  else{
      printf("False\n");
  } 
  
  //Get element at certain index
  returnedElem = list_get_elem_at(ptr, 2);
  printf("Element at index 2: %d\n", returnedElem);
  
  //Get index of certain value
  index = list_get_index_of(ptr, 4);
  printf("Index of element 4: %d\n", index);
  
  //Remove element at certain index
  returnedElem = list_remove_at_index(ptr, 2);
  printf("Element removed at index 2: %d\n", returnedElem);
  printf("New list is: ");
  list_print(ptr);
  
  //Remove an element from the back of the list
  returnedElem = list_remove_from_back(ptr);
  printf("\nElement removed at back: %d\n", returnedElem);
  printf("New list is: ");
  list_print(ptr);
   
  //Remove an element from the fron  of the list
  returnedElem = list_remove_from_front(ptr);
  printf("\nElement removed at front: %d\n", returnedElem);
  printf("New list is: ");
  list_print(ptr);
  
  //Free space taken up by list
  list_free(ptr);
    
  printf("Test after makefile");
  
  return 0;
}
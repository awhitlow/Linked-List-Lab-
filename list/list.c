// list/list.c
// 
// Implementation for linked list.
//
// <Alexandria Whitlow>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

//Allocate space for list
list_t *list_alloc() { 
    list_t* newPointer = (list_t*) malloc(sizeof(list_t));
    newPointer->head = NULL;                                       
    return newPointer; 
}

//Deallocate space from linked list                                         
void list_free(list_t *l) {
    free(l);
}

void list_print(list_t *l) {
    //Instantiate new node pointer
    node_t *current = l->head;
    
    //Iterate through the linked list, printing the information within each node
    while(current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
    return;
}
                                          
int list_length(list_t *l) {
    node_t *current = l->head;
    int count = 0;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count; 
}

void list_add_to_back(list_t *l, elem value){ 
   node_t *current = l->head; 
   node_t *backNode = (node_t*) malloc(sizeof(node_t));
   backNode->value = value;
    
    if (current == NULL){
        backNode = l->head;
    }
    
    while (current->next != NULL){
        current = current -> next;
    }
    
    current->next = backNode;
    
  return;  
}

void list_add_to_front(list_t *l, elem value) { 
   node_t *frontNode = (node_t*) malloc(sizeof(node_t));
   frontNode->value = value;
   frontNode->next = l->head;
   l->head = frontNode;
   return;
}
                                          
void list_add_at_index(list_t *l, elem value, int index) {
    node_t *current = l->head; 
    node_t *someNode = (node_t*) malloc(sizeof(node_t));
    node_t *temp = l->head;
    someNode->value = value; 
    int i =0;
    for(i; i < index; i++){
        current = current->next;
    }
    int j = 0;
    for (j; j < index - 1; j++){
            temp = temp->next;
    }
    
    temp->next = someNode;
    someNode->next = current;
    //current->next = someNode;
    return;
}


elem list_remove_from_back(list_t *l) {
    elem nodeValue;
    int length = list_length(l);
    node_t *current = l->head;
    node_t *temp = l->head;
    
    while (current->next != NULL){
        current = current -> next;
    }
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    nodeValue = current->value;
    free(current);
    temp->next = NULL;
    return nodeValue; 
}
                                          
elem list_remove_from_front(list_t *l) { 
    elem nodeValue;
    node_t *temp = l->head;
    nodeValue = temp->value;
    l->head = temp->next;
    free(temp);
    return nodeValue; 
}
                                          
elem list_remove_at_index(list_t *l, int index) { 
    elem nodeValue;
    node_t *current = l->head;
    node_t *temp = l->head;
    int i =0;
    for(i; i < index; i++){
        current = current->next;
    }
    int j =0;
    for (j; j < index - 1; j++){
        temp = temp->next;
    }
    nodeValue = current->value;
    temp->next = current->next;
    free(current);
    
    return nodeValue; 
}

bool list_is_in(list_t *l, elem value) {
    node_t *current = l->head;
    while(current != NULL){
        if(current->value == value){
            return true;
        }
        else{
            current = current->next;
        }
    }
    return false;
}
elem list_get_elem_at(list_t *l, int index) { 
    node_t *current = l->head;
    int i = 0;
    for(i; i <index; i++){
        current = current->next;
    }
    return current->value; 
}
                                          
int list_get_index_of(list_t *l, elem value) { 
    node_t *current = l->head;
    int index = 0;
    while(current != NULL){
        if(current->value == value){
            return index;
        }
        else{
            current = current-> next;
            index++;
        }
    }
   return -1; 
}
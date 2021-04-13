
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   char* nome;
   struct node *next;
};


struct node *head = NULL;
struct node *current = NULL;


/* Add string to list*/
void addList(char* );
/* false if list contains an element*/
bool isEmpty();
/*clears list*/
void clearList();
/*deletes and returns element form head of list*/
struct node* pop();
/*return lenght*/
int Listlength();




//insert link at the first location
void addList(char* nome) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));	
   link->nome= nome;	
   //point it to old first node
   link->next = head;	
   //point first to new first node
   head = link;
}



//delete first item
struct node* pop() {

   //save reference to first link
   struct node *tempLink = head;
	
   //mark next to first link as first 
   head = head->next;
	
   //return the deleted link
   return tempLink;
}



void clearList()
{   
      head = NULL;
      current = NULL;
}


//is list empty
bool isEmpty() {
   return head == NULL;
}



int Listlength() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}











/*
//Return first element on list
struct node* pop() {
   //start from the first link
   struct node* current = head;
   deleteFirst();
   return current;
}
*/
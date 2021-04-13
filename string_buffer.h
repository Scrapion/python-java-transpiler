#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// DOUBLE LINKED LIST
struct block {
   char* stringa;   
   struct block *next;
   struct block *prec;
};

struct block *top = NULL;
struct block *first= NULL;

/*inserts string on top of buffer*/
void insetrOnTop(char*);
/*inserts string on bottom of buffer*/
void insertBuffer(char*);
/*prints buffer on screen*/
void printBuffer() ;
/*prints buffer on passed file*/
void printBufferOnFile(FILE *);
/*clears buffer*/
void clearBuffer();

/**
 * @brief  inserts string on top of buffer
 * @note   
 * @param  stringa: Element to insert
 * @retval None
 */
void insetrOnTop(char* stringa) {
   // NEW ELEMENT
   struct block *link = (struct block*) malloc(sizeof(struct block));   
   link->stringa= stringa;	

   //SET KLD FIRST PRECEDENT
   first->prec =link; 
   //SET NEW FIRST SUCSESSOR
   link->next = first;
   link->prec = NULL;
   //UPDATE FIRST
   first=link;
}

/**
 * @brief  inserts string on bottom of buffer
 * @note   
 * @param  stringa: Element to add
 * @retval None
 */
void insertBuffer(char* stringa) {
   // NEW ELEMENT
   struct block *link = (struct block*) malloc(sizeof(struct block));   
   link->stringa= stringa;	
   
   //IF FIRST EXIST POINT CURRENT TOP IN LIST TO NEW ELEMENT
   if(first!=NULL){ 
    top->next = link;
    top->prec = NULL;
   }
   //POINT NEW ELEMENT TO PRECEDENT ELEMENT
   link->prec = top;
   link->next= NULL;	
   //SET NEW ELEMENT AT CURRENT TOP OF LIST
   top = link;

   //IF LIST HAS NO FIRST ELEMENT SET FIRST
   if(first==NULL){
    link->next=NULL; 
    first=link;
   }
}

/**
 * @brief  clears buffer
 * @note   
 * @retval None
 */
void clearBuffer(){ 
    //get start
    struct block *ptr = top;  
    // chack if null
    if(ptr != NULL){
        // change list start,first to NULL
        top = NULL;
        first= NULL;
    }    
}
/**
 * @brief  prints buffer on passed file
 * @note   
 * @param  *f: File reference
 * @retval None
 */
void printBufferOnFile(FILE *f) {
   //GET FIST ELEENT 
   struct block *ptr = first;   
   
    //PRINT FROM FIRST TO LAST
    while(ptr != NULL && ptr->next != NULL) 
    {       
      fprintf(f,"%s",ptr->stringa);      
      ptr = ptr->next;      
    }	
    fprintf(f,"%s",ptr->stringa); 
   
}
/**
 * @brief  prints buffer on screen
 * @note   
 * @retval None
 */
void printBuffer() {
   //GET FIST ELEENT 
   struct block *ptr = first;   
   
    //PRINT FROM FIRST TO LAST
    while(ptr != NULL && ptr->next != NULL) 
    {       
      printf("%s",ptr->stringa);      
      ptr = ptr->next;      
    }	
    printf("%s",ptr->stringa);  
   
}
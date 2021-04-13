

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define LBUFFER_SIZE 2048

char* newList (char*);
char* appendList (char*,char*);
char* clList(char* );
char* countList(char* );
char* extendList(char*,char*);
char* indexList(char*,char*);
char* insertList(char*,char*,char*);
char* popList(char* );
char* popElList(char*,char*);
char* removeList(char*,char*);
char* copyList(char* );
char* reverseList(char* );
char* sortList(char* );
/**
 * @brief  Creates java string for list declaration
 * @note   
 * @param  name: List name
 * @retval string of Java List Decleration
 */
char* newList (char* name)
{
    char buffer[LBUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "ArrayList  %s = new ArrayList() " ,name );
  
    char* str = buffer;
    
    return str;
}

/**
 * @brief  Creates java string for adding element to list
 * @note   
 * @param  name:  List name
 * @param  element: Element to add to list
 * @retval string of Java List add
 */
char* appendList (char* name,char* element)
{
    char buffer[LBUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "%s.add(%s) " ,name,element );
  
    char* str = buffer;
    
    return str;
}
/**
 * @brief  Creates java string for list clearing function
 * @note   
 * @param  name: List name
 * @retval string of Java List clear function
 */
char* clList (char* name)
{
    char buffer[LBUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "%s.clear() " ,name );
  
    char* str = buffer;
    
    return str;
}

/**
 * @brief  Creates java string for  list size function
 * @note   
 * @param  name:  List name
 * @retval string of Java List size function
 */
char* countList (char* name)
{
    char buffer[LBUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "%s.size()" ,name );
  
    char* str = buffer;
    
    return str;
}

/**
 * @brief  Creates java string for  list addAll function
 * @note   
 * @param  name: List name
 * @param  element: Second List name
 * @retval string of Java List addAll function
 */
char* extendList (char* name,char* element)
{
    char buffer[LBUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "%s.addAll(%s) " ,name,element );
  
    char* str = buffer;
    
    return str;
}


/**
 * @brief   Creates java string for  list indexOf function
 * @note   
 * @param  name: List name
 * @param  element: list element
 * @retval string of Java List indexOf function
 */
char* indexList (char* name,char* element)
{
    char buffer[LBUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "%s.indexOf(%s) " ,name,element );
  
    char* str = buffer;
    
    return str;
}

/**
 * @brief  Creates java string for  list add to index function
 * @note   
 * @param  name: List name
 * @param  element1: Index 
 * @param  element2: Element to add
 * @retval string of Java List add to index function
 */
char* insertList(char* name,char* element1,char* element2)
{
    char buffer[LBUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "%s.add(%s,%s) " ,name,element1,element2 );
  
    char* str = buffer;
    
    return str;
}

/**
 * @brief  string implementation of python opp function to .get java function
 * @note   
 * @param  name: List name
 * @retval String
 */
char* popList (char* name)
{
    char buffer[LBUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "popList(%s,(%s.size()-1))" ,name,name);
  
    char* str = buffer;
    
    return str;
}
/**
 * @brief  String implementation of get element at index in java
 * @note   
 * @param  name: List name
 * @param  element: index
 * @retval string
 */
char* popElList (char* name,char* element)
{
    char buffer[LBUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "popList(%s,%s) " ,name,element );
  
    char* str = buffer;
    
    return str;
}

/**
 * @brief  String of remove function in java
 * @note   
 * @param  name: List name
 * @param  element: index
 * @retval String
 */
char* removeList(char* name,char* element)
{
    char buffer[LBUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "%s.remove(%s) " ,name,element );
  
    char* str = buffer;
    
    return str;
}

/**
 * @brief  Metodo per copiare una lista
 * @note   
 * @param  name: Stringa nome di funzione
 * @retvalstring, java method
 */
char* copyList(char* name)
{
    char buffer[LBUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "copyList(%s) " ,name );
  
    char* str = buffer;
    
    return str;
}
/**
 * @brief  implementa il metodo reverse da collections
 * @note   uses java Collection library 
 * @param  name: String list name
 * @retval string, java method
 */
char* reverseList(char* name)
{
    char buffer[LBUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "Collections.reverse(%s) " ,name );
  
    char* str = buffer;
    
    return str;
}
/**
 * @brief  Implement method for sorting lists
 * @note   uses java Collection library 
 * @param  name: String list name
 * @retval string, java method
 */
char* sortList(char* name)
{
    char buffer[LBUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "Collections.sort(%s)" ,name );
  
    char* str = buffer;
    
    return str;
}



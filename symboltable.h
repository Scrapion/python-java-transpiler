#define NHASH 999997

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct symbol {
    char *name;
    char *tipo;
    int scope;
    struct ref *reflist;
};

struct ref {
    struct ref *next;    
    int lineno;
};

struct symbol symtab[NHASH];

/*cheks for existence of element otherwise adds element on symTable and returns element*/

struct symbol *lookup(char*, char*,int);
/*adds reference to reftable, cheks avaiability of memory. uses lookup function*/
void addref(int, char*, char*,int);
/*Translates sym to hash*/
static unsigned symhash(char *sym);
/*returns the type of the associated element having on input element name*/
static char* getType(char*);
/*cheks existance of element having on input element name*/
static int exist(char*);
/*modifyes the type of an element if it exists on the list*/
static int  modtype(char*,char*,int);
/*returns the scope of an element if it exists*/
static int getScope(char*);
/*modifies the scope of an element if it exists*/
static int  setScope(char*,int);


/**
 * @brief  Translates sym to hash
 * @note   
 * @param  *sym: String, symbol name
 * @retval hashs
 */
static unsigned symhash(char *sym){
    unsigned int hash = 0;
    unsigned c;

    while(c= *sym++) hash = hash*9 ^ c;

    return hash;
}
/**
 * @brief  cheks for existence of element otherwise adds element on symTable and returns element
 * @note   
 * @param  sym: Symble
 * @param  tipo: Element Type
 * @param  scope: Scope Identification Number
 * @retval pointer to symble table entry
 */
struct symbol *lookup(char* sym, char* tipo,int scope){
    struct symbol *sp = &symtab[symhash(sym)%NHASH];
    int scount = NHASH;

    while(--scount >= 0) {
        if(sp->name && !strcmp(sp->name, sym)) return sp;

        if(!sp->name){
            sp->name = strdup(sym);
            sp->tipo = strdup(tipo);
            sp->scope = scope;
            sp->reflist = 0;
            return sp;
        }

        if (++sp >= symtab+NHASH) sp = symtab;
    }

    fputs("symbol table overflow\n", stderr);
    abort();
}

/**
 * @brief  adds reference to reftable, cheks avaiability of memory. uses lookup function
 * @note   
 * @param  lineno: Line number of entry
 * @param  *word: Element name
 * @param  *tipo: Element Type
 * @param  scope: Scope Identification Number
 * @retval None
 */
void addref(int lineno,  char *word, char *tipo,int scope){
    
    struct ref *r;
    struct symbol *sp = lookup(word, tipo,scope);
    
    if (sp->reflist &&
        sp->reflist->lineno == lineno ) return;
    
    r = malloc(sizeof(struct ref));
    
    if (!r) {
        fputs("out of space\n", stderr); abort();
    }
    r->next = sp->reflist;
    r->lineno = lineno;       
    sp->reflist = r;
}




/**
 * @brief  returns the type of the associated element having on input element name
 * @note   
 * @param  sym: Name of element
 * @retval type of element else if not exist ERROR
 */
static char* getType(char* sym)
{
    struct symbol *sp = &symtab[symhash(sym)%NHASH];
    int scount = NHASH;

    while(--scount >= 0) {
        if(sp->name && !strcmp(sp->name, sym)) return (char*)(sp->tipo);

        if(!sp->name){
           return "ERROR";
        }

        if (++sp >= symtab+NHASH) sp = symtab;
    }

    fputs("symbol table overflow\n", stderr);
    abort();

}
/**
 * @brief  cheks existance of element having on input element name
 * @note   
 * @param  sym: Name of element
 * @retval if element exists return 1 else 0
 */
static int exist(char* sym)
{
    struct symbol *sp = &symtab[symhash(sym)%NHASH];
    int scount = NHASH;

    while(--scount >= 0) {

        if(sp->name && !strcmp(sp->name, sym)) return (1);

        if(!sp->name){return 0;}

        if (++sp >= symtab+NHASH) sp = symtab;

    }

    fputs("symbol table overflow\n", stderr);
    abort();

}
/**
 * @brief  modifyes the type of an element if it exists on the list
 * @note   
 * @param  sym: Element name
 * @param  tipo: Element Type
 * @param  scope: Scope Identification Number
 * @retval success 1 failure 0
 */
static int modtype(char* sym,char* tipo,int scope)
{
    struct symbol *sp = &symtab[symhash(sym)%NHASH];
    int scount = NHASH;

    while(--scount >= 0) {

        if(sp->name && !strcmp(sp->name, sym)){ 
            sp->tipo = strdup(tipo);
            sp->scope = scope;
            return 1;
        }

        if(!sp->name){return 0;}

        if (++sp >= symtab+NHASH) sp = symtab;
    }

    fputs("symbol table overflow\n", stderr);
    abort();
}




/**
 * @brief  returns the scope of an element if it exists
 * @note   
 * @param  sym: Element Name
 * @retval success scope identification number failure -1
 */
static int getScope(char* sym)
{
    struct symbol *sp = &symtab[symhash(sym)%NHASH];
    int scount = NHASH;

    while(--scount >= 0) {
        if(sp->name && !strcmp(sp->name, sym)) return (int)(sp->scope);

        if(!sp->name){
           return (-1);
        }

        if (++sp >= symtab+NHASH) sp = symtab;
    }

    fputs("symbol table overflow\n", stderr);
    abort();

}


/**
 * @brief  modifies the scope of an element if it exists
 * @note   
 * @param  sym: Element name
 * @param  scope: new Scope identification number
 * @retval success 1 failure 0
 */
static int setScope(char* sym,int scope)
{
    struct symbol *sp = &symtab[symhash(sym)%NHASH];
    int scount = NHASH;

    while(--scount >= 0) {

        if(sp->name && !strcmp(sp->name, sym)){ 
            sp->scope = scope;
            return 1;
        }

        if(!sp->name){return 0;}

        if (++sp >= symtab+NHASH) sp = symtab;
    }

    fputs("symbol table overflow\n", stderr);
    abort();
}


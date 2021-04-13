

%{

#define YYSTYPE char *
#define BUFFER_SIZE 200000

#define S "String"
#define I "int"

#include <stdio.h>
#include <string.h>
#include "symboltable.h"
#include "linkList.h"
#include "string_buffer.h"
#include "list_op.h"

extern FILE* yyin;
extern int yylineno;


int yyerror(char *s);
int yylex();

/*tab counter*/
int tab = 0;
/*tab value of precedent line*/
int otab = 0;
/*Flag for empty line*/
int end=0; 
/* type of current function */
char* currentFType;
/* current scope used for decleration disambiguation in distinct functions */
int currentScope=0;
/*inline flag*/
int in_line = 0;
/*return flag*/
int returnFlag = 0;
/*loose code flag */
int loseCodeFlag =0;
/* main existance flag */
int mainExistanceFlag = 0;
/*emptyStart flag*/
int emptyStart =1;
/*Used Lists flag*/
int listFlag = 0;


/* Cheks existance of variable in symble table else adds entry with respective type and constructs java string in return */
char* decl(char* ,char*, char*,int ); 

/* Builds if string in java having in input string condition*/
char* build_if(char*);

/*Builds java for string given iterable variable and condition variable condition  is alwais LESS THAN*/
char* build_for(char*,char*);

/*Builds strings of matematical expressions*/
char* build_mExp(char*,char*,char*);

/*Builds strings for combined Input\Output operations*/
char* build_IOop(char*,char*);

/*Builds strings for output operations*/
char* build_out(char*);

/* costume string concatenation */
char* myStrCat (char* ,char*);

/*Builds a string contaning function call with rispective decorators*/
char*  buildFCall(char* , char* );

/*gets the function name from a function call*/
char* getFName(char* );

/* builds if condition with % element*/
char*  build_odd_cond(char* , char* ,char* );

/*Adds or modifies element  to symble table*/
void addTipo( char* ,char*,int );

/*This methods are used respectevly to get the number of parenthesis needed and building a string with the parenthesis*/
int pClosure( int,int);
char* buildClosures ( int,int);

/*This function is used to build the decoration of a function*/
char* buildDecoration();
/*This Function builds the string of the java function declaration input: type,name,decoration*/
char* buildFDecleration(char*,char*,char*);

/*this function prints on file opens and closes buffer. on input requires file name*/
void printOnF (char* );

/*This function loads into the buffer a java method to emulate the python pop function */
void loadPopToBuffer();
/*This function loads into the buffer a java method to emulate the python copy function */
void loadCopyToBuffer ();
%}




%token END TAB
%token ID
%token ASSIGN
%token STRING NUM
%token LESS MORE EQUALS DIFFER AND
%token PLUS MINUS MULT DIV
%token IF ELSE 
%token INR FOR
%token RP LP LS RS COLON
%token INPUT PRINT
%token APPEND CLEAR COUNT EXTEND INSERT INDEX POP REMOVE COPY REVERSE SORT
%token DEF RETURN
%token PERCENT



%%

definition: 

|definition DEF ID  LP decoration  RP  COLON END  input    {    char* dec;
                                                                if(strcmp(strdup($3),"main")==0){
                                                                    dec = "String []args";
                                                                    currentFType="void";

                                                                    mainExistanceFlag = 1;
                                                                    if(loseCodeFlag){insetrOnTop("loose_code();\n");loseCodeFlag=0;}

                                                                }else{ 
                                                                    dec = buildDecoration();
                                                                }
                                                                
                                                                if(returnFlag == 0){currentFType="void";}
                                                                returnFlag =0;
                                                                

                                                                char* top = buildFDecleration(currentFType,$3,dec);
                                                                insetrOnTop(top);
                                                                
                                                                char* closures = buildClosures(otab,tab );
                                                                insertBuffer(closures);
                                                                
                                                                printBuffer() ;

                                                                printOnF ("newprogram.java") ;

                                                                clearBuffer();
                                                                clearList();


                                                                otab=0;
                                                                tab=0;
                                                                 
                                                                currentScope++;
                                                            }
|input                                                      {  if(!emptyStart){  char* top = buildFDecleration("void","loose_code"," ");
                                                                insetrOnTop(top);
                                                                insertBuffer("}");
                                                                printBuffer() ;printOnF ("newprogram.java");clearBuffer();
                                                                loseCodeFlag=1;}}

   
;


decoration:          {currentFType = "void";}
|ID decoration          { addList($1); currentFType = "void"; }
;

input:
|input line                                 {   
                                                if(!end){     

                                                    emptyStart=0;
                                                    in_line = 0;
                                                    char* closures = buildClosures(otab,tab );
                                                    insertBuffer(closures);
                                                    insertBuffer(strdup($2));
                                                    insertBuffer("\n");
                                                    otab=tab; 
                                                    tab=0;                                                    
                                                
                                                }else{
                                                    in_line = 0;
                                                    end=0;
                                                    insertBuffer(strdup($2));
                                                    tab=0;                                                    
                                                }
                                            }


;



line: END                                 {$$="\n ";end=1;}

| tab                                     { $$ = $1;  }

| tab IOoperation                         {  $$ = strdup($2); }

| tab declaration                         {  $$ = strdup($2); }           //$$ = strcat(strdup($2),"\n");

| tab list                                {   if(in_line==0){$$ = myStrCat(strdup($2),";");}else{$$ = strdup($2);} listFlag = 1; } 

| tab selection                           {  $$ =strdup($2);    }   //strcat(strdup($2),"\n");

| tab ELSE COLON                          { $$="else{";      }

| tab iteration                           {  $$ = strdup($2);   } 

| tab function_call                       { $$ = myStrCat( strdup($2),";"); }

| tab RETURN type                         {if( strcmp(  getType($3),"String")!=0){currentFType=getType($3);}      char* ret=myStrCat("return ",strdup($3));$$=myStrCat(ret,";"); returnFlag=1;}

;



tab:                                                                      
| TAB tab                                   {tab++; $$=" ";}
;

declaration: ID ASSIGN STRING               {$$ = decl(strdup($1), S ,strdup($3),currentScope ); }

| ID ASSIGN NUM                             {$$ = decl(strdup($1), I ,strdup($3),currentScope ); }

| ID ASSIGN math_exp                        {$$ = decl(strdup($1), I ,strdup($3),currentScope ); }

| ID ASSIGN function_call                   {$$ = decl(strdup($1),getType(getFName($3)),strdup($3),currentScope);}

| ID ASSIGN ID                              {$$ = decl(strdup($1),getType(getFName($3)),strdup($3),currentScope);}

| ID ASSIGN list                            {$$ = decl(strdup($1),currentFType,strdup($3),currentScope);}
;

selection: IF LP condition RP COLON         { $$ = build_if(strdup($3));  }

| IF condition COLON                        { $$ = build_if(strdup($2));  }


;

iteration: FOR type INR LP type RP COLON    {$$=build_for(strdup($2),strdup($5));}
;

IOoperation: ID ASSIGN INPUT LP RP          {$$ = decl(strdup($1), S ,"tastiera.nextLine()",currentScope );}

| ID ASSIGN INPUT LP type RP                {$$ = build_IOop(strdup($1),strdup($5));}

| PRINT LP txt RP                           {$$ = build_out(strdup($3));}
;

list: ID ASSIGN LS RS                       {$$= newList(strdup($1));                               }
| ID APPEND LP type RP                      {$$= appendList (strdup($1),strdup($4)  );              }
| ID CLEAR LP RP                            {$$=clList ( strdup($1)   );                            }
| ID COUNT LP RP                            {$$= countList ( strdup($1)  );     currentFType="int" ;                      }
| ID EXTEND LP type RP                      {$$= extendList ( strdup($1),strdup($4) );              }
| ID INDEX LP type RP                       {$$= indexList ( strdup($1),strdup($4)  );   currentFType="int" ;         }
| ID INSERT LP type type RP                 {$$=  insertList( strdup($1),strdup($4),strdup($5) );   }
| ID POP LP RP                              {$$=  popList (strdup($1)    );                         }
| ID POP LP type RP                         {$$= popElList ( strdup($1),strdup($4)  );              }
| ID REMOVE LP type RP                      {$$=removeList( strdup($1),strdup($4)   );              }
| ID COPY LP RP                             {$$= copyList( strdup($1)  );                           }
| ID REVERSE LP RP                          {$$= reverseList( strdup($1)  );                        }
| ID SORT LP RP                             {$$= sortList( strdup($1)  );                           }
;

function_call: ID LP  RP                    {$$ = buildFCall(strdup($1)," ");}
| ID LP passing_vallues RP                  {$$ = buildFCall(strdup($1),strdup($3));}
;

passing_vallues:  type          {$$ = $1; }
|type passing_vallues       {$$ = myStrCat(strdup($1),strdup(",")); $$ = myStrCat(strdup($$),strdup($2));}
;


txt:type                                    {$$=$1;}

|type txt                                   {$$=$1;strcat($$,"+");strcat($$,$2);}
;

condition: type                             {$$ = $1;addTipo(strdup($1),"int",currentScope);}

| type logic_op type                        {$$ = $1; strcat($$,$2); strcat($$,$3);addTipo(strdup($1),"int",currentScope);addTipo(strdup($3),"int",currentScope); }

| type PERCENT type EQUALS type                            {$$ = build_odd_cond(strdup($1),strdup($3),strdup($5));
                                                            addTipo(strdup($1),"int",currentScope);
                                                            }

| condition condition                       {$$ = $1; strcat($$," ");strcat($$,$2); }
;

type: ID                                    {$$ = strdup($1);}

| NUM                                       {$$ = strdup($1);currentFType = "Int";}

| STRING                                    {$$ = strdup($1); currentFType = "String";}

| list                                      {$$ = strdup($1); in_line=1;}

| function_call                             {$$ = strdup($1)}
;

math_exp: type math_op type                 {$$= build_mExp($1,$2,$3);}

|   LP math_exp RP                          {$$= build_mExp("(",strdup($2),")");}
;

logic_op: EQUALS                            { $$ = "==";}

| DIFFER                                    {$$ = "!="; }

| LESS                                      {$$ = "<"; }

| MORE                                      {$$ = ">"; }

| AND                                       {$$ = "&&";}
;

math_op: PLUS                               {$$="+";}
| MINUS                                     {$$="-";}
| MULT                                      {$$="*";}
| DIV                                       {$$="/";}
;



%%


char* buildDecoration(){

    if(!isEmpty()){
        
        char buffer[2048];
        *buffer=NULL;
        while(!isEmpty())
        {
            struct node* element = pop();
            char* nome = element->nome;
            char* tipo = getType(nome);
            
            if(Listlength()!=0){ 
                char* tmp= strdup(buffer);
                
                snprintf(buffer, sizeof(buffer), "%s %s %s , ",tmp , tipo,nome);
            }else{
                char* tmp= strdup(buffer);
                
                snprintf(buffer, sizeof(buffer), "%s %s %s ",tmp , tipo,nome);
            }
            
        }
        char* str = buffer;
        return str;
    }
    return " ";
}


char* decl( char* name, char* type, char* val,int currentScope){  

    char buffer[2048];
    
    if(exist(name) == 1 && getScope(name)==currentScope){
        modtype(name,type,currentScope);
        snprintf(buffer, sizeof(buffer), "%s = %s ;" , name,val);
        char* ass = buffer;
        return ass;

    }
    else if(exist(name) == 1 && getScope(name)!=currentScope){
        modtype(name,type,currentScope);
        snprintf(buffer, sizeof(buffer), "%s %s = %s ;" , type, name,val);  
        
        setScope(name,currentScope);
        char* ass = buffer;
        return ass;

    }
    else{        
        
        addref(yylineno,  name, type,currentScope);        
        
        snprintf(buffer, sizeof(buffer), "%s %s = %s ;" , type, name,val);        
        char* dec = buffer;
        
        return dec;

    }


}


char* build_if(char* cond){
   
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "if ( %s ){ " , cond);
    char* sel = buffer;
    return sel;

}


int pClosure(int otab,int tab ){
    int closures=0;
    
    //while ( otab > tab ){ closures++;otab--;}
    
    if(otab>tab){closures = otab-tab;}
    

    return closures;     

}


char* build_for(char* iter,char* cond){
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "for(;%s<%s;%s++){" ,iter, cond,iter);
    char* str = buffer;
    return str;
}


char* build_mExp(char* l,char* c,char* r){
    char buffer[1024];
    
    snprintf(buffer, sizeof(buffer), "%s %s %s",l,c,r);
    char* str = buffer;
    return str;
}


char* build_IOop(char* id,char* strout){
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%s\n%s " ,build_out (strout), decl(id, S ,"tastiera.nextLine()" ,currentScope) );
    char* str = buffer;
    return str;
}

char* build_out (char* outs){
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "System.out.println( %s );" ,outs );
    char* str = buffer;
    return str;
}

char* myStrCat (char* l ,char* r){
    

    char buffer[BUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "%s%s" ,l,r );
  
    char* str = buffer;
    
    return str;
}



void addTipo( char* var,char* tipo,int currentScope)
{
    if (exist(var))
    {
        modtype(var,tipo,currentScope);
        printf("---------------------------------%s,%s",var,tipo);
    }else{
        addref(yylineno,  var, tipo,currentScope); 
    }

}


char*  buildFCall(char* name, char* values)
{   
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%s(%s)" , name,values);
    char* fun = buffer;
    
    return fun;

}

char*  build_odd_cond(char* element, char* divisor,char* equals)
{   
    char buffer[BUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "%s %% %s == %s" , element,divisor,equals);
    char* cnd = buffer;
    
    return cnd;

}
char* getFName(char* fun){char *sym = strtok(fun, "("); return sym;}

char* buildClosures ( int otab,int tab )
{   
    int cl = pClosure(otab,tab );
    if(cl!=0){
    
    char* cnd =malloc(sizeof(char));
    
    while (cl>0){ 
        strcat(cnd,"}");
        cl--;
    }   
    return cnd;    
    }
    else
    {
        return " ";
    } 
    
}

char* buildFDecleration(char* tipo,char* nome,char* dec)
{
    char buffer[BUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "public static %s %s ( %s ) { \n",tipo,nome,dec );
  
    
    char* str = buffer;
    
    return str;
}


int yyerror(char* s) {
    
    printf("%s in linea : %d \n", s , yylineno);
    
}


void printOnF (char* name )
{
    FILE *fptr;

    fptr = fopen(name,"a");

    printBufferOnFile(fptr);

    fclose(fptr);

}

void loadPopToBuffer (){

    insertBuffer("public static Object popList (ArrayList lst, int j) \n" );    
    insertBuffer("{\n Object temp = new Object();\n");
    insertBuffer(" temp = lst.get(j);\n lst.remove(j);\n");   
    insertBuffer(" return temp;\n}\n");
    
    
}

void loadCopyToBuffer (){

  insertBuffer( "public static ArrayList copyList ( ArrayList toCopy){\n" );
  insertBuffer(" ArrayList copy = new ArrayList();\n");
  insertBuffer( "copy.addAll(toCopy); \n return copy;}   ");
    
    
}

int main(int argc, char const *argv[]) {
    
    
    insertBuffer("import java.util.ArrayList;\n");
    insertBuffer("import java.util.Collections;\n");
    insertBuffer("public class CLASSNAME{ \n");
    printBuffer() ;
    printOnF ("newprogram.java") ;
    clearBuffer();

    

    yyin = fopen(argv[1], "r");

    int result_code = yyparse();

    fclose(yyin);

    if (!mainExistanceFlag && loseCodeFlag)
    {
        insertBuffer("public void main ( ){\n");
        insertBuffer("loose_code();\n");
        insertBuffer("}\n");


    }    





    loadPopToBuffer ();
    printBuffer() ;
    printOnF ("newprogram.java") ;
    clearBuffer();
    loadCopyToBuffer ();
    

    insertBuffer("}\n");

    

    printBuffer() ;
    printOnF ("newprogram.java") ;
    
    
    return result_code;
}
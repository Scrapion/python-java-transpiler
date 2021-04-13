%option noyywrap yylineno


%{

#define YYSTYPE char const *
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>


extern int yyparse (void);
char* curfilename;
%}
tab [\t]
tabS [ ]{4}
ws [ ]
letter [a-zA-Z_]
digit [0-9]
number (-)?{digit}+
id     {letter}({letter}|{digit})*
qt  ["]
sqt [']
inr (in{ws}+range)
string {qt}(.*){qt}|{sqt}.*{sqt}
%%

"(" 	{return LP;}
")"		{return RP;}
"["     {return LS;}
"]"     {return RS;}
":" {return COLON;}
{tab} {return TAB;}
{tabS} {return TAB;}
{inr} {return INR;}
"for" {return FOR;}
"<" {return LESS;}
">"	{return MORE;}
"==" {return EQUALS;}
"!=" {return DIFFER;}
"+"  {return PLUS;}
"*" {return MULT;}
"/" {return DIV;}
"\n" {return END;}
"=" {return ASSIGN;}
"if" {return IF;}
"else" {return ELSE;}
"input" {return INPUT;}
"print" {return PRINT;}
"def"   {return DEF;}
".append" {return APPEND;}
".clear" {return CLEAR;}
".count" {return COUNT;}
".extend" {return EXTEND;}
".index" {return INDEX;}
".insert" {return INSERT;}
".pop" {return POP;}
".remove" {return REMOVE;}
".copy" {return COPY;}
".reverse" {return REVERSE;}
".sort" {return SORT;}
"%"       {return PERCENT;}
"return"  {return RETURN;}

{id} {yylval = strdup(yytext); return ID;}
{number} {yylval = strdup(yytext); return NUM;}
"-"  {return MINUS;}
{string} {yylval=strdup(yytext); return STRING;}

","
%%

/*".copy" {return COPY;}*/
flex scanner.l
bison -d parser.y
gcc parser.tab.c lex.yy.c -L"C:/GnuWin32/lib" -lfl
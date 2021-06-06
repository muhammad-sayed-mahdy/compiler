# compiler

## How to run
```bash
flex -o lexer.cpp lexer.l
bison parser.y --yacc -d -o parser.cpp
g++ compiler.c parser.cpp lexer.cpp
./a.out
```
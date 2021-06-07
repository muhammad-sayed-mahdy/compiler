# compiler

## How to run
```bash
flex -o lexer.cpp lexer.l
bison parser.y --yacc -d -o parser.cpp
g++ compiler.cpp parser.cpp lexer.cpp
./a.out
```
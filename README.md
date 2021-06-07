# compiler

## How to run
```bash
flex -o lexer.cpp lexer.l
bison parser.y -d -o parser.cpp
g++ compiler.cpp parser.cpp lexer.cpp
./a.out

```
## For Debugging Segmentation fault
```
g++ compiler.cpp parser.cpp lexer.cpp -g -fsanitize=address -fsanitize=undefined -DGLIBCXX_DEBUG

```
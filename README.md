# compiler

## How to run
To compile and run use:
```bash
make
```
To just run use:
```bash
make run
```
The input file can be found in `data/in.cpp`, you can play with this file and run.  
You can also change the input file and run the program after compiling with
```bash
./src/a.out <input_file> <output_quad_file> <symbol_table_file>
```

## For Debugging Segmentation fault
```
g++ compiler.cpp parser.cpp lexer.cpp -g -fsanitize=address -fsanitize=undefined -DGLIBCXX_DEBUG

```
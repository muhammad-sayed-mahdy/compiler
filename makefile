all:
	@make -s build
	@make -s run

build:
	@make -s gen
	@make -s comp
	
gen:
	flex -o src/lexer.cpp src/lexer.l
	bison src/parser.y -d -o src/parser.cpp

comp:
	g++ src/main.cpp src/compiler.cpp src/parser.cpp src/lexer.cpp -o src/a.out


run:
	./src/a.out data/in.cpp data/out.quad data/symbol_table.txt

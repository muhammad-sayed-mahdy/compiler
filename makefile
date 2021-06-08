all:
	@make -s build
	# @make -s run

build:
	@make -s gen
	@make -s comp
	
gen:
	flex -o src/lexer.cpp src/lexer.l
	bison src/parser.y -d -o src/parser.cpp

comp:
	g++ src/compiler.cpp src/parser.cpp src/lexer.cpp	


# run:
# 	./src/a.out data/input.mpp -o data/out.quad -s data/symbol_table.txt

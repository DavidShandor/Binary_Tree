all: EX4.cpp  Btree.cpp Btree.h
	g++ EX4.cpp Btree.cpp -o EX4
all-GDB: EX4.cpp Btree.h Btree.cpp
	g++ -g EX4.cpp Btree.cpp -o EX4

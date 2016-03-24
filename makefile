all: P4
P4: removal main.o utility.o Hash_table1.o Hash_table2.o
	g++ -o P4 main.o utility.o Hash_table1.o Hash_table2.o
main.o: main.cpp
	g++ -c -g main.cpp
Hash_table2.o: Hash_table2.cpp
	g++ -c -g Hash_table2.cpp
Hash_table1.o: Hash_table1.cpp
	g++ -c -g Hash_table1.cpp
utility.o: utility.cpp
	g++ -c -g utility.cpp
removal:
	rm -f *.o
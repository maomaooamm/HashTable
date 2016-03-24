#include "Hash_table1.h"
//linear probing


Hash_table1::Hash_table1(int size){
	count = size;
	table = new string[count];
	clear();
}

void Hash_table1::clear(){for(int i = 0; i < count; i++) table[i] = "0";}

int Hash_table1::hash(const string &key){
	int value = 1;
	for (int i = 0; i < 6; i++) value *= key[i];
	value %= count;
	if(value < 0) value += count;
	return value;
}

int Hash_table1::insert(const string &new_entry){
	int value = hash(new_entry);
	while(value < count && value >= 0 && table[value] != "0"){
		if(table[value] == new_entry) return -1;
		value++;
	}
	if(value >= count) return -1;
	else{
		table[value] = new_entry;
		return value;
	}
}

int Hash_table1::retrieve(const string &target){
	int value = hash(target);
	while(value < count && value >= 0 && table[value] != target){value++;}
	if(value >= count) return -1;
	else value;
}
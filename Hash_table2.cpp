#include "Hash_table2.h"
//quadratic probing

Hash_table2::Hash_table2(int size){
	count = size;
	table = new string[count];
	clear();
}

void Hash_table2::clear(){for(int i = 0; i < count; i++) table[i] = "0";}

int Hash_table2::hash(const string &key){
	int value = 1;
	for (int i = 0; i < 6; i++) value *= key[i];
	value %= count;
	if(value < 0) value += count;
	return value;
}

int Hash_table2::insert(const string &new_entry){
	int value = hash(new_entry);
	int probe;
	while(probe < count){
		if(table[value] == new_entry) return -1;
		value++;
		if(table[value] == "0"){
			table[value] = new_entry;
			return value;
		}
		probe++;
		value = (value+probe*probe)%count;
	}
	return -1;
}

int Hash_table2::retrieve(const string &target){
	int value = hash(target);
	int probe;
	while(probe < count && value >= 0){
		if(table[value] == target) return value;
		probe++;
		value = (value + probe*probe)%count;
	}
	return -1;
}
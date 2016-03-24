#include <string>
using namespace std;
//quadratic probing

class Hash_table2{
	int count;
	string* table;
public:
	Hash_table2(int size);
	void clear();
	int hash(const string &key);
	int insert(const string &new_entry);
	int retrieve(const string &target);
};
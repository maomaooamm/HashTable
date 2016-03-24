#include <string>
using namespace std;
//linear probing
class Hash_table1{
	int count;
	string* table;
public:
	Hash_table1(int size);
	void clear();
	int hash(const string &key);
	int insert(const string &new_entry);
	int retrieve(const string &target);
};

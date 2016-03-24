#include "utility.h"
#include "List.h"
#include "Ordered_list.h"
#include "Linked_list.h"
#include "searches.h"
#include "Hash_table1.h"
#include "Hash_table2.h"

#define REPEAT_FACTOR 100000

int main(){
	clock_t start, finish;
   double elapsed_time;

   string input = "";
   bool exit_now = false;
   Ordered_list<string> ol;
   Hash_table1 ht1 = Hash_table1(220009);
   Hash_table1 ht2 = Hash_table1(800011);
   Hash_table2 ht3 = Hash_table2(220009);
   Hash_table2 ht4 = Hash_table2(800011);

   string search_key;
   int position = 0;

   string result = "";
   Error_code code;

   while(!exit_now){
      cout << endl;
      cout << "***********************" << endl;
      cout << "Menu:" << endl;
      cout << "1. Import List from File" << endl;
      cout << "2. Sequential Search" << endl;
      cout << "3. Binary Search" << endl;
      cout << "4. Hash Table 1 (Size = 200003)" << endl;
      cout << "5. Hash Table 1 (Size = 800011)" << endl;
      cout << "6. Hash Table 2 (Size = 200003)" << endl;
      cout << "7. Hash Table 2  (Size = 800011)" << endl;
      cout << "x. Exit" << endl;
      cout << "***********************" << endl;

      getline(cin, input);

      if(input == "1"){
         cout << endl << "Enter List File Name:" << endl;
         getline(cin, input);
         ifstream insertion_file;
         insertion_file.open(input.c_str());
         if(!insertion_file.fail()){
            ol.clear();
            int cnt = 0;
            while(!insertion_file.fail() && !insertion_file.eof()){
               getline(insertion_file, input);
               input = rtrim(input);
               ol.insert(cnt, input);
               ht1.insert(input);
               ht2.insert(input);
               ht3.insert(input);
               ht4.insert(input);
               //ol.retrieve(cnt, input);
               //cout << input << endl;
               cnt++;
               if(cnt%10000==0)
                  cout << cnt << " entries imported." <<endl;
            }
         } else
            cout << "Invalid file name." << endl;
      }
      else if(input == "2"){
         cout << endl;
         cout << "Enter a string for search:" << endl;
         getline(cin, input);
         search_key = lpad(input, max_key_length, "0");
         start = clock();
         code = sequential_search<string, string>(ol, search_key, position);
         finish = clock();
         elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
         if (code == success)
            cout << endl << "String " << search_key << " is found at Position " << position << "." << endl;
         else
            cout << endl << "String " << search_key << " is not found." << endl;
         cout << endl << "Time: " << elapsed_time << " seconds" << endl << endl;
      }
      else if(input == "3"){
         cout << endl;
         cout << "Enter a string for search:" << endl;
         getline(cin, input);
         search_key = lpad(input, max_key_length, "0");
         start = clock();
         for(int i = 0; i < REPEAT_FACTOR; i++) code = binary_search(ol, search_key, position);
         finish = clock();
         elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
         if (code == success)
            cout << endl << "String " << search_key << " is found at Position " << position << "." << endl;
         else
            cout << endl << "String " << search_key << " is not found." << endl;
         cout << endl << "Time: " << elapsed_time << " seconds" << endl << endl;
      } 
      else if(input == "4"){
         int location;

         cout << endl;
         cout << "Enter a string for search:" << endl;
         getline(cin, input);
         search_key = lpad(input, max_key_length, "0");
         start = clock();
         for(int i = 0; i < REPEAT_FACTOR; i++) location = ht1.retrieve(search_key);
         finish = clock();
         elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
         if (location >= 0)
            cout << endl << "String " << search_key << " is found at Position " << location << "." << endl;
         else
            cout << endl << "String " << search_key << " is not found." << endl;
         cout << endl << "Time: " << elapsed_time << " seconds" << endl << endl;
      }
      else if(input == "5"){
         int location;

         cout << endl;
         cout << "Enter a string for search:" << endl;
         getline(cin, input);
         search_key = lpad(input, max_key_length, "0");
         start = clock();
         for(int i = 0; i < REPEAT_FACTOR; i++) location = ht2.retrieve(search_key);
         finish = clock();
         elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
         if (location >= 0)
            cout << endl << "String " << search_key << " is found at Position " << location << "." << endl;
         else
            cout << endl << "String " << search_key << " is not found." << endl;
         cout << endl << "Time: " << elapsed_time << " seconds" << endl << endl;
      }
      else if(input == "6"){
         int location;

         cout << endl;
         cout << "Enter a string for search:" << endl;
         getline(cin, input);
         search_key = lpad(input, max_key_length, "0");
         start = clock();
         for(int i = 0; i < REPEAT_FACTOR; i++) location = ht3.retrieve(search_key);
         finish = clock();
         elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
         if (location >= 0)
            cout << endl << "String " << search_key << " is found at Position " << location << "." << endl;
         else
            cout << endl << "String " << search_key << " is not found." << endl;
         cout << endl << "Time: " << elapsed_time << " seconds" << endl << endl;
      }
      else if(input == "7"){
         int location;

         cout << endl;
         cout << "Enter a string for search:" << endl;
         getline(cin, input);
         search_key = lpad(input, max_key_length, "0");
         start = clock();
         for(int i = 0; i < REPEAT_FACTOR; i++) location = ht4.retrieve(search_key);
         finish = clock();
         elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
         if (location >= 0)
            cout << endl << "String " << search_key << " is found at Position " << location << "." << endl;
         else
            cout << endl << "String " << search_key << " is not found." << endl;
         cout << endl << "Time: " << elapsed_time << " seconds" << endl << endl;
      }
      else if(input == "x")
         exit_now = true;
   }
}

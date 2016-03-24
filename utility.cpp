#include "utility.h"

int string_to_int(string s){
   istringstream instr(s);
   int n;
   instr >> n;
   return n;
}

string lpad(string s, unsigned int str_len, string pad_s){
   string result = s;
   if(s.size() < str_len){
      int difference = str_len - s.size();
      for(int i = 0; i < difference; i++)
         result = pad_s + result;
   }
   return result;
}

string rtrim(string str) {
   string s = str;
   return s.erase(s.find_last_not_of(" \n\r\t") + 1);   
}
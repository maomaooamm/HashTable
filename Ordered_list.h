template <class Record>
class Ordered_list:public List<Record>{
public:
   Ordered_list();
   Error_code insert(const Record &data);
   Error_code insert(int position, const Record &data);
   Error_code replace(int position, const Record &data);
};

 
template <class Record>
Ordered_list<Record>::Ordered_list():List<Record>(){
}

template <class Record>
Error_code Ordered_list<Record>::insert(const Record &data){
   int s = this->size();
   int position;
   for (position = 0; position < s; position++) {
      Record list_data;
      retrieve(position, list_data);
      if (data < list_data) break;
   }
   return List<Record>::insert(position, data);
}

template <class Record>
Error_code Ordered_list<Record>::insert(int position, const Record &data)
{
   Record list_data;
   if (position > 0) {
      retrieve(position - 1, list_data);
      if (data < list_data)
         return fail;
   }
   if (position < this->size()) {
      retrieve(position, list_data);
      if (data > list_data)
         return fail;
   }
   return List<Record>::insert(position, data);
}

template <class Record>
Error_code Ordered_list<Record>::replace(int position, const Record &data)
{
   Record list_data;
   if (position > 0) {
      retrieve(position - 1, list_data);
      if (data < list_data)
         return fail;
   }
   if (position < this->size()) {
      retrieve(position, list_data);
      if (data > list_data)
         return fail;
   }
   return List<Record>::replace(position, data);
}

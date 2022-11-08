// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using Str_Pair = std::initializer_list<std::pair<std::string, std::string>>;
using std::pair;
#define Get(identifier) identifier.begin() 

struct student {
    std::string name, id;
    student* next;
    student() : name(), id(), next(NULL) {};
    student(std::string name, std::string id) : name(name), id(id), next(NULL) {};
    //I reccomend using this constructor

};
struct tree : student {
    int size;
    tree(Str_Pair pairs) {
        //current node has already been defined, so skip first value
        name = Get(pairs)->first;
        id = Get(pairs)->second;
        size = pairs.size();
        student* temp_ptr = this;
        for (int x = 1; x < size; x++) {


            temp_ptr->next = new student((Get(pairs) + x)->first, (Get(pairs) + x)->second);
            temp_ptr = temp_ptr->next;
        }
    }
    struct student* insert(pair<std::string, std::string> values, int index) {
        struct student* temp;
        for (int x = 0; x < index; x++) {

        }
        
    };
};

int main()
{
    tree values({ {"bob", "1235"}, {"joe", "315"}, {"john", "32"}});
    std::cout << values.next->next->id << " is the id ," << values.next->next->name <<  " is the name\n";
    std::cout << "Hello World!\n";


}

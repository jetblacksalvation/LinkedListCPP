// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using Str_Pair = std::initializer_list<std::pair<std::string, std::string>>;
using std::pair;



#define Get(identifier) identifier.begin() 
//g++ main.cpp ; ./a.exe
//unix - 
//g++ main.cpp && ./a.exe

struct student {
    std::string name, id;
    student* next;
    
    student() : name(), id(), next(NULL) {};
    student(std::string name, std::string id) : name(name), id(id), next(NULL) {};
   
    
    //I reccomend using this constructor

};
struct tree :private student { 

    int size;


    tree(Str_Pair pairs) {
        //current node has already been defined, so skip first value
        name = Get(pairs)->first;
        id = Get(pairs)->second;
        size = pairs.size();
        student* temp_ptr = this;
        //initializes the linked list
        for (int x = 1; x < size; x++) {


            temp_ptr->next = new student((Get(pairs) + x)->first, (Get(pairs) + x)->second);
            temp_ptr = temp_ptr->next;
        }
        

    }
    struct student* get_root_ptr(){
        return this;
    }


    void print_nodes(){
        student * temp = this;
        while(temp != NULL){
            std::cout<<"name is :"<<temp->name<<" id is :"<<temp->id<<std::endl;
            temp = temp->next;
        }
    };

    //root is unchangeable using this method, use set root to change root value. Zero is second node
    void insert(pair<std::string, std::string> values, int index) {
        struct student* temp = this;
        for(int x =0; x<index  ; x++){
            temp = temp->next;
        }
        if (size == index){
            //pushback
            temp->next = new student(values.first, values.second);
        }
        else{
            //copy next into a temp pointer
            struct student * hold_next = temp->next;
            temp->next = new student(values.first, values.second);
            temp->next->next = hold_next;
        }
        size++;
    };

};

int main()
{
    tree values({ {"bob", "1235"}, {"joe", "315"}, {"john", "32"}});
    //values.print_nodes();
    values.insert(pair<std::string,std::string>({"fdafdas", "fa"}), 0);
    values.print_nodes();
    
    //std::cout << values.next->next->id << " is the id ," << values.next->next->name <<  " is the name\n";
    std::cout << "Hello World!\n";
    auto ptr = values.get_root_ptr();
    std::cout<<ptr->id;
}

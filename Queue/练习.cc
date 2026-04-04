#include <iostream>
using namespace std;
template <typename T>
class LinkQueue{
    private:
    struct Linknode{
        T data;
        Linknode* next;
        Linknode(T v) : data(v), next(nullptr) {}
    };
    Linknode* first;
    Linknode* last;
    int count;
    public:
     LinkQueue() : count(0) { first = new Linknode(T());
         last = first;
     }
     ~LinkQueue() { Linknode* cur = first;
    while(cur!=nullptr){
        Linknode* temp = cur;
        cur = cur->next;
        delete (temp);
        temp = nullptr;
    }
    first = last = nullptr;
    count = 0;
     }
     LinkQueue(const LinkQueue&) = delete;
     LinkQueue& operator=(const LinkQueue&) = delete;
     void push(T val) { Linknode* newnode = new Linknode(val);
         last->next = newnode;
         last = newnode;
         count++;
     }
     void pop(){
        if(is_empty()){
            return;
        }
        Linknode* temp = first;
        first = first->next;
        delete temp;
        count--;
        if(first->next==nullptr){
            last = first;
        }
     }
     T first (){ return first->data; }
     T last() { return last->data; }
     bool isempty() { return first == nullptr; }
     int count() { return count; }
     void clear(){
        while(!is_empty()){
            pop();
        }
     }
};
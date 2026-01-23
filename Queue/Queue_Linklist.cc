#include <iostream>
template <typename T>
class LinkQueue {
   private:
    struct Node {
        T val;       
        Node* next;  
        Node(T value) : val(value), next(nullptr) {}
    };
    Node* first;  
    Node* last;  
    int size; 
   public:
    LinkQueue() : size(0) {
        first = new Node(T());  
        last = first;         
    }
    ~LinkQueue() {
        Node* cur = first;
        while (cur != nullptr) {
            Node* temp = cur; 
            cur = cur->next;  
            delete temp;    
        }
        first = last = nullptr;
        size = 0;
    }
    LinkQueue(const LinkQueue&) = delete;
    LinkQueue& operator=(const LinkQueue&) = delete;
    void push(T val) {
            Node* newNode = new Node(val);  
            last->next = newNode;          
            last = newNode;                
            size++;                       
    }
    void pop() {
        if (isEmpty()) {
            return;
        }
        Node* temp = first->next;  
        first->next = temp->next; 
        if (first->next == nullptr) {
            last = first;
        }
        delete temp;  
        size--;        
    }
    T front() {
        if (isEmpty()) {
            return NULL;
        }
        return first->next->val;
    }
    T back() {
        if (isEmpty()) {
            return NULL;
        }
        return last->val;
    }
    bool isEmpty() {
        return first->next == nullptr;  
    }
    int size() {
        return size;  
    }
    void clear() {
        Node* cur = first->next;
        while (cur != nullptr) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
        first->next = nullptr;
        last = first;
        size = 0;
    }
};
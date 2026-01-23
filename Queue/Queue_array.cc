#include <iostream>  
template <typename T>
class ArrayQueue {
   private:
    T* arr;        
    int capacity;  // 最大可存储元素数 = capacity - 1，牺牲1个位置判满
    int first;    
    int last;  // 指向队列下一个可插入的空位置
   public:
    ArrayQueue(int capacity = 10)
        : capacity(capacity), first(0), last(0) {
        arr = new T[capacity];
    }
    ~ArrayQueue() {
        delete[] arr;  
        arr = nullptr; 
        capacity = first = last = 0;
    }
    ArrayQueue(const ArrayQueue&) = delete;
    ArrayQueue& operator=(const ArrayQueue&) = delete;
    void push(T val) {
        if (isFull()) {
            return;
        }
        arr[last] = val;               
        last = (last + 1) % capacity;  
    }
    void pop() {
        if (isEmpty()) {
            return;
        }
        first = (first + 1) % capacity;  
    }
    T first() {
        if (isEmpty()) {
            return NULL;
        }
        return arr[first];
    }
    T back() {
        if (isEmpty()) {
            return NULL;
        }
        int backIdx = (last - 1 + capacity) % capacity;
        return arr[backIdx];
    }
    bool isEmpty() {
        return first == last;  
    }
    bool isFull(){
        return (last + 1) % capacity == first;
    }
    int size(){
        return (last - first + capacity) % capacity;
    }
    int capacity()  { 
        return capacity; 
    }
    void clear() { 
        first = last = 0; 
    }
};

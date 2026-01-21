#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class ArrayStack {
   private:
    vector<T> data;  
    int topIdx;     
    int capacity;   
   public:
    ArrayStack(int cap = 10) : capacity(cap), topIdx(-1) {
        data.reserve(capacity); 
    }
    void push(T val) {
        if (topIdx + 1 >= capacity) {
            capacity *= 2;
            data.reserve(capacity);
        }
        topIdx++;
        if (topIdx < data.size()) {
            data[topIdx] = val; //复用已分配的空间
        } else {
            data.push_back(val);  
        }
    }
    void pop() {
        if (isEmpty()) {
            return;
        }
        topIdx--;  // 逻辑删除
    }
    T top() {
        if (isEmpty()) {
            return NULL;
        }
        return data[topIdx];
    }
    bool isEmpty() {
         return topIdx == -1; 
    }
    int size() { 
        return topIdx + 1;
    }
    void clear() {
        topIdx = -1;  // 逻辑清空，无需释放内存
        // data.clear();  物理清空，释放内存
    }
    // 从栈顶到栈底
    void print() {
        if (isEmpty()) {
            cout << "栈为空" << endl;
            return;
        }
        for (int i = topIdx; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    ArrayStack<int> stack(5);  
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.print();  
    cout << "栈顶元素：" << stack.top() << endl; 
    stack.pop();
    cout << "栈是否为空：" << (stack.isEmpty() ? "是" : "否") << endl;  
    cout << "栈大小：" << stack.size() << endl;                         
    stack.clear();
    return 0;
}

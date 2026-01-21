#include <iostream>
using namespace std;
template <typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(T v) : val(v), next(nullptr) {}
};
template <typename T>
class LinkedStack {
   private:
    ListNode<T>* topNode;  
    int count;            
   public:
    LinkedStack() : topNode(nullptr), count(0) {}
    ~LinkedStack() { 
        clear(); 
    }
    void push(T val) {
        ListNode<T>* newNode = new ListNode<T>(val);
        newNode->next = topNode;  
        topNode = newNode;        
        count++;
    }
    void pop() {
        if (isEmpty()) {
            return;
        }
        ListNode<T>* temp = topNode;  
        topNode = topNode->next;      
        delete temp;                 
        count--;
    }
    T top() {
        if (isEmpty()) {
            return NULL;
        }
        return topNode->val;
    }
    bool isEmpty() {
        return topNode == nullptr; 
    }
    int size() {
        return count;
    }
    void clear() {
        while (!isEmpty()) {
            pop();  
        }
    }
    void print() {
        if (isEmpty()) {
            cout << "栈为空" << endl;
            return;
        }
        cout << "顶->底：";
        ListNode<T>* cur = topNode;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    // 禁用拷贝构造和赋值（避免浅拷贝内存泄漏）,是C++11引入的语法，核心作用是禁用链表栈的拷贝构造和赋值操作，避免浅拷贝导致的内存泄漏、重复释放等致命问题，链表栈的底层是手动new的节点，默认浅拷贝只会复制指针值，不会复制节点内容，导致两个对象共享同一块内存，导致重复释放和修改同步，=delete是 C++11的「删除函数」语法，作用是：告诉编译器：不要生成这个函数的默认版本；如果代码中尝试调用被删除的函数（比如拷贝构造 /赋值），编译器会直接报错，把运行期的内存崩溃问题，提前到编译期解决，代码更安全
    LinkedStack(const LinkedStack&) = delete;
    LinkedStack& operator=(const LinkedStack&) = delete;
};
int main() {
    LinkedStack<string> stack;
    stack.push("C++");
    stack.push("Java");
    stack.push("Python");
    stack.print();  
    cout << "栈顶元素：" << stack.top() << endl;  
    stack.pop();
    cout << "栈大小：" << stack.size() << endl;                        
    cout << "栈是否为空：" << (stack.isEmpty() ? "是" : "否") << endl;  
    stack.clear();
    return 0;
}

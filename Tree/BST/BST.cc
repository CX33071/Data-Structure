#include <cassert>
#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BSTree {
   private:
    struct BSTNode {
        T data;
        BSTNode* left;
        BSTNode* right;
        BSTNode(T val) : data(val), left(nullptr), right(nullptr) {}
    };
    using Node = BSTNode<T>;
    Node* _root;  
    Node* _insert(Node* cur, T val) {
        if (cur == nullptr) {
            return new Node(val);
        }
        if (val < cur->data) {
            cur->left = _insert(cur->left, val);
        } else if (val > cur->data) {
            cur->right = _insert(cur->right, val);
        }
        return cur;
    }
    Node* _find(Node* cur, T val){
        if (cur == nullptr || cur->data == val) {
            return cur;
        }
        if (val < cur->data) {
            return _find(cur->left, val);
        } else {
            return _find(cur->right, val);
        }
    }
    Node* _erase(Node* cur, T val) {
        if (cur == nullptr)
            return nullptr;  
        if (val < cur->data) {
            cur->left = _erase(cur->left, val);
            return cur;
        } else if (val > cur->data) {
            cur->right = _erase(cur->right, val);
            return cur;
        }
        Node* temp = nullptr;
        if (cur->left == nullptr) {
            temp = cur->right;
            delete cur;  
            return temp;
        }
        else if (cur->right == nullptr) {
            temp = cur->left;
            delete cur;
            return temp;
        }
        else {
            Node* minNode = cur->right;
            while (minNode->left != nullptr) {
                minNode = minNode->left;
            }
            cur->data = minNode->data;
            cur->right = _erase(cur->right, minNode->data);
            return cur;
        }
    }
    void _inOrder(Node* cur){  
        if (cur == nullptr)
            return;
        _inOrder(cur->left);
        cout << cur->data << " ";
        _inOrder(cur->right);
    }
    void _levelOrder(Node* cur) {  
        if (cur == nullptr)
            return;
        queue<Node*> q;
        q.push(cur);
        while (!q.empty()) {
            Node* front = q.front();
            q.pop();
            cout << front->data << " ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
    void _clear(Node* cur) { 
        if (cur == nullptr)
            return;
        _clear(cur->left);
        _clear(cur->right);
        delete cur;
    }
   public:
    BSTree() : _root(nullptr) {}
    ~BSTree() {
        _clear(_root);
        _root = nullptr;
    }
    BSTree(const BSTree&) = delete;
    BSTree& operator=(const BSTree&) = delete;
    void insert(T val) { _root = _insert(_root, val); }
    bool find(T val){ return _find(_root, val) != nullptr; }
    void erase(T val) {
        assert(_root != nullptr); 
        _root = _erase(_root, val);
    }
    void inOrder(){  
        cout << "中序遍历：";
        _inOrder(_root);
        cout << endl;
    }
    void levelOrder(){  
        cout << "层序遍历：";
        _levelOrder(_root);
        cout << endl;
    }
    void clear() {
        _clear(_root);
        _root = nullptr;
    }
};

#include <iostream>
#include <queue>  
using namespace std;
template <typename T>
class BinaryTree {
   private:
    struct BTNode {
        T data;
        BTNode* left;
        BTNode* right;
        BTNode(T val) : data(val), left(nullptr), right(nullptr) {}
    };
    using Node = BTNode<T>;  
    Node* _root;            
    void _preOrder(Node* cur){
        if (cur == nullptr)
            return;                
        cout << cur->data << " "; 
        _preOrder(cur->left);      
        _preOrder(cur->right);   
    }
    void _inOrder(Node* cur){
        if (cur == nullptr)
            return;
        _inOrder(cur->left);     
        cout << cur->data << " ";  
        _inOrder(cur->right);      
    }
    void _postOrder(Node* cur){
        if (cur == nullptr)
            return;
        _postOrder(cur->left);    
        _postOrder(cur->right);    
        cout << cur->data << " "; 
    }
    int _getNodeCount(Node* cur){
        if (cur == nullptr)
            return 0;
        return _getNodeCount(cur->left) + _getNodeCount(cur->right) + 1;
    }
    int _getHeight(Node* cur){
        if (cur == nullptr)
            return 0;  
        int leftH = _getHeight(cur->left);
        int rightH = _getHeight(cur->right);
        return (leftH > rightH ? leftH : rightH) + 1;
    }
    void _clear(Node* cur) {
        if (cur == nullptr)
            return;
        _clear(cur->left);  
        _clear(cur->right);  
        delete cur;         
    }
   public:
    BinaryTree() : _root(nullptr) {}
    ~BinaryTree() {
        _clear(_root);
        _root = nullptr;
    }
    BinaryTree(const BinaryTree&) = delete;
    BinaryTree& operator=(const BinaryTree&) = delete;
    void setRoot(T val) { _root = new Node(val); }
    void addLeft(Node* parent, T val) {
        if (parent == nullptr)
            return;
        parent->left = new Node(val);
    }
    void addRight(Node* parent, T val) {
        if (parent == nullptr)
            return;
        parent->right = new Node(val);
    }
    void preOrder(){
        cout << "前序遍历：";
        _preOrder(_root);
        cout << endl;
    }
    void inOrder(){
        cout << "中序遍历：";
        _inOrder(_root);
        cout << endl;
    }
    void postOrder(){
        cout << "后序遍历：";
        _postOrder(_root);
        cout << endl;
    }
    void levelOrder(){
        cout << "层序遍历：";
        _levelOrder(_root);
        cout << endl;
    }
    int getNodeCount(){ return _getNodeCount(_root); }
    int getHeight(){ return _getHeight(_root); }

    void clear() {
        _clear(_root);
        _root = nullptr;
    }
};

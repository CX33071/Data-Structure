#include <iostream>
#include <string>
#include <utility>  // 用于pair键值对
using namespace std;
template <typename Key, typename Value>
class HashTable {
   private:
    struct HashNode {
        pair<Key, Value> kv;
        HashNode* next;
        HashNode(Key k, Value v) : kv(k, v), next(nullptr) {}
    };
    using Node = HashNode<Key, Value>; 
    // typedef HashNode<Key, Value> Node;
    Node** _hashTable;                  
    int _capacity;                    
    int _size;                         
     _loadFactor = 0.75;   
    // 哈希函数1：处理整型Key
    int getHash(int key) {
        return (key % _capacity + _capacity) % _capacity;
    }
    // 哈希函数2：处理字符串Key
    int getHash(string key) {
        unsigned int hash = 0;
        for (char c : key) {
            hash = hash * 31 + c;  
        }
        return hash % _capacity;
    }
    void expand() {
        int newCap = _capacity * 2 + 1;
        Node** newTable = new Node*[newCap]();  
        for (int i = 0; i < _capacity; ++i) {
            Node* cur = _hashTable[i];
            while (cur != nullptr) {
                Node* nextNode = cur->next; 
                int newIdx = getHash(cur->kv.first);
                cur->next = newTable[newIdx];
                newTable[newIdx] = cur;
                cur = nextNode;
            }
        }
        delete[] _hashTable;
        _hashTable = newTable;
        _capacity = newCap;
        cout << "原容量：" << (_capacity - 1) / 2 << " 新容量："
             << _capacity << endl;
    }
    Node* findPrevNode(Key key, int idx){
        idx = getHash(key);  
        Node* prev = nullptr;
        Node* cur = _hashTable[idx];
        while (cur != nullptr && cur->kv.first != key) {
            prev = cur;
            cur = cur->next;
        }
        return prev;
    }
   public:
    HashTable(int initCap = 11) : _capacity(initCap), _size(0) {
        _hashTable = new Node*[_capacity]();
    }
    ~HashTable() {
        for (int i = 0; i < _capacity; ++i) {
            Node* cur = _hashTable[i];
            while (cur != nullptr) {
                Node* temp = cur;
                cur = cur->next;
                delete temp;
            }
        }
        delete[] _hashTable;
        _hashTable = nullptr;
        _capacity = _size = 0;
    }
    HashTable(const HashTable&) = delete;
    HashTable& operator=(const HashTable&) = delete;
    //Key存在则更新Value，不存在则插入
    void insert(Key key, Value val) {
        if (_size * 1.0 / _capacity > _loadFactor) {
            expand();
        }
        int idx = 0;
        Node* prev = findPrevNode(key, idx);
        Node* target = prev == nullptr ? _hashTable[idx] : prev->next;
        if (target != nullptr) {
            target->kv.second = val;
            return;
        }
        Node* newNode = new Node(key, val);
        newNode->next = _hashTable[idx];
        _hashTable[idx] = newNode;
        _size++;
    }
    Value find(Key key) {
        int idx = getHash(key);
        Node* cur = _hashTable[idx];
        while (cur != nullptr && cur->kv.first != key) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            cout << "不存在" << endl;
        }
        return cur->kv.second;  
    }
    void erase(Key key) {
        int idx = 0;
        Node* prev = findPrevNode(key, idx);
        Node* target = prev == nullptr ? _hashTable[idx] : prev->next;
        if (target == nullptr) {
            return;
        }
        if (prev == nullptr) {
            _hashTable[idx] = target->next; 
        } else {
            prev->next = target->next; 
        }
        delete target;
        _size--;
    }
    bool isEmpty() { return _size == 0; }
    int size() { return _size; }
    int capacity() { return _capacity; }
    void clear() {
        for (int i = 0; i < _capacity; ++i) {
            Node* cur = _hashTable[i];
            while (cur != nullptr) {
                Node* temp = cur;
                cur = cur->next;
                delete temp;
            }
            _hashTable[i] = nullptr;  
        }
        _size = 0;
    }
};

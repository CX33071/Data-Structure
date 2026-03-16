#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int a[1001];
int main(){
    int n = 3;//先定义数组长度
    a[0] = 3;
    a[1] = 1;
    a[2] = 4;
    //1.普通数组排序
    sort(a, a + n);//升序
    sort(a, a + n, greater<int>());//降序
    //2.结构体排序
    struct Node{
        int x, y;
        bool operator<(const Node& b){//重载<运算符函数，按x升序，x相同按y降序
            if(x!=b.x){
                return x<b.x;
            }
            return y > b.y;
        }
    };
    Node nodes[1000];
    sort(nodes, nodes + n);
    //3.自定义函数排序
    sort(a, a + n, cmp);//自定义不可出现在main函数
}
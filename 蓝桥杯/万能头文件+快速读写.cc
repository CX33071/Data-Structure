#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            f = -1;
        }
        ch = getchar();
    }
    while(ch>='0'&&ch<='9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x = -x;
    }
    if(x>9){
        write(x / 10);
    }
    putchar(x % 10 + '0');
}
int main(){
    ios::sync_with_stdio(
        false);  // 关闭 C++ 的cin/cout和C语言的scanf/printf之间的同步，让cin/cout的速度大幅提升（接近scanf/printf）,默认情况下cin/cout为了兼容 C语言的输入输出，速度很慢，处理大数据时会超时，这行是必加的优化。
    cin.tie(0);  // 解绑cin和cout的关联,默认情况下，每次用cin读取数据前，会先刷新cout的缓冲区（把cout里的内容输出），解绑后可以避免这个额外操作，进一步加速输入输出
    //...
    return 0;
}
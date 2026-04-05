//返回结果：把子问题的结果组合起来
//循环比递归块,千万要清楚终止条件
//阶乘
int factorial(int n){
    if(n==0||n==1){
        return 1;
    }
    return n * factorial(n - 1);
}
// 斐波那契数列,递归会重复计算，超时
int fib(int n){
    if(n==0||n==1){
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
//不超时
int fib(int n){
    long long a = 0, b = 1;
    for (int i = 2; i <= n;++i){
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}
//记忆化搜索，解决重复计算
int mem[100] = {-1};
int fib(int n){
    if(n==0||n==1){
        return n;
    }
    if(mem[n]!=-1){
        return mem[n];
    }
    mem[n] = fib(n - 1) + fib(n - 2);
    return mem[n];
}
// 最大公约数
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b, a % b);
}
//汉诺塔
#include <iostream>
void hanoi(int n,char from,char mid,char to){
    if(n==1){
        std::cout << from << "->" << to << std::endl;
        return;
    }
    hanoi(n - 1, from, to, mid);
    hanoi(1, from, mid, to);
    hanoi(n-1,mid, from, to);
}
//快速幂
int fastpow(int a,int n){
    if(n==0){
        return 1;
    }
    int half = fastpow(a, n / 2);
    if(n%2==0){
        return half * half;
    }else{
        return half * half * a;
    }
}
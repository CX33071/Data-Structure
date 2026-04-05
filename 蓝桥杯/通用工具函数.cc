#include <bits/stdc++.h>
//交换两个数
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
//最大公约数
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b, a % b);
}
//最小公倍数
int lcm(int a,int b){
    return a * b / gcd(a, b);
}
//判断数字是否包含某一位
bool has(int x,int tar){
    if(x==0){
        return tar == 0;
    }
    while(x){
        if(x%10==tar){
            return true;
        }
        x /= 10;
    }
    return false;
}
//数字各位之和
int sum_digit(int x){
    int sum = 0;
    while(x){
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}
//回文数
bool is_pali(int x){
    int t = 0;
    int tmp = x;
    while(tmp){
        t = t * 10 + tmp % 10;
        tmp /= 10;
    }
    return x == t;
}
//闰年判断
bool is_leap(int y){
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
//快速幂
//位运算更快、先取模、long long
long long quick_pow(long long a,long long b,long long mod_num){
    long long res = 1;
    a %= mod_num;
    while(b){
        if(b&1){
            res = res * a % mod_num;
        }
        a = a * a % mod_num;
        b >>= 1;
    }
    return res;
}
long long qpow(long long a,long long b){
    int res = 1;
    while(b){
        if(b&1){
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
// 快速幂求逆元：前提：mod是质数，逆元 = a^(mod-2) % mod（费马小定理）
// 素数筛(埃氏筛)找1~n的素数
bool is_prime[100000];
void get_prime(int n){
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n;i++){
        if(is_prime[i]){//i是质数，筛掉它的所有倍数
            for (int j = i * i; j <= n;j+=i){
                is_prime[j] = false;
            }
        }
    }
}
//单个数字判断质数
bool is_prime2(int n){
    if(n<2){
        return false;
    }
    if(n==2){
        return true;
    }
    if(n%2==0){
        return false;
    }
    for (long long i = 3; i * i <= n;i+=2){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
//分解质因数，把一个数拆成质因数乘积
void prime_factor(long long n){
    for (long long i = 2; i * i <= n;i++){

    }
}

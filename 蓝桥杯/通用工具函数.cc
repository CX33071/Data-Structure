
#include <bits/stdc++.h>
//交换两个数
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
//最大公约数，分数约分时可以用
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b, a % b);
}
//最大公约数迭代写法，防止递归爆栈
int gcd(int a,int b){
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
//最小公倍数
int lcm(int a,int b){
    return a * b / gcd(a, b);
    // return a/gcd(a,b)*b;先除再乘避免溢出
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
std::vector<std::pair<int,int>> factorize(int n){
    std::vector<std::pair<int, int>> factors;
    for (int i = 2; i * i <= n;i++){
        if(n%i==0){
            int count = 0;
            while(n%i==0){
                n /= i;
                count++;
            }
            factors.emplace_back(i, count);
        }
    }
    if(n>1){
        factors.emplace_back(n, 1);
    }
    return factors;
}
#include <math.h>
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int other = n / i;
            printf("%d\n", (i > other) ? i : other);
            return 0;
        }
    }
    return 0;
}
//组合数
long long C(int n,int m){
    if(m<0||m>n){
        return 0;
    }
    long long ret = 1;
    for (int i = 1; i <= m;i++){
        ret = ret * (n - m + i) / i;
    }
    return ret;
}
//递推组合数
long long Carry[100][100];
void initc(int n){
    for (int i = 0; i <= n;i++){
        Carry[i][0] = Carry[i][i] = 1;
        for (int j = 1; j < i;j++){
            Carry[i][j] = Carry[i - 1][j - 1] + Carry[i - 1][j];
        }
    }
}
//排列数A(n,m)=n!/(n-m)!
long long A(int n,int m){
    long long ret = 1;
    for (int i = 0; i < m;i++){
        ret *= (n - i);
    }
    return ret;
}
//整除性质：一个数能被3整除=各位数字之和能被3整除
        //   一个数能被9整除=各位数字之和能被9整除
        //   一个数能被11整除=奇数位和-偶数位和能被11整除
//千万注意溢出：long long
//负数取模，要想取模不为负，先加模再取模
// int ret = (x % mod + mod) % mod;
//for里不写sqrt(n)，效率低
//高精度加法
#include <bits/stdc++.h>
using namespace std;
vector<int> add(vector<int> a, vector<int> b) {
    int t = 0;
    vector<int> ret;
    for (int i = 0; i < a.size() || i < b.size() || t;i++){
        if(i<a.size()){
            t += a[i];
        }
        if(i<b.size()){
            t += b.size();
        }
        ret.push_back(t % 10);
        t /= 10;
    }
}
// num.insert(num.begin(),k,0);10的k此方
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a;
    vector<int> b;
    for (int i = s1.size() - 1; i >= 0; i--) {
        a.push_back(s1[i] - '0');
    }
    for (int i = s2.size() - 1; i >= 0;i--){
        b.push_back(s2[i] - '0');
    }
    vector<int> ret = add(a,b);
    for (int i = ret.size(); i >= 0;i--){
        cout << ret[i];
    }
    return 0;
}
//回文质数
#include <math.h>
#include <stdio.h>

// 判断质数
int isPrime(int num) {
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
        return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

// 判断回文数（正确版）
int isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

// 获取数字位数
int getLen(int num) {
    int cnt = 0;
    while (num > 0) {
        cnt++;
        num /= 10;
    }
    return cnt;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i++) {
        // 核心优化：除了11，偶数位回文数一定不是质数，直接跳过
        int len = getLen(i);
        if (len % 2 == 0 && i != 11) {
            // 跳过 2/4/6/8 位数（除11外）
            continue;
        }

        if (isPalindrome(i) && isPrime(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
//次方用pow(10,6),开方用sqrt
//杨辉三角
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int Carry[30][30];
    for (int i = 0; i < n; i++) {
        Carry[i][0] = Carry[i][i] = 1;
        for (int j = 1; j < i; j++) {
            Carry[i][j] = Carry[i - 1][j - 1] + Carry[i - 1][j];
        }
        for (int j = 0; j <= i; j++) {
            cout << Carry[i][j] << " ";
        }
        cout << '\n';
    }
}
// 回文质数：#include <stdio.h>
#include <math.h>

// 判断质数
int isPrime(int num) {
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
        return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

// 判断回文数（正确版）
int isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

// 获取数字位数
int getLen(int num) {
    int cnt = 0;
    while (num > 0) {
        cnt++;
        num /= 10;
    }
    return cnt;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i++) {
        // 核心优化：除了11，偶数位回文数一定不是质数，直接跳过
        int len = getLen(i);
        if (len % 2 == 0 && i != 11) {
            // 跳过 2/4/6/8 位数（除11外）
            continue;
        }

        if (isPalindrome(i) && isPrime(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}

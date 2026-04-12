
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
            t += b[i];
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
//高精度加法
vector<int> add(vector<int> a,vector<int> b){
    vector<int> ret;
    int t = 0;
    for (int i = 0; i < a.size() || i < b.size() || t;i++){
        if(i<a.size()){
            t += a[i];
        }
        if(i<b.size()){
            t += b[i];
        }
        ret.push_back(t % 10);
        t /= 10;
    }
    return ret;
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    vector<int>a,b;
    for (int i = s1.size() - 1; i >= 0;i--){
        a.push_back(s1[i] - '0');
    }
    for (int i = s2.size() - 1; i >= 0;i--){
        b.push_back(s2[i] - '0');
    }
    vector<int> ret=add(a, b);
    for (int i = ret.size() - 1; i >= 0;i--){
        cout << ret[i];
    }
        return 0;
}
//高精度减法
bool cmp(vector<int> a,vector<int> b){
    if(a.size()>b.size()){
        return true;
    }else if(a.size()<b.size()){
        return false;
    }else{
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > b[i]) {
                return true;
            } else {
                return false;
            }
        }
    }
}
vector<int> sub(vector<int> a,vector<int> b){
    vector<int> ret;
    int t = 0;
    for (int i = 0; i < a.size();i++){
        t = a[i] - t;
        if(i<b.size()){
            t -= b[i];
        }
        ret.push_back((t + 10) % 10);
        if(t<0){
            t = 1;
        }else{
            t = 0;
        }
    }
    while(ret.size()>1&&ret.back()==0){
        ret.pop_back();
    }
    return ret;
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a, b;
    for (int i = s1.size() - 1; i >= 0;i--){
        a.push_back(s1[i] - '0');
    }
    for (int i = s2.size() - 1; i >= 0;i--){
        b.push_back(s2[i] - '0');
    }
    vector<int> c;
    if (cmp(a, b)) {
        c = sub(a, b);
    }else{
        c = sub(b, a);
        cout << '-';
    }
    for (int i = c.size() - 1; i >= 0;i--){
        cout << c[i];
    }
}
//高精度乘法
vector<int> cheng(vector<int> a,int b){
    vector<int> ret;
    long long t;
    for (int i = 0; i < a.size() || t;i++){
        if(i<a.size()){
            t += (long long)a[i] * b;
        }
        ret.push_back(t % 10);
        t /= 10;
    }
    while(ret.size()>1&&ret.back()==0){
        ret.pop_back();
    }
    return ret;
}
int main(){
    string s;
    int b;
    cin >> s >> b;
    vector<int> a;
    for (int i = s.size() - 1; i >= 0;i--){
        a.push_back(s[i] - '0');
    }
    vector<int> ret=cheng(a, b);
    for (int i = ret.size() - 1; i >= 0;i--){
        cout << ret[i];
    }
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
//dfs全排列
bool a[10];
int b[10];
int n;
void dfs(int u) {
    if(u==n){
        for (int i = 0; i < n;i++){
            cout << b[i] << ' ';
        }
        return;
    }
    for (int i = 1; i <= n;i++){
        if(!a[i]){
            a[i] = 1;
            b[u] = i;
            dfs(u + 1);
            a[i] = 0;
        }
    }
}
int main(){
    cin >> n;
    dfs(0);
}
//不用回溯
int a[10];
int k;
void dfs(int u,int start){

}
int main(){
    k = 5;
    dfs(0, 1);
}
//dfs子集枚举
vector<int> v1(3, 0);
vector<int> nums = {1, 2, 3};
vector<int> v2;
void dfs(int u){
    if(u==nums.size()){
        for (int i = 0; i < v2.size();i++){
            cout << v2[i];
        }
        return;
    }
    for (int i = 0; i < nums.size();i++){
        if(!v1[i]){
            v1[i] = 1;
            v2.push_back(nums[i]);
            dfs(u + 1);
            v1[i] = 0;
        }
    }
}
// dfs走迷宫
// dfs输出每条路：vector<pair<int,int>> path;path.push_back({nx,ny});
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
char maze[N][N];//路，能走吗
bool vis[N][N];//标记已访问
int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool dfs(int x,int y,int targetx,int targety){
    if(x<0||x>n-1||y<0||y>n-1||maze[x][y]=='1'||vis[x][y]){
        return false;
    }
    if(x==targetx&&y==targety){
        return true;
    }
    vis[x][y] = true;
    for (int i = 0; i < 4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(dfs(nx,ny,targetx,targety)){
            return true;
        }
    }
    // vis[x][y]=false;判断一条路，不用回溯
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            maze[i][j] = s[j];
        }
    }

    int a, b, h, l;
    cin >> a >> b >> h >> l;
    // 起点或终点不可通行
    if (maze[a][b] == '1' || maze[h][l] == '1') {
        cout << "NO" << endl;
        return 0;
    }
    // 初始化访问标记
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vis[i][j] = false;
        }
    }
    if (dfs(a, b, h, l)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
//BFS不需要回溯
//迷宫求最短路径:左上角到右下角
const int N = 45;
char maze[N][N];
bool vis[N][N];
int R;
int D;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct point{
    int x, y, step;
};
int bfs() {
    queue<point> q;
    q.push({1, 1, 1});
    vis[1][1] = true;
    while(!q.empty()){
        point cur = q.front();
        q.pop();
        if(cur.x==R&&cur.y==D){
            return cur.step;
        }
        for (int i = 0; i < 4;i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx >= 1 && nx <= R && ny >= 1 && ny <= D && !vis[nx][ny] &&
                maze[nx][ny] == '.') {
                vis[nx][ny] = true;
                q.push({nx, ny, cur.step + 1});
            }
        }
    }
    return -1;
}
int main() {
    cin >> R >> D;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= D; j++) {
            cin >> maze[i][j];
        }
    }

    int ans = bfs();
    cout << ans << endl;

    return 0;
}
//全排列
vector<vector<int>> ret;
vector<bool> used;
vector<int> nums;
vector<int> path;
void dfs(vector<int> nums) {
    if(path.size()==nums.size()){
        ret.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size();i++){
        if(!used[i]){
            used[i] = true;
            path.push_back(used[i]);
            dfs(nums);
            path.pop_back();
            used[i] = false;
        }
    }
}
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        nums[i - 1] = i;
    }
    used.resize(n, false);
    dfs(nums);
    cout << ret.size();
}
//2-36进制转10进制
int change(string num,int base){
    return stoi(num, nullptr, base);//若数字较大建议用stoll
}
int change1(string num,int base){
    long long ret = 0;
    for(char c:num){
        int digit;
        if(c>='0'&&c<='9')digit = c - '0';
        else if(c>='A'&&c<='Z')digit = c - 'A' + 10;
        else if(c>='a'&&c<='z')digit = c - 'a' + 10;
        else continue;
        ret = ret * base + digit;
    }
    return ret;
}
//10进制转其他
string change(long long num,int base){
    string ret;
    if(num==0){
        return "0";
    }
    while(num>0){
        int digit = num % base;
        if(digit<10){
            ret += (char)('0' + digit);
        }else{
            ret += char('A' + digit - 10);
        }
        num /= base;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
//前缀和
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<int> prefix(n, 0);
    for (int i = 1; i <= n;i++){
        prefix[i] = prefix[i - 1] + a[i - 1];
    }
    int l, r;
    cin >> l >> r;
    int sum = prefix[r + 1] - prefix[l];//+1左右边界都包括
}
//二维前缀和
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n;i++){
        for (int j = 0;j<m;j++){
            cin >> a[i][j];
        }
    }
    //前缀和大小为((n+1)*(m+1))
    vector<vector<int>> prefix(n+1, vector<int>(m+1,0));
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] -
                           prefix[i - 1][j - 1] + a[i - 1][j - 1];
        }
    }
    int u, v, l, r;
    cin >> u >> v >> l >> r;
    int sum = prefix[l + 1][r + 1] - prefix[l + 1][v] - prefix[u][r + 1] +
              prefix[u][v];
    cout << sum;
}
//不定长滑动窗口
int count(string s){
    unordered_set<char> w;
    int max = 0;
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
        while(w.count(s[right])){
            w.erase(s[left]);
            left++;
        }
        w.insert(s[right]);
        max = max > (right - left + 1) ? max : (right - left + 1);
    }
    return max;
}
// 注意滑动窗口用set和map的不同
// 汉诺塔
#include <iostream>
void hanoi(int n, char from, char mid, char to) {
    if (n == 1) {
        std::cout << from << "->" << to << std::endl;
        return;
    }
    hanoi(n - 1, from, to, mid);
    hanoi(1, from, mid, to);
    hanoi(n - 1, mid, from, to);
}
// 快速幂
int fastpow(int a, int n) {
    if (n == 0) {
        return 1;
    }
    int half = fastpow(a, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return half * half * a;
    }
}
33.先反转再去0, if ((idx = s.find('.')) != string::npos) {
    string zhengshu = s.substr(0, idx);
    string xiaoshu = s.substr(idx + 1);

    reverse(zhengshu.begin(), zhengshu.end());
    reverse(xiaoshu.begin(), xiaoshu.end());

    while (zhengshu.size() > 1 && zhengshu[0] == '0')
        zhengshu.erase(zhengshu.begin());
    while (xiaoshu.size() > 1 && xiaoshu.back() == '0')
        xiaoshu.pop_back();
36.找多个答案中的最小答案时，刚开始就从最小开始试 for (int num = 4;
                                                           num <= n; num += 2) {
        // 找第一个最小的质数 a，使得 num - a 也是质数
        for (int a = 2; a <= num / 2; a++) {
            int b = num - a;
            if (isPrime(a) && isPrime(b)) {
                // 找到就输出，立刻退出，保证第一个最小
                cout << num << "=" << a << "+" << b << endl;
                break;
            }
        }
    }
    41.dfs void dfs(当前状态) {
        // 1. 终止条件：找到答案或无法继续
        if (满足结束条件) {
            // 处理结果
            return;
        }

        // 2. 遍历所有可能的选择
        for (所有可选方案) {
            // 3. 做出选择
            if (该选择合法) {
                // 标记已访问
                visited[下一步] = true;
                // 4. 递归进入下一步
                dfs(下一步的状态);
                // 5. 撤销选择（回溯）
                visited[下一步] = false;
            }
        }
    }
    43.弧度制：double angle1 = atan2(y, x);
    计算角度：double angle2 = atan2(y, x) * 180 / M_PI;
//日期
#include <bits/stdc++.h>
    using namespace std;

    // 平年每月的天数，days[0] 为占位符
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 1. 判断闰年
    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // 2. 获取某年某月的天数
    int getDays(int y, int m) {
        if (m == 2)
            return days[m] + isLeapYear(y);
        return days[m];
    }

    // 3. 判断日期是否合法
    bool isValidDate(int y, int m, int d) {
        if (y < 0 || m < 1 || m > 12)
            return false;
        if (d < 1 || d > getDays(y, m))
            return false;
        return true;
    }

    // 4. 计算两个日期之间相隔的天数（y2>y1）
    int dateDiff(int y1, int m1, int d1, int y2, int m2, int d2) {
        int daysCount = 0;
        // 累加年份
        for (int i = y1; i < y2; i++) {
            daysCount += 365 + isLeapYear(i);
        }
        // 累加月份
        for (int i = 1; i < m1; i++)
            daysCount -= getDays(y1, i);
        daysCount -= d1;
        for (int i = 1; i < m2; i++)
            daysCount += getDays(y2, i);
        daysCount += d2;
        return daysCount;
    }

    // 5. 求N天后的日期
    void addDays(int y, int m, int d, int n, int& ny, int& nm, int& nd) {
        ny = y, nm = m, nd = d + n;
        while (nd > getDays(ny, nm)) {
            nd -= getDays(ny, nm);
            nm++;
            if (nm > 12)
                ny++, nm = 1;
        }
    }
    // 检查是否是合法日期
    bool check(int y, int m, int d) {
        if (m < 1 || m > 12)
            return false;
        if (d < 1)
            return false;
        if (m == 2) {
            int leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
            return d <= 28 + leap;
        }
        return d <= days[m];
    }
    //滑动窗口可变长度模板
    int left = 0;
    for (int right = 0; right < n; right++) {
        // 1. 将right元素加入窗口（扩展）

        // 2. 当窗口不满足条件时，收缩left
        while (窗口不满足条件 && left <= right) {
            // 移除left位置的元素
            left++;
        }

        // 3. 此时窗口满足条件，更新答案
        ans = max(ans, right - left + 1);
    }
    // 给定一个长度为N的数组A和整数K，求所有长度大于等于K的连续子数组的最大平均值。结果四舍五入保留3位小数
#include <iomanip>
#include <iostream>
#include <vector>
    using namespace std;

    int main() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // 前缀和
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + a[i];
        }

        double maxAvg = -1e9;
        for (int len = k; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                long long sum = prefix[i + len] - prefix[i];
                double avg = (double)sum / len;
                if (avg > maxAvg)
                    maxAvg = avg;
            }
        }

        cout << fixed << setprecision(3) << maxAvg;
        return 0;
    }
//查找左边界
    int lowerBound(vector<int> & nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = nums.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
//查找右边界
    int upperBound(vector<int> & nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    // 二分答案求满足条件最小值
    //  找最小的x，使得check(x)为真
    int binarySearchMin() {
        int left = minVal, right = maxVal;
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                ans = mid;
                right = mid - 1;  // 尝试更小的
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    // 最大值
    //  找最大的x，使得check(x)为真
    int binarySearchMax() {
        int left = minVal, right = maxVal;
        int ans = left;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                ans = mid;
                left = mid + 1;  // 尝试更大的
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    // 木材加工（经典二分答案）题目：有N根木材，长度分别为L₁₂, ...,Lₙ。要切成K根长度相同的小段，求最大能切成的长度（整数）
#include <iostream>
#include <vector>
    using namespace std;

    vector<int> woods;
    int n, k;

    bool check(int len) {
        if (len == 0)
            return true;
        int cnt = 0;
        for (int w : woods) {
            cnt += w / len;
        }
        return cnt >= k;
    }

    int main() {
        cin >> n >> k;
        woods.resize(n);
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            cin >> woods[i];
            maxLen = max(maxLen, woods[i]);
        }

        int left = 1, right = maxLen;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                ans = mid;
                left = mid + 1;  // 尝试更大的长度
            } else {
                right = mid - 1;
            }
        }
        cout << ans << endl;
        return 0;
    }
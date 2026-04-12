#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}
int binartsearch(vector<int> a,int target){
    int left = 0;
    int right = a.size() - 1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(a[mid]==target){
            return mid;
        }else if(a[mid]>target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}
vector<int> a;
auto it = lower_bound(a.begin(),a.end(),4);
int idx = it - a.begin();
auto it = upper_bound(a.begin(), a.end(), 4);
int b[5];
int* p = upper_bound(b, b + 5, 4);
bool check(int n){

}
int minboard;
int maxboard;
int binarysearch() {
    int ret;
    int left = minboard;
    int right = maxboard;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(check(mid)){
            ret = mid;
            int left = mid + 1;
            // int right=mid-1;
        }else{
            //
        }
    }
    return ret;
}
int first(vector<int>a,int target){
    auto it = lower_bound(a.begin(), a.end(), target);
    if(it==a.begin()){
        return *it;
    }else if(it==a.end()){
        return *(it - 1);
    }else{
        if(abs(*it-target)<abs(*(it-1)-target)){
            return *it;
        }else{
            return *(it - 1);
        }
    }
}
int main(){
    unordered_set<int> s;
    s.insert(5);
    if(s.count(5)){

    }
    s.erase(5);
    s.size();
    s.empty();
    for(int x:s){
        cout << x;
    }
    unordered_set<int> s1;
    vector<int> v = {1, 8, 3, 3, 37, 5, 5, 6, 7, 8};
    for(int d:v){
        s1.insert(d);
    }
    cout << s1.size();
    unordered_map<int, string> mp;
    mp[1] = "apple";
    mp[2] = "pol";
    for(auto p:mp){
        cout << p.first << ' ' << p.second << '\n';
    }
}
int sqrt(int n){
    int left = 0;
    int right=n;
    int ret;
    while (left<=right){
        long long mid = left + (right - left) / 2;
        if(mid*mid<=n){
            ret = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return ret;
}
int sqrt(int n){
    int left = 0;
    int right = n;
    int ret;
    while(left<=right){
        long long mid = left + (right - left) / 2;
        if(mid*mid<=n){
            ret = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return ret;
}
int maxsearch(vector<int> a){
    int left = 0;
    int right = a.size() - 1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(a[mid]<a[mid+1]){
            left = mid + 1;
        }else{
            right = mid ;
        }
    }
    return left;
}
struct student{
    string name;
    int score;
};
bool cmp(student a,student b){
    if(a.score!=b.score){
        return a.score > b.score;
    }else{
        return a.name < b.name;
    }
}
int main() {
    map<int, int> mp;
    mp.insert({1, 3});
    if(mp.find(1)!=mp.end()){

    }
    for (auto it = mp.begin(); it != mp.end();it++) {
        if(it->second==0){
            it = mp.erase(it);
        }else{
            it++;
        }
    }
    set<int, greater<int>> s2;
    auto it = s2.lower_bound(5);
    auto begin = s2.lower_bound(3);
    auto end = s2.upper_bound(7);
    for (auto it = begin; it != end;it++){
        cout << *it;
    }
    multiset<int> ms;
    ms.insert(3);
    ms.insert(3);
    cout << ms.count(3);
    ms.erase(3);
    ms.erase(ms.find(3));
    int n;
    int a1[n];
    sort(a1, a1 + n, greater<int>());
    sort(a.begin(), a.end());
    student stu[100];
    sort(stu, stu + 100, cmp);
}
void bubblesrt(int a[],int n){
    for (int i = 0; i < n - 1;i++){
        for (int j = 0; j < n - 1 - i;j++){
            if(a[j]<a[j+1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void selectsort(int a[],int n){
    int minidx;
    for (int i = 0; i < n - 1;i++){
        minidx = i;
        for (int j = i + 1; j < n;j++){
            if(a[j]<a[minidx]){
                minidx = j;
            }
        }
        swap(a[i], a[minidx]);
    }
}
void insertsort(int a[],int n){
    for (int i = 1; i < n;i++){
        int key = a[i];
        int j = i - 1;
        while(j>=0&&a[j]>key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void insertsort(int a[],int n){
    for (int i = 1; i < n;i++){
        int key = a[i];
        int j = i - 1;
        while(j>=0&&a[j]>key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int a[100];
int temp[100];
void merge(int left,int mid,int right){
    int i = left;
    int j = mid + 1;
    int k = 0;
    while(i<=mid&&j<=right){
        if(a[i]<a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=right){
        temp[k++] = a[j++];
    }
    for (int i = left,j=0; i <= right;i++,j++){
        a[i] = temp[j];
    }
}
void mergesort(int left,int right){
    if(left>=right){
        return;
    }
    int mid = left + (right - left) / 2;
    mergesort(left, mid);
    mergesort(mid + 1, right);
    merge(left, mid, right);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    char c;
    cin >> c;
    cin.ignore();
    getline(cin, s);
}
int factorial(int n){
    if(n==0||n==1){
        return 1;
    }
    return n * factorial(n - 1);
}
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b, a % b);
}
int gcd(int a,int b){
    while(b){
        int t=a%b;
        a = b;
        b = t;
    }
    return a;
}
int lcm(int a,int b){
    return a / gcd(a, b) * b;
}
int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int fib(int n){
    if(n==0||n==1){
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
int main(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    while(ss>>word){

    }
}
bool huiwen(string s){
    int i = 0;
    int j = s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main(){
int num;
string s;
char ch = (char)('0' + num);
int num = stoi("123");
char c = toupper('A');
reverse(s.begin(), s.end());
}
int main(){
    int N, K;
    cin >> N >> K;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    double sum = 0;
    for (int i = 0; i < K;i++){
        sum += A[i];
    }
    double av = sum / K;
    double max = av;
    for (int i = K; i < N;i++){
        
    }
}
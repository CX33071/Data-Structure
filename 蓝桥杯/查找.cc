#include <bits/stdc++.h>
// 线性查找	O(n)
// 二分查找	O(log n)    前提是有序数组
// lower_bound / upper_bound	O(log n)        前提是有序数组
// 哈希查找	O(1)
//二分查找
int binarysearch(int a[],int n,int target){
    int left = 0;
    int right = n - 1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(a[mid]==target){
            return mid;
        }else if(a[mid]<target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}
// C++内置二分函数
//  找第一个 ≥ target 的位置	lower_bound
//  找第一个 > target 的位置	upper_bound
//  找最后一个 < target 的位置	upper_bound - 1
//  找最后一个 ≤ target 的位置	upper_bound - 1
std::vector<int> v = {1, 2, 3, 4, 5};
auto it = std::lower_bound(v.begin(), v.end(), 4);
int num = *it;
int idx = it - v.begin();
//数组版
int a[]={1,2,3,4,5};
int* p = std::lower_bound(a, a + 5, 4);
int num = *p;
int idx = p - a;
//统计target出现的次数
int target = 0;
int count = std::upper_bound(v.begin(), v.end(), target) -
            std::lower_bound(v.begin(), v.end(), target);
//二分答案:求最优解，check
#define min 1
#define max 100
bool check(int x){

}
int binarysearch(){
    int left = min;
    int right = max;
    int ret = -1;
    while(left<=right){
        int mid = left + (right - left) / 2;
        if(check(mid)){
            ret = mid;
            // 找最大可行解：left=mid+1;
            // 找最小可行解：right=mid-1;
        }else{
            //
        }
    }
    return ret;
}
//在有序数组中找到最接近target的数字
int first(std::vector<int>& a,int target){
    auto it = std::lower_bound(a.begin(), a.end(), target);
    if(it==a.begin()){
        return *it;
    }
    if(it==a.end()){
        return *(it - 1);
    }
    if(abs(*it-target)<abs(*(it-1)-target)){
        return *it;
    }else{
        return *(it - 1);
    }
}
//unorder_set去重+快速存在性检查
//注意无序！
std::unordered_set<int> s;
int main(){
    s.insert(5);
    s.erase(5);
    s.count(5);//存在返回1,不存在0
    if(s.find(5)!=s.end()){

    }
    s.size();
    s.clear();
    s.empty();
    for(int x:s){
        std::cout << x;
    }
}
//unordered_set自动去重，重复元素只留一份
int main(){
    std::vector<int> a = {1, 1, 1, 2, 2, 3, 3, 6, 5};
    std::unordered_set<int> s;
    for(int x:a){
        s.insert(x);
    }
    //再转回vector
    std::vector<int> ret(s.begin(), s.end());
    //更短的写法
    std::unordered_set<int> s(a.begin(), a.end());
}
//保持原来顺序去重
int main(){
    std::vector<int> a = {1, 4, 2, 3, 3, 3, 7, 7, 6};
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}

//unordered_map(key-value哈希映射)
#define key 1
int main(){
std::unordered_map<int, std::string> mp;
std::unordered_map<std::string, int> cnt;
mp[123] = "abc";
cnt["apple"]++;
mp.find(key);
mp.erase(key);
mp.count(key);//是否存在
for(auto&p:mp){
    std::cout << p.first << " " << p.second;
}
}
//求平方根整数部分（二分答案）
int mysqrt(int x){
    int l = 0;
    int r = x;
    while(l<=r){
        long long mid = l + (r - l) / 2;
        if(mid*mid<=x){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return r;
}
//找峰值元素
int midsearch(std::vector<int>& a){
    int l = 0;
    int r = a.size() - 1;
    while(l<r){
        int mid = l + (r - l) / 2;
        if(a[mid]<a[mid+1]){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    return l;
}
//旋转有序数组找最小值
int findmin(std::vector<int>& a){
    int l = 0;
    int r = a.size() - 1;
    while(l<r){
        int mid = l + (r - l) / 2;
        if(a[mid]>a[r]){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    return a[l];
}
//如果想对unordered进行排序，需要倒进vector
std::unordered_map<int, int> mp;
std::vector<std::pair<int, int>> v(mp.begin(), mp.end());
// sort(v.begin(), v.end());
// sort(v.begin(), v.end(), [](auto a, auto b) { return a.second < b.second; });
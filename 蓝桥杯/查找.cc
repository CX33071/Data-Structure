#include <bits/stdc++.h>
using namespace std;  
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
//  找找第一个 ≥ target 的位置	lower_bound
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
// map
// 声明：map<string,int> mp;
// 插入：mp.insert({"apple",3});        mp["apple"]=5;
// 访问元素：如果key不存在，mp回自动创建该key,对应value为0:mp["apple"]
// 查找元素：if(mp.find("apple")!=mp.end()){cout<<mp["apple"];}避免意外创建
// 删除元素：mp.erase("apple");按key删除
// 遍历mp:for(auto& p:mp){cout<<p.first<<p.second;}
// 获取大小.size()清空.clear()
// 遍历时不要修改map结构,it失效
// 错误：遍历时删除元素
// for (auto it = mp.begin(); it != mp.end(); it++) {
//     if (it->second == 0) {
//         mp.erase(it);  // it 失效，程序崩溃
//     }
// }

// // 正确：
// for (auto it = mp.begin(); it != mp.end();) {
//     if (it->second == 0) {
//         it = mp.erase(it);  // erase 返回下一个迭代器
//     } else {
//         it++;
//     }
// }
// set
// 声明：set<int> s;    set<int,greater<int>> s2;降序
// 插入：s.insert(2);   s.insert(b.begin(),n.end());
// 遍历：for(int x:s){}
// 查找元素：if(s.find(5)!=s.end()){}
// 删除元素：删除值为5的元素：s.erase(5);删除第一个元素：s.erase(s.begin())
// s.empty(),s.size(),s.clear()
// 检查元素是否存在s.count(3)，存在返回1
// 求两个集合并集用set,3个set
int main() {
    set<int> s = {1, 3, 5, 7, 9};

    // lower_bound：返回第一个 ≥ x 的迭代器
    auto it1 = s.lower_bound(5);
    if (it1 != s.end()) {
        cout << "第一个 ≥ 5 的元素：" << *it1 << endl;  // 5
    }

    // upper_bound：返回第一个 > x 的迭代器
    auto it2 = s.upper_bound(5);
    if (it2 != s.end()) {
        cout << "第一个 > 5 的元素：" << *it2 << endl;  // 7
    }

    // 找出区间 [3, 7] 内的元素
    auto begin = s.lower_bound(3);
    auto end = s.upper_bound(7);

    cout << "区间 [3,7] 内的元素：";
    for (auto it = begin; it != end; it++) {
        cout << *it << " ";  // 3 5 7
    }
    cout << endl;

    multiset<int> ms;//允许重复元素

    ms.insert(3);
    ms.insert(3);
    ms.insert(5);

    cout << ms.size() << endl;  // 3（允许重复）

    // 统计某个值的个数
    cout << ms.count(3) << endl;  // 2

    // 删除一个元素（只删一个）
    ms.erase(ms.find(3));

    // 删除所有值为3的元素
    ms.erase(3);
    return 0;
}
// 不能修改set中的元素，先删除再插入
// 不能直接s.erase(it), 要it = s.erase(it);  
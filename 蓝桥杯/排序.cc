#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int a[1001];
int main(){
    int n = 3;  // 先定义数组长度sort(stu, stu + 100, cmp);
    a[0] = 3;
    a[1] = 1;
    a[2] = 4;
    //1.普通数组排序
    sort(a, a + n);//升序
    sort(a, a + n, greater<int>());//降序
    //2.对vector排序
    vector<int> v = {3, 1, 4, 1, 5};
    sort(v.begin(), v.end());
}
// 2.结构体排序
struct student {
    string name;
    int score;
    int id;
};
bool cmp2(student a, student b) {
    if (a.score != b.score) {
        return a.score > b.score;
    } else {
        return a.id < b.id;
    }
}
int main(){
student stu[100];
sort(stu, stu + 100, cmp2);
//3.lambda表达式
sort(stu, stu + 100, [](student a, student b) {
    if(a.score!=b.score){
        return a.score > b.score;
    }else {
        return a.id < b.id;
    }
});
//4.对string 排序
vector<string> words = {"banana", "apple", "cherry"};
sort(words.begin(), words.end());//字典序
sort(words.begin(), words.end(),
     [](string a, string b) { return a.size() < b.size(); });
}
//冒泡排序
void bubblesort(int a[],int n){
    for (int i = 0; i < n - 1;i++){
        for (int j = 0; j < n - 1 - i;j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
}
//选择排序
void selectionsort(int a[],int n){
    for (int i = 0; i < n - 1;i++){
        int minidx = i;
        for (int j = i + 1; j < n; j++) {
            if(a[j]<a[minidx]){
                minidx = j;
            }
        }
        swap(a[i], a[minidx]);
    }
}
//插入排序
void innsertionsort(int a[],int n){
    for (int i = 0; i < n;i++){
        int key = a[i];
        int j = i - 1;
        while(j>=0&&a[j]>key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

//稳定排序：相同元素按输入顺序输出:stable_sort()
// stable_sort(v.begin(), v.end(), cmp);
//部分排序：只找出前k个最小的元素：partial_sort()
//第k大的元素：nth_element()
//判断是否有序：is_sorted()
int main(){
vector<int> v = {1, 6, 2, 8, 4};
partial_sort(v.begin(), v.begin() + 3, v.end());
nth_element(v.begin(), v.begin() + 3, v.end());//v[3]是第4小的元素
if(is_sorted(v.begin(),v.begin()+3)){

}
}
// sort() (快排)	O(n log n)	O(log n)
// 归并排序	O(n log n)	O(n)
//奇偶分离：奇数在前，同奇偶按大小
bool cmp(int a,int b){
    if(a%2!=b%2){
        return a % 2 > b % 2;
    }else{
        return a < b;
    }
}
//比较函数必须是严格弱序
// return a < b;而不是a <= b;
//结构体排序时忘记加const&大数据会慢，不加的话是拷贝整个结构体，加了是引用传递
bool cmp(const student&a,const student&b){}
// sort(a,a+n)不是sort(a,a+n-1)
//归并排序
int a[100];
int temp[100];
long long cnt;
void merge(int l, int mid, int r) {
    int i=l;
    int k = 0;
    int j = mid + 1;
    while(i<=mid&&j<=r){
        if(a[i]<a[j]){
            temp[k++] = a[i++];
        }else{
            cnt += (mid - i + 1);//逆序对数量
            temp[k++] = a[j++];
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=r){
        temp[k++] = a[j++];
    }
    for (int i = l, j = 0; i <= r;i++,j++){
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
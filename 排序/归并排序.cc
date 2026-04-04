#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void merge(vector<int>&arr,int left,int mid,int right){
        vector<int>temp(right-left+1);
        int i = left;
        int j = mid + 1;
        int k = 0;
        while(i<=mid&&j<=right){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
            }
        }
        while(i<=mid){
            temp[k++] = arr[i++];
        }
        while(j<=right){
            temp[k++] = arr[j++];
        }
        copy(temp.begin(), temp.end(), arr.begin() + left);
}
void mergesort(vector<int>&arr,int left,int right){
    if(left>=right){
        return;
    }
    int mid = left + (right - left) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
int main(){
    vector<int> arr = {2, 5, 6, 7, 5, 5, 7, 8, 4, 3};
    int mid=0;
    mergesort(arr,0, arr.size() - 1);
    return 0;
}
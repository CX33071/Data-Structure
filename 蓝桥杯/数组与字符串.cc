#include <bits/stdc++.h>
int main(){
    std::string s1;
    std::string s2 = "hello";
    std::string s3(5, 'a');
    std::string s4 = s2;
    std::string s5(s2, 1, 3);//从下标1开始取3个字符
}
// 赋值：直接赋值
// 拼接：不能直接拼接2个字面量，s="a"+"b",至少有一个是string对象
// 获取长度s.size()返回字符个数,size()返回的是size_t,需要用int强转
// 判空：s.empty()
// 清空s.clear()
// 获取第一个字符：s.front()
// 获取最后一个字符：s.back()
// 访问：s.at(0),0为下标，at访问检查越界
// 插入：s.insert(2,"123")在下标2前插入“123”he123llo
// s.insert(0,3,'x')在下标0前插入3个x 删除：s.erase(2,3)从下标2开始删除3个字符
// s.pop_back()删除最后一个字符 截取子串：string
// sub=s.substr(1,3)从下标1开始取3个字符        string
// sub=s.substr(1)从下标1开始取 查找：int
// idx=s.find("world")返回第一次出现的下标         s.rfind('o')从右往左找
// s.find_first_of("aeiou")返回字符串里任意字符第一次出现的位置 s.find_last_of
// 判断是否找到了：if(s.find('o')!=string::npos)
// 替换：string s="hello wprld";s.replace(6,5,"c++");从下标6开始替换5个字符为c++
// 删除：s.erase(pos);从pos删到最后，s.erase(pos,len)从pos删len个
// 数组
// strlen()需要#include <cstring>
// 拷贝：strcpy(dest,src);
// 拼接：strcat(s1,s2);
// 比较：int cmp=strcmp(s1,s2);相等返回0
// string和char[]互转：string->char[]:s.c_str()      char s[10]="hello";string
// str=s;直接赋值
// 反转字符串 reverse(s.begin(),s.end());
// s.insert(0, "-");-要加""
// 常用算法，需要#include <algorithm>
#include <iostream>
#include <algorithm>
int main(){
    std::string s = "hello";
    //反转
    reverse(s.begin(), s.end());
    //排序
    sort(s.begin(), s.end());
    //大小写转换
    char up = toupper('a');//错误，toupper返回的是字符ASCII码，要用char强转
    char low = tolower('A');
    //字符串大小写转换,必须加::,防止toupper编译报错
    std::string s = "hello";
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
}
//数字与字符串互转
#include <string>
int main(){
    std::string s = std::to_string(123);
    std::string s2 = std::to_string(3.14);
    int a = std::stoi("123");
    long b = std::stol("123456789");
    long long c = std::stoll("123456789");
    float d = std::stof("3.14");
    double e = std::stod("3.1415");
}
// 数字转字符 res += (char)('0' + rem)
//  强转：int a=ststic_cast<int>(3.14);
// 遍历时修改字符串
#include <string>
int main(){
    std::string s;
    for(char &c:s){
        c = toupper(c);
    }
}
//分隔字符串
#include <iostream>
#include <string>
int main(){
    std::string s;
    getline(std::cin, s);
    std::stringstream ss(s);
    std::string word;
    while(ss>>word){

    }
}
//判断回文串
bool ishuiwen(std::string s){
    int i = 0, j = s.size() - 1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
//判断是不是字母：isalpha(c)
//判断是不是大写字母：isalpha(c)&&isupper(c)
//判断是不是小写字母：isalpha(c)&&islower(c)
//判断字符出现次数
int cishu(std::string s){
    int cnt[26] = {0};
    for(char c:s){
        if(isalpha(c)){
            cnt[tolower(c) - 'a']++;
        }
    }
}
// 注意不要写i<=s.size()-1,可能溢出，因为size_t,应该写int n=s.size();i<=n-1;
// 小写字母偏移：c=(c-'a'+n)%26+'a';
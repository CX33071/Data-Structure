// 1.'1' '2' '3' '''\n'都会被存到缓冲区，只是不同输入函数对'\n'的处理不同，cin和scanf从缓冲区取完数据不会主动清空
// 读数字时，scanf 会自动跳过所有空格、换行,while(scanf(...))循环必须手动结束输入,scanf不能读取带空格和换行的字符串
// %lld输出longlong
//1.解决scanf读取字符，中间遗留空格或换行问题
#include <iostream>
int main(){
    int n;
    char c;
    //加空格跳过空白
    scanf("%d", &n);
    scanf(" %c", &c);
    //或者用getchat吃掉空格
    scanf("%d", &n);
    getchar();
    scanf("%c", &c);
}
// cin>>s自动跳过空格和换行
// cin.get()读单个字符，c=cin.get()
// cin.getline()读一整行，遇到\n停止，给字符数组用的，必须指定读取长度cin.getline(s,100)
// getline(cin,s)读一整行，给字符串用的，可以读空格，但是遇到\n停止，输入一个字符串，然后在下一行再输入一个字符串，只有这两行，用两次getline就行
// 大坑：cin>>和getline混用,前一次的\n留在缓冲区，下一次读取读到\n
#include <iostream>
int main(){
    //1.吃掉换行符
    int n;
    std::string s;
    std::cin >> n;
    std::cin.ignore();
    getline(std::cin, s);
    getline(std::cin, s);
}
//大数据输入输出超时
#include <iostream>
int main(){
    int n;
    //1.用scanf和printf
    //2.关闭同步
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
}
// 行末不要空格，第一个数前不输出空格，后面数字前都输出空格
// 不要混用printf和cin，std::sout<<endl;会超时，请用std::cout<<'\n';
//C++读小数
#include <iostream>
#include <iomanip>
int main(){
    double x;
    std::cin >> x;
    std::cout << std::fixed << std::setprecision(2) << x << '\n';
}
//读不带空格的字符串和带空格的
#include <iostream>
int main(){
    std::string s;
    std::cin >> s;
    getline(std::cin, s);
}
//cin之后getline会吞行，记得sin.ignore()
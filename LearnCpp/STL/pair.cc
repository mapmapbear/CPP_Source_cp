#include<iostream>
#include <utility>

int main(){
    //pair 对组结构通常用来存储key-value格式数据
    std::pair<std::string, int> myp("aaa",10);
    std::cout << myp.first << "-" << myp.second << std::endl;
    std::pair<int , std::string> myp2(1,"qqq");
    std::cout << myp2.first << "-" << myp2.second << std::endl;

    return 0;
} 
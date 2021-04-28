#include <iostream>
#include <set>
struct myFunc{
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};
void test(){
    std::set<int,myFunc> s;
    s.insert(4);
    s.insert(5);
    s.insert(7);
    s.insert(8);
    s.insert(2);
    // for(auto i=s.begin(); i != s.end(); ++i){
    //     std::cout <<  *i << std::endl;
    // }
    for(auto &i : s)
        std::cout <<  i << " ";
    s.insert(8);
    for(auto &i : s)
        std::cout <<  i << " ";
}

int main(){
    test();
    return 0;
}
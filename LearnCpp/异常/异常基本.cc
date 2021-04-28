#include <exception>
#include <iostream>

class Maker{
public:
    void printMaker(){
        std::cout << "This is Print Maker function" << std::endl;
    }

};
int func(int a, int b){
    if(b == 0){
        Maker m;
        throw false;
    }
    return a/b;
}

void test(){
    try{
        func(1,0);
    }
    catch(Maker m){
        std::cout << "B can't not a '0'::Maker"<< std::endl;
        m.printMaker();
    }
    catch(bool b){
        std::cout << "B can't not a '0'::Bool" << std::endl;
        std::cout << "the return value is:" << b << std::endl;
        
    }
}



int main(){
    test();
    return 0;
}
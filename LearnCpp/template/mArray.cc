#include <iostream>
#include "MyArray.hpp"

class Maker{
public:
    std::string name;
    int age;
public:
    Maker(){
        this->name = "";
        this->age = 0;
    }
    Maker(std::string name, int age){
        this->name = name;
        this->age = age;
    }
};

void printMaker(MyArray<Maker> &arr){
    for(int i = 0; i < arr.getSize(); ++i)
        std::cout << arr[i].name << arr[i].age << std::endl;
}

void test(){
    MyArray<Maker> myArr(4);
    Maker m1("string",12);
    Maker m2("stri123g",15);
    Maker m3("str123",16);
    Maker m4("stri1fasfng",12112);
    myArr.push_back(m1);
    myArr.push_back(m2);
    myArr.push_back(m3);
    myArr.push_back(m4);

    printMaker(myArr);

}

int main(){
    test();
    return 0;
}
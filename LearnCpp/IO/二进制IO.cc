#include <ios>
#include<iostream>
#include <fstream>
#include <string.h>

class Maker{
public:
    Maker() = default;
    Maker(const char* name, int age){
        this->age = age;
        strcpy(this->name, name);
    }
public:
    char name[100];
    int age;
};
void test(){
    std::ofstream ofs;
    ofs.open("ByteList",std::ios::out|std::ios::trunc|std::ios::binary);
    if(!ofs.is_open()){
        std::cout << "File Open ERROR !";
    }
    Maker m1("chensong",89);
    Maker m2("xiangyongp",88);
    ofs.write((const char*)&m1,sizeof(Maker));
    ofs.write((const char*)&m2,sizeof(Maker));
    ofs.close();

    std::ifstream ifs;
    ifs.open("ByteList",std::ios::in|std::ios::binary);
    if(!ifs.is_open()){
        std::cout << "File Open ERROR !";
    }
    ifs.read((char*)&m1,sizeof(Maker));
    ifs.read((char*)&m2,sizeof(Maker));
    std::cout << m1.name << " " << m1.age << std::endl;
    std::cout << m2.name << " " << m2.age << std::endl;
    ifs.close();
}

int main(){
    test();
    return 0;
}
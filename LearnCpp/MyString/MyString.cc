#include"MyString.h"
#include"string.h"

MyString::MyString(){
    pAddress = nullptr;
    mLength = 0;
}

MyString::MyString(const char* str){
    mLength = strlen(str);
    pAddress = new char[mLength+1];
    strcpy(pAddress,str);
}

MyString::MyString(MyString& str){
    mLength = str.mLength;
    pAddress = new char[str.mLength+1];
    strcpy(pAddress,str.pAddress);
}

MyString::~MyString(){
    delete[] this->pAddress;
}

const char* MyString::c_str() const{
    return this->pAddress;
}

int MyString::length(){
    return this->mLength;
}

ostream& operator<<(ostream& cout, MyString& str){
    cout << str.pAddress;
    return cout;
}

ostream& operator>>(const char* str,MyString& nStr){
    if(nStr.pAddress != nullptr)
        delete[] nStr.pAddress;
    nStr.pAddress = new char[strlen(str)+1];
    strcpy(nStr.pAddress,str);
}

MyString& MyString::operator=(const MyString& str){
    if(this->pAddress != nullptr)
        delete[] str.pAddress;
    this->pAddress = nullptr;
    this->mLength = str.mLength;
    this->pAddress = new char[this->mLength+1];
    strcpy(pAddress,str.pAddress);
}

MyString& MyString::operator=(const char* str){
    if(this->pAddress != nullptr)
        delete[] str;
    this->pAddress = nullptr;
    this->mLength = strlen(str);
    this->pAddress = new char[this->mLength+1];
    return *this;
}

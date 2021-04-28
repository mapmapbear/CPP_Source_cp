#include<ostream>

class MyString{
public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();
public:
    const char* c_str() const;
    int length();

    friend ostream& operator<<(ostream& cout, MyString& str);
    friend ostream& operator>>(const char* str, MyString& nStr);

    MyString& operator=(const MyString& str);
    MyString& operator=(const char* str);

    char& operator[](int idx);

private:
    char *pAddress;
    int mLength;

};
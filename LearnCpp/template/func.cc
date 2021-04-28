#include<iostream>

template < class T>
void tmpFun1(T &a, T &b){
    std::cout << a << "-" << b << std::endl;
    T tmp = b;
    b = a;
    a = tmp;
    std::cout << a << "-" << b << std::endl;
}
template < class T>
void SortFunc(T arr[], int len){
    
    for(int i = 0; i < len; ++i){
        int max = i;
        for(int j = i+1; j < len; ++j)
            if(arr[max] > arr[j])
                max = j;
        if(max != i){
            tmpFun1(arr[max],arr[i]);
        }
    }
}
template < class T>
void printList(T arr[],int len){
    for(int i = 0; i < len; ++i)
        std::cout << arr[i] << "-";
    std::cout << std::endl;
}
int main(){
    float f1 = 9.999, f2 = 1.32;
    tmpFun1<float>(f1,f2);
    char p[] = "hello word";
    int len = sizeof(p)/sizeof(char);
    SortFunc(p,len);
    printList(p,len);
    return 0;
}
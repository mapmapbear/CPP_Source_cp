#pragma once
template <class T>
class MyArray{
public:
    MyArray(){
        this->mCapacity = 0;
        this->mSize = 0;
    }
    MyArray(int capacity){
        this->mCapacity = capacity;
        this->mSize = 0;
        p = new T[this->mCapacity];
    }
    MyArray(const MyArray &arr){
        this->mCapacity = arr.mCapacity;
        this->mSize = arr.mSize;
        p = new T[arr.mCapacity];
        for(int i = 0; i < mSize; ++i)
            p[i] = arr.p[i];
    }
    MyArray &operator=(const MyArray &arr){
        if(this->p != nullptr){
            delete[] this->p;
            this->p = nullptr;
        }
        this->mCapacity = arr.mCapacity;
        this->p = new T[arr.mCapacity];
        this->mSize = arr.mSize;
        for(int i : arr)
            this->p[i] = arr.p[i];
        
        return *this;

    }

    T& operator[](int index){
        return this->p[index];
    }

    void push_back(const T &arr){
        if(this->mSize == this->mCapacity)
            return ;
        this->p[this->mSize] = arr;
        this->mSize++;
    }

    void pop_back(){
        if(this->mSize == 0){
            return ;
        }
        this->mSize--;
    }

    ~MyArray(){
        if(this->p != nullptr){
            delete [] p;
            p = nullptr;
        }
    }

    int getSize(){
        return this->mSize;
    }

private:
    T *p;
    int mCapacity;
    int mSize;
};
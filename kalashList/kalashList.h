//
// Created by Kalash on ٤/١/٢٠٢٢.
//
#include <iostream>
#include "string"
#include "stdexcept"
using namespace std;
#ifndef DATA_STRUCTURES_KALASHLIST_H
#define DATA_STRUCTURES_KALASHLIST_H
class emptyList:public logic_error
{
public:
    emptyList() : logic_error("The List Is Empty, idiot\n") {}
    explicit emptyList(const string &meseage) : logic_error(meseage) {};
};
class fullList:public logic_error{
public:
    fullList(): logic_error("The List is Full, Idiot\n"){};
    explicit fullList(const string& meseage): logic_error(meseage){};

};
class negativeSize:public logic_error{
public:
    explicit negativeSize(const string &meseage): logic_error(meseage){};
    negativeSize(): logic_error("The Size You Entered Is Negative, Idiot\n"){};
};

template<class T>
class kalashList {
private:
    int maxSize;
    int size;
     T* arr;
public:
    kalashList()=delete;
    explicit kalashList( int max_size) noexcept(false);
    kalashList(const kalashList<T>& list);
    bool     isEmpty()const noexcept ;
    bool     isFull()const noexcept;
    int      getSize()const noexcept;
    int      getMaxSize()const noexcept;
    void     clear() noexcept;
    void 	 insert	(int index, T item) noexcept(false);
    T 	     getAndDelete	(int index)noexcept(false);
    void 	 traverseList(void (*pFunction)(const T& item)) noexcept;
    T& 	     get(int index)const noexcept(false);
    void 	 replace(int index,T item)noexcept(false);
    void     push(T item) noexcept(false);
    T        pop() noexcept(false);
    T        serve() noexcept(false);
    T& operator[](int index) const noexcept(false);
    void     print() const;

    virtual  ~kalashList();
};





#endif //DATA_STRUCTURES_KALASHLIST_H

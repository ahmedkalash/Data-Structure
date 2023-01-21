//
// Created by Kalash on ٣/٢٤/٢٠٢٢.
//
#include <iostream>
#include "string"
#include "stdexcept"
using namespace std;
#ifndef DATA_STRUCTURES_KALASHLINKEDQUEUE_H
#define DATA_STRUCTURES_KALASHLINKEDQUEUE_H

class emptyQueue:public exception
{
public:string meseage="The Queue Is Empty, idiot";
};
class outOfRange:public exception{
public:string meseage="The Index Is Out of Range, Idiot";
};
class fullQueue:public exception{
public:string meseage="The Queue is Full, Idiot";
};


template<typename T>
class node
{
public:
    int item;
    node<T>* next;
};


template<typename T>
class kalashLinkedQueue {
private:
    int size;
    node<T>* front;
    node<T>* rear;

public:
    explicit kalashLinkedQueue()noexcept;
    bool isEmpty()const noexcept ;
    bool isFull()const noexcept;
    int getSize()const noexcept;
    void append(T item) noexcept;
    void append(T arr[],int arrSize) noexcept;
    T retrieve()const throw(emptyQueue);
    T serve()throw(emptyQueue);
    const T& operator[](int index) const throw(outOfRange,emptyQueue);
    void clear() noexcept;
    void print() noexcept;

};




#endif //DATA_STRUCTURES_KALASHLINKEDQUEUE_H

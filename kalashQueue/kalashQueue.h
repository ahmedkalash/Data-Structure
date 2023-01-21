//
// Created by Kalash on ٣/٢٤/٢٠٢٢.
//
#include <iostream>
#include "string"
#include "stdexcept"
using namespace std;
/*#ifndef DATA_STRUCTURES_KALASHQUEUE_H
#define DATA_STRUCTURES_KALASHQUEUE_H*/
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
template<class itemType>
class kalashQueue {
private:
    int front,rear,size;
    const int maxSize;
    itemType* elemnts;
public:
    explicit kalashQueue(int maxSize)noexcept;
    bool isEmpty()const noexcept;
    bool isFull()const noexcept;
    int getSize()const noexcept;
    void append(itemType item) throw(fullQueue);
    void append(itemType arr[],int arrSize)throw(fullQueue);
    itemType retrieve()const throw(emptyQueue);
    itemType serve()throw(emptyQueue);
    const itemType& operator[](int index) const throw(outOfRange,emptyQueue);
    void clear() noexcept;
    void print() noexcept;

};



//#endif //DATA_STRUCTURES_KALASHQUEUE_H

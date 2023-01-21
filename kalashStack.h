//
// Created by Kalash on ٣/١٠/٢٠٢٢.
//
#ifndef DATA_STRUCTURES_KALASHSTACK_H
#define DATA_STRUCTURES_KALASHSTACK_H
#include <iostream>
#include "string"
using namespace std;

template <typename itemType>
class kalashStack
  {

    int total_size;
    int top;
    itemType* arr;

public:
    kalashStack();
    explicit kalashStack(int total_size);
    bool stackfull() const;
    bool push(itemType item);
    itemType pop();
    int length() const;
    int totalSize() const;
    itemType stackTop() const;
    void clear();
    void print();
    ~kalashStack();


};



#endif //DATA_STRUCTURES_KALASHSTACK_H

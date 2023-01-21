//
// Created by Kalash on ٣/١٣/٢٠٢٢.
//
#ifndef DATA_STRUCTURES_KALASHLINKEDSTACK_H
#define DATA_STRUCTURES_KALASHLINKEDSTACK_H
#include <iostream>
#include "string"
using namespace std;

class node
{
public:
    int data=0;
    node* next= nullptr;
};


class kalashLinkedStack
{
    int total_size=0;
    node* top= nullptr;

public:
    kalashLinkedStack();
    static bool stackfull() ;
    void push(int item);
    int pop();
    int length() const;
    int stackTop() const;
    void clear();
    void print() const;
    ~kalashLinkedStack();


};




#endif //DATA_STRUCTURES_KALASHLINKEDSTACK_H









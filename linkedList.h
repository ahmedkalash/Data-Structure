//
// Created by Kalash on ٤/٢٥/٢٠٢٢.
//

#ifndef DATA_STRUCTURES_LINKEDLIST_H
#define DATA_STRUCTURES_LINKEDLIST_H

class node
{
public:
    int item;
    node* next;
};



class linkedList {
private:
    int size;
    node* head;
    node* tail;

public:
    explicit linkedList();
    bool isEmpty()const  ;
    bool isFull()const ;
    int getSize()const ;
    void addAsTail(int item) ;
    void addAsHead(int item) ;
    void addSorted(int item);
    node find(int i);
    void reverse();
    int popHead();
    void removeFirst(int i); // removes the first node with val i;
    void addAll(linkedList l);
    void removeAll(int i);
    void clear() ;
    void print() ;
};


#endif //DATA_STRUCTURES_LINKEDLIST_H

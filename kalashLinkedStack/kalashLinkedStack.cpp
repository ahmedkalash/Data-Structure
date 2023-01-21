//
// Created by Kalash on ٣/١٣/٢٠٢٢.
//

#include "kalashLinkedStack.h"

kalashLinkedStack::kalashLinkedStack():total_size(0),top(nullptr){}
bool kalashLinkedStack::stackfull() {return false;}
void kalashLinkedStack::push(int item)
{
    auto* pn =new node;
    pn->data=item;
    pn->next=top;
    top = pn;
    pn= nullptr;
    //delete(pn);
    total_size++;

}
int kalashLinkedStack::pop()
{
    int item=top->data;
    node* temp=top;
    top=temp->next;
    //temp= nullptr;
    delete(temp);
    total_size--;
    return item;
}
int kalashLinkedStack::length() const {return total_size;}
int kalashLinkedStack::stackTop() const
{
    return top->data;
}
void kalashLinkedStack::print()const
{
    int i=0;
    node* temp=top;
    while (temp!= nullptr)
    {
        cout<< temp->data;
        temp=temp->next;
    }
}
void kalashLinkedStack::clear()
{
    node* curr=top;
    while (curr)
    {
        node* post=curr->next;
        delete(curr);
        curr=post;
        total_size--;
    }
    top= nullptr;

}
kalashLinkedStack::~kalashLinkedStack() = default;


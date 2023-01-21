//
// Created by Kalash on ٣/١٠/٢٠٢٢.
//

#include "kalashStack.h"

template <typename itemType>
kalashStack<itemType>::kalashStack(): top(0), total_size(0)
{
    arr  =  new itemType[total_size];
}
template <typename itemType>
kalashStack<itemType>:: kalashStack(int total_size): top(0), total_size(total_size)
{
    arr  =  new itemType[total_size];
    for (int i = 0; i < total_size; ++i) { arr[i]= false; }
}
template <typename itemType>
bool kalashStack<itemType>:: stackfull() const
{
    return top==total_size;
}
template <typename itemType>
bool kalashStack<itemType>:: push(itemType item)
{
    if (stackfull())
        return false;
    else {
        arr[top] = item; // heapContent[top++]=item;
        top++;
        return true;
    }

}
template <typename itemType>
itemType kalashStack<itemType>:: pop()
{
    // pre-conditions: stack should not be empty!
    // pos-conditions: the length(top) will be decremented by 1,
    // and the item will not be removed, and it does not have to be removed. and it can't be removed as the stack should be contiguous.
    top--;
    return arr[top];
}
template <typename itemType>
int kalashStack<itemType>:: length() const
{
    return top;
}
template <typename itemType>
int kalashStack<itemType>:: totalSize() const
{
    return total_size;
}
template <typename itemType>
itemType kalashStack<itemType>:: stackTop() const
{
    return arr[top];
}
template <typename itemType>
void kalashStack<itemType>:: clear()
{
    top=0;

}
template <typename itemType>
void kalashStack<itemType>:: print()
{
    for (int i = 0; i < top; ++i) {
        cout << arr[i]<<' ';

    }
}
template <typename itemType>
kalashStack<itemType>::~kalashStack()
{
    delete[] arr;
}

#include <iostream>
#include "string"
using namespace std;

#include "kalashVector.h"


template <typename itemType>
kalashVector<itemType>::kalashVector(): top(0), total_size(0)
    {
        arr  =  new itemType[total_size];
    }
template <typename itemType>
kalashVector<itemType>:: kalashVector(int total_size): top(0), total_size(total_size)
    {
        arr  =  new itemType[total_size];
        for (int i = 0; i < total_size; ++i) { arr[i]= false; }
    }
template <typename itemType>
bool kalashVector<itemType>:: vectorfull() const
    {
        return top==total_size;
    }
template <typename itemType>
void kalashVector<itemType>:: push(itemType item)
    {
        if (vectorfull())
        {
            auto* newArr= new itemType[2*total_size];
            for (int i = 0; i < total_size ;++i) {
                newArr[i]=arr[i];
            }

            newArr[top]=item;
            top++;

            itemType* temp=arr;
            arr=newArr;
            newArr=nullptr;
            delete[] temp;
            total_size *=2;

        }
        else {
            arr[top] = item; // heapContent[top++]=item;
            top++;
        }

    }
template <typename itemType>
itemType kalashVector<itemType>:: pop()
    {
        // pre-conditions: stack should not be empty!
        // pos-conditions: the length(top) will be decremented by 1,
        // and the item will not be removed, and it does not have to be removed. and it can't be removed as the stack should be contiguous.
        top--;
        return arr[top];
    }
template <typename itemType>
int kalashVector<itemType>:: length() const
    {
        return top;
    }
template <typename itemType>
int kalashVector<itemType>:: totalSize() const
    {
        return total_size;
    }
template <typename itemType>
itemType kalashVector<itemType>:: end() const
    {
        return arr[top];
    }
template <typename itemType>
void kalashVector<itemType>:: clear()
    {
        top=0;

    }
template <typename itemType>
bool kalashVector<itemType>:: replace(int index, itemType item)
    {
        // pre-conditions: index < top.
        if(index>=top)
            return false; // throw exeption
        arr[index]=item;
        return true;


    }
template <typename itemType>
void kalashVector<itemType>:: print()
    {
        for (int i = 0; i < top; ++i) {
            cout << arr[i]<<' ';

        }
    }
template <typename itemType>
kalashVector<itemType>::~kalashVector()
{
    delete[] arr;
}
// operators
template <typename itemType>
const itemType&kalashVector<itemType>:: operator[](int index)const
    {

    if(index<0 || index>=length())
        throw  "exception: index out of range";
    return arr[index];
    }



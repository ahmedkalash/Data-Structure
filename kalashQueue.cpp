//
// Created by Kalash on ٣/٢٤/٢٠٢٢.
//
#include <iostream>
#include "string"
#include "kalashQueue.h"
using namespace std;

template<class itemType>
kalashQueue<itemType>::kalashQueue(int maxSize) noexcept:front(0),rear(-1),size(0),maxSize(maxSize)  {
elemnts=new itemType[maxSize];
}
template<class itemType>
bool kalashQueue<itemType>::isEmpty() const noexcept{
    return size==0;
}
template<class itemType>
bool kalashQueue<itemType>::isFull() const noexcept {
    return size==maxSize;
}
template<class itemType>
int kalashQueue<itemType>::getSize() const noexcept {
    return size;
}
template<class itemType>
void kalashQueue<itemType>::append(itemType item) throw(fullQueue) {
    if(isFull())
        throw fullQueue();
    else
    {
        rear = ++rear % maxSize;
        elemnts[rear]=item;
        size++;
    }
}
template<class itemType>
void kalashQueue<itemType>::append(itemType arr[],int arrSize)throw(fullQueue) {
    if(isFull())
        throw fullQueue();
    else
    {
        for (int i = 0; i < arrSize; ++i) {
            rear = ++rear % maxSize;
            elemnts[rear]=arr[i];
            size++;
        }

    }
}
template<class itemType>
itemType kalashQueue<itemType>::retrieve() const throw(emptyQueue) {
    if(isEmpty())
        throw emptyQueue();
    else { return elemnts[front]; }
}
template<class itemType>
itemType kalashQueue<itemType>::serve() throw(emptyQueue) {
    if(isEmpty())
        throw emptyQueue();
    else
    {
        int tempFront=front;
        front=++front%maxSize;
        size--;
        return elemnts[tempFront];

    }

}
template<class itemType>
const itemType& kalashQueue<itemType>::operator[](int index) const
        throw(outOfRange,emptyQueue)
        {
    if(size==0)
        throw emptyQueue();
    if(index<0 || index >size-1)
        throw outOfRange();
    int temp= (front+index) % maxSize;
    return elemnts[temp];
}
template<class itemType>
void kalashQueue<itemType>::clear()noexcept {
    if(!isEmpty()) {
        front = 0;
        rear = -1;
        size = 0;
    }
}
template<class itemType>
void kalashQueue<itemType>::print()noexcept {
    for (int i = 0; i < size; ++i) {
        if(size==0)
            cout << "Empty Queue\n";
        int temp= (front+i) % maxSize;
        cout << elemnts[temp] << " ";
    }
}

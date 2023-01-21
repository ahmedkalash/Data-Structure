//
// Created by Kalash on ٣/٢٤/٢٠٢٢.
//

#include "kalashLinkedQueue.h"


template<typename T>
kalashLinkedQueue<T>::kalashLinkedQueue()noexcept :size(0),front(nullptr),rear(nullptr){}
template<typename T>
bool kalashLinkedQueue<T>::isEmpty() const noexcept {
    return size==0; // or return !front // or return !rear
}
template<typename T>
bool kalashLinkedQueue<T>::isFull() const noexcept  {
    return false;
}
template<typename T>
int kalashLinkedQueue<T>::getSize() const noexcept {
    return size;
}
template<typename T>
void kalashLinkedQueue<T>::append(T item)  noexcept {
    auto*temp =new node<T>;
    temp->item=item;
    temp->next= nullptr;
    if(!front)
        rear=front=temp;
    else
    {
        rear->next=temp;
        rear=temp;
    }
    size++;
}

template<typename T>
void kalashLinkedQueue<T>::append(T *arr, int arrSize) noexcept {

    for (int i = 0; i < arrSize; ++i) {
        append(arr[i]);
    }

}

template<typename T>
T kalashLinkedQueue<T> ::retrieve() const throw(emptyQueue) {
    if(!front)
        throw emptyQueue();
    return front->item;
}

template<typename T>
T kalashLinkedQueue <T>::serve() throw(emptyQueue) {
    if(!front)
        throw emptyQueue();
    int e=front->item;
    node<T> * temp=front;
    front=front->next;
    delete temp;
    if(!front)
        rear= nullptr;
    size --;
    return e;
}

template<typename T>
const T &kalashLinkedQueue<T> ::operator[](int index) const throw(outOfRange, emptyQueue) {
    if(size==0)
        throw emptyQueue();
    if(index<0 || index >=size)
        throw outOfRange();
    node<T>* temp=front;
    for (int i = 0; i <= index; ++i) {
        if(i==index)
            return temp->item;
        temp=temp->next;
    }
}

template<typename T>
void kalashLinkedQueue<T>::clear() noexcept {
    node<T>* second=front;
    while (!front)
    {
        second=front->next;
        free (front);
        front =second;
    }
    size=0;
    front= nullptr;
    rear= nullptr;


}

template<typename T>
void kalashLinkedQueue<T>::print() noexcept {
    if(isEmpty())
        cout << "Empty Queue, Idiot";
    else
    {
        for (auto*temp =front;  temp ; temp=temp->next) {
            cout << temp->item << " ";
        }
    }

}


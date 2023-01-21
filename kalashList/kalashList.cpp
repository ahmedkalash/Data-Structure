//
// Created by Kalash on ٤/١/٢٠٢٢.
//

#include "kalashList.h"

template<typename T>
kalashList<T>::kalashList( int max_size) noexcept(false):size(0) {
    if(max_size<0)
        throw negativeSize();
    maxSize=max_size;
    arr= new T[maxSize];

}
template<typename T>
kalashList<T>::kalashList(const kalashList<T>& list):maxSize(list.maxSize), size(list.size), arr(list.arr) {}
template<typename T>
bool kalashList<T>::isEmpty() const noexcept {
    return size==0;
}
template<typename T>
bool kalashList<T>::isFull() const noexcept {
    return size==maxSize;
}
template<typename T>
int kalashList<T>::getSize() const noexcept {
    return size;
}
template<typename T>
int kalashList<T>::getMaxSize() const noexcept {
    return maxSize;
}
template<typename T>
void kalashList<T>::clear() noexcept {
    size=0;

}
template<typename T>
void kalashList<T>::insert(int index, T item) noexcept(false) {
    if(index < 0 || index > size)
        throw out_of_range("The Index Is Out of Range, Idiot\n");
    if(isFull())
        throw fullList();
    for (int i = size-1; index <= i ; i--)
        arr[i+1]=arr[i];
    arr[index]=item;
    size++;
}
template<typename T>
T kalashList<T>::getAndDelete(int index) noexcept(false) {
    if(index < 0 || index >= size)
        throw out_of_range("The Index Is Out of Range, Idiot\n");
    if(isEmpty())
        throw emptyList();
    T temp = arr[index];
    for (int i = index; i < size-1  ; ++i)
        arr[i]=arr[i+1];
    size--;
    return temp;
}
template<typename T>
void kalashList<T>::traverseList(void (*pFunction)(const T& item)) noexcept {
    for (int i=0;i<size;i++)
        (*pFunction)(arr[i]);

}
template<typename T>
T& kalashList<T>::get(int index) const noexcept(false) {
    if(index < 0 || index >= size)
        throw out_of_range("The Index Is Out of Range, Idiot\n");
    if(isEmpty())
        throw emptyList();
    return arr[index];
}
template<typename T>
void kalashList<T>::replace(int index, T item) noexcept(false) {
    if(index < 0 || index >= size)
        throw out_of_range("The Index Is Out of Range, Idiot\n");
    if(isEmpty())
        throw emptyList();
    arr[index]=item;
}

template<typename T>
 T &kalashList<T>::operator[](int index) const
        noexcept(false) {

    return get(index) ;
}

template<typename T>
void kalashList<T>::print() const {
    for (int i=0;i<size;i++)
        cout <<arr[i] <<" ";
    if(!size)
        cout << "Empty List";
}

template<typename T>
void kalashList<T>::push(T item) noexcept(false) {
    insert(size,item);

}

template<typename T>
T kalashList<T>::serve() noexcept(false) {
    T temp = getAndDelete(0);
    return temp;

}

template<typename T>
kalashList<T>::~kalashList() {
    delete[] arr;
}

template<class T>
T kalashList<T>::pop() noexcept(false) {
    T temp = getAndDelete(size-1);

    return temp;
}


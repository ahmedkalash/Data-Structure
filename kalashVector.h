#ifndef DATA_STRUCTURES_KALASHVECTOR_H
#define DATA_STRUCTURES_KALASHVECTOR_H
#include <iostream>
#include "string"
using namespace std;

template <typename itemType>
class kalashVector {
        int total_size;
        int top;
        itemType* arr;

    public:
        kalashVector();
        explicit kalashVector(int total_size);
        bool vectorfull() const;
        void push(itemType item);
        itemType pop();
        int length() const;
        int totalSize() const;
        itemType end() const;
        void clear();
        bool replace(int index, itemType item);
        void print();
        // operators
        const itemType& operator[](int index)const;
        ~kalashVector();
    };





#endif //DATA_STRUCTURES_KALASHVECTOR_H

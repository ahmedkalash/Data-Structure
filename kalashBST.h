//
// Created by Kalash on ٤/٢٨/٢٠٢٢.
//
#include "kalashQueue.cpp"
#ifndef DATA_STRUCTURES_KALASHTREE_H
#define DATA_STRUCTURES_KALASHTREE_H

template<typename T>
class node
{
public:
    T item;
    node<T>* right;
    node<T>* left;

    node(node<T>* l, T item ,node<T>* r): left(l), item(item), right(r){ }
    node(): left(nullptr)/*,item(nullptr)*/, right(nullptr){ }

    bool isLeafNode (){  return (!left && !right);  }
    bool isParent   (){  return !isLeafNode();  }


};


template<typename T>
class kalashBST {

private:
    node<T>* root;
    int size;
    int depth;

    //// helper functions
    void    clear       (node<T> pN);
    void	inOrder 	(node<T>* pN ,void (*pFunction)(T item));
    void	postOrder	(node<T>* pN, void (*pFunction)(T item));
    void	preOrder	(node<T>* pN, void (*pFunction)(T item));
    int	    getDepthRec (node<T>* pN);
    void    deleteNode  (node<T>* &pN); // pass the pointer by reference! (: (:
    void    deleteNode2 (node<T>* &pN); // pass the pointer by reference! (: (:

public:
    kalashBST();
    kalashBST          (const kalashBST<T>& kalashTree1);
    void    clear       ();
    int	    getSize     ();
    int	    getDepth    ();
    bool    isEmpty     ();
    void	inOrder	    (void (*pFunction)(T item));
    void	postOrder	(void (*pFunction)(T item));
    void	preOrder	(void (*pFunction)(T item));
    void    insert      (const T& item);
    int	    getDepthRec ();
    T       getAndRemove(int key);
    void    BFT         (void (*pFunction)(T item));








};




#endif //DATA_STRUCTURES_KALASHTREE_H

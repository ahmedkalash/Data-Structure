//
// Created by Kalash on ٤/٢٨/٢٠٢٢.
//

#include "kalashBST.h"
#include "vector"





template<typename T>
kalashBST<T>::kalashBST():root(nullptr), size(0), depth(0) {}

template<typename T>
kalashBST<T>::kalashBST(const kalashBST<T> &kalashTree1)
:root(kalashTree1.root),size(kalashTree1.size),depth(kalashTree1.depth) {}

template<typename T>
void kalashBST<T>::clear() {
    node<T>* p=root/*->left*/;
    clear(p);
    size=0;
    depth=0;
    root= nullptr;
}

template<typename T>
void kalashBST<T>::clear(node<T>pN) {
    if(!pN)
        return;

    clear(pN->left);
    clear(pN->right);
    delete pN;
}

template<typename T>
int kalashBST<T>::getSize() {
    return size;
}

template<typename T>
int kalashBST<T>::getDepth() {
    return depth;
}

template<typename T>
bool kalashBST<T>::isEmpty() {
    return (size==0);
}

template<typename T>
void kalashBST<T>::inOrder(void (*pFunction)(T item)) {
    node<T>* p=root;
    inOrder(p,pFunction);
}

template<typename T>
void kalashBST<T>::inOrder(node<T>* pN, void (*pFunction)(T item)) {
    if(!pN)
        return;
    inOrder(pN->left,pFunction);
    pFunction(pN->item);
    inOrder(pN->right,pFunction);
}

template<typename T>
void kalashBST<T>::insert(const T& item) {
    node<T> *newNode, *prev, *curr=root ;
    int d=1; // it is initialized with 0 so if the tree is empty then the new node will be a level 1
            //                              else , if the tree is not empty then we should start count from level 1.
    newNode = new node<T>(nullptr,item, nullptr);
    if(!root)
        root=newNode;
    else
    {
        while (curr)        // this starts from the root and this means that we are at level 1.
        {
            prev= curr;
            if(item < curr->item)
                curr = curr->left;
            else
                curr= curr->right;
            d++;
        }
        if(item < prev->item)
            prev->left =newNode;
        else
            prev->right =newNode;
    }

    size++;

    if (d> depth) {
        depth=d;
    }


}

template<typename T>
int kalashBST<T>::getDepthRec(node<T> *pN)
{
    if(!pN)
        return 0;
    int left = getDepthRec(pN->left);
    int right = getDepthRec(pN->right);
    return left>right ? left+1 : right+1;
}

template<typename T>
int kalashBST<T>::getDepthRec() {
    getDepthRec(root);


}

template<typename T>
T kalashBST<T>::getAndRemove(int key)
{
    node<T> *curr=root,*prev = nullptr;
    while (curr)
    {
        prev=curr;
        if(key==curr->item)  // if we found what we seek , we get out.
            break;
        else if(key < curr->item)
            curr= curr->left;
        else
            curr= curr->right;
    }
    if(prev==root)
        deleteNode(root); // passing a reference to the root(is a ptr) to allow changing the root
    else if((key < prev->item))
        deleteNode(root->left); // passing a reference to the left(is a ptr) to allow changing the left
    else
        deleteNode(root->right); // passing a reference to the right(is a ptr) to allow changing the right


    size--;
    depth = getDepthRec();

}

template<typename T>
void kalashBST<T>::deleteNode(node<T>* &pN) // 'pN' is the pointer that hold the node we want to delete and is passed by reference,so we can change the address it holds.
{
    node<T> *i, *temp = pN; // 'temp' will hold the node we want to delete during the over all fun ,and then we delete it at the end of the fun.
    if(!pN->left) // if the node we want to delete does not have left.
        pN=pN->right; // link it's right tree(node) with the previous node.
    else if(!pN->right) // else if the node we want to delete does not have right.
        pN=pN->left; // link it's left tree(node) with the previous node.
    else // else if it has left and right.
    {
        pN=pN->right; // link it's right tree(node) with the previous node.
        for (i=temp->right; i->left ; i=i->left) ; //  while 'i' has left vist this left. when the loop ends 'i' will be pointing to the left deepest node(the last node on the left side)
        i->left=temp->left; // link the left of the left deepest node with the left subtree of the node we want to delete('temp' will be pointing to node we want to delete)
    }
    delete temp;  // and finally delete the node we want to delete
}

template<typename T>
void kalashBST<T>::deleteNode2(node<T> *&pN)  // 'pN' is the pointer that hold the node we want to delete and is passed by reference,so we can change the address it holds.
{
    node<T> *prev, *temp ;
    if(!pN->left) // if the node we want to delete does not have left.
        pN=pN->right; // link it's right tree(node) with the previous node.
    else if(!pN->right) // else if the node we want to delete does not have right.
        pN=pN->left; // link it's left tree(node) with the previous node.
    else // else if it has left and right.
    {
        temp = pN->left;  // 'temp' will hold the root of the left subtree of the node we want to delete
        if(!temp->right) // if it does not have right then it has  the greatest item in the left subtree
        {
            pN->item=temp->item; // so take the item it has and put it in node we want to delete
            pN->left=temp->left;  // and then bypass temp and link its parent with the left child
        }
        else
        {
            for(;temp->right; temp=temp->right) // while it have right vist this right.when the loop ends 'temp' will be pointing to the right deepest node(the last node on the left subtree)
                prev = temp; // and 'prev' will be pointing to the parent of 'temp'.
            pN->item = temp->item; // so take the item it has and put it in node we want to delete
            prev->right = temp->left;  // and then bypass temp and link its parent with the left child
        }
    }
    delete temp;

}

template<typename T>
void kalashBST<T>::BFT(void (*pFunction)(T item))
{
    if(!isEmpty())
    {
        kalashQueue<node<T>> queue(size);
        queue.append(*root);
        while (!queue.isEmpty())
        {
            node<T> tempNode = queue.serve();
            if(tempNode.left)
                queue.append(tempNode.left);
            if(tempNode.right)
                queue.append(tempNode.right);

            pFunction(tempNode.item);
        }
    }
}

template<typename T>
void kalashBST<T>::postOrder(node<T>* pN, void (*pFunction)(T))
{
    if(!pN)
        return;
    inOrder(pN->left,pFunction);
    inOrder(pN->right,pFunction);
    pFunction(pN->item);
}

template<typename T>
void kalashBST<T>::preOrder(node<T>* pN, void (*pFunction)(T))
{
    if(!pN)
        return;
    pFunction(pN->item);
    inOrder(pN->left,pFunction);
    inOrder(pN->right,pFunction);
}

template<typename T>
void kalashBST<T>::preOrder(void (*pFunction)(T))
{
    node<T>* p=root;
    preOrder(p,pFunction);
}

template<typename T>
void kalashBST<T>::postOrder(void (*pFunction)(T))
{
    node<T>* p=root;
    postOrder(p,pFunction);
}












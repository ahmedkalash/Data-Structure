//
// Created by Kalash on ٤/٢٥/٢٠٢٢.
//

#include "linkedList.h"
#include "iostream"
using namespace std;
linkedList::linkedList():size(0),head(nullptr),tail(nullptr) {

}

bool linkedList::isEmpty() const {
    return (size ==0);
}

bool linkedList::isFull() const {
    return false;
}

int linkedList::getSize() const {
    return size;
}

void linkedList::addAsTail(int item) {
    node*temp =new node;
    temp->item=item;
    temp->next= nullptr;
    if(!head) // if the list is empty
        tail=head=temp;
    else
    {
        tail->next=temp;
        tail=temp;
    }
    size++;
}

void linkedList::addAsHead(int item) {
    node*temp =new node;
    temp->item=item;
    temp->next= head;
    if(!head) // if the list is empty
        tail=head=temp;
    else
        head=temp;
    size++;
}

void linkedList::addSorted(int item) {
    node* temp = new node;
    temp->item=item;
    node* curr=head;
    node* prev=head;
    while (curr != nullptr) {
        if(size==0)
        {
            addAsHead(item);
            break;
        }
        else if (curr->item >= item)
        {
            prev->next=temp;
            temp->next=curr;
            break;
        }
        prev=curr;
        curr=curr->next;
    }
}

node linkedList::find(int item) // returns nullptr if not found
{
    node* temp=head;
    while (temp!= nullptr) {
        if (temp->item == item)
            break;
        temp=temp->next;
    }
    return *temp;
}

void linkedList::reverse() {
    if(size>=2) {
        node *prev = head;
        node *mid = prev->next;
        node *after = mid;
        head->next= nullptr;
        while (mid)
        {
            after=after->next;
            mid->next=prev;

            prev=mid;
            mid=after;
        }
        after=head;
        head=tail;
        tail=after;
    }
}

int linkedList::popHead() {
    int item= head->item;
    node* temp=head;
    head=head->next;
    delete temp;
    return item;
    size--;
}

void linkedList::removeFirst(int item) {
    node* prev=head;
    node* temp=head;
    while (temp!= nullptr) {
        if (temp->item == item)
            break;
        prev=temp;
        temp=temp->next;
    }
    if(temp==head) // if the item is at the head
    {
        head= head->next;
        if(!head)
            tail= nullptr;// if it is the only node in the list
        delete temp;
    }

    else if(temp==tail) // if the item is at the tail
    {
        tail= prev;
        tail->next= nullptr;
        delete temp;
    }
    else if(temp) // if the item exist anywhere after head
    {
        prev->next=temp->next;
        delete temp;
    }
    size--;
}

void linkedList::addAll(linkedList l) {

    node* temp=l.head;
    while(temp)
    {
        addAsTail(temp->item);
        temp=temp->next;
    }
}

void linkedList::clear()  {
    while (head)
    {
        tail=head->next;
        delete head;
        head =tail;
    }
}

void linkedList::print()  {
    node* temp=head;
    while (temp)
    {

        cout << temp->item<< " ";
        temp=temp->next;
    }
}

void linkedList::removeAll(int item) {
    node* prev=head;
    node* curr=head;
    while (curr != nullptr) {
        if (curr->item == item)
        {
            if(curr == head) // if the item exist at the head
            {
                head= head->next;
                if(!head) // if it is the only node in the list
                    tail= nullptr;
                delete curr;
                curr=head;
            }
            else if(curr == tail) // if the item is at the tail
            {
                curr = nullptr;
                prev->next = nullptr;
                delete tail;
                tail =prev;
            }
            else
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            size--;
        } else {
            prev = curr;
            curr = curr->next;
        }


    }


}

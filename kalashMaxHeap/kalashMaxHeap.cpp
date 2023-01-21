//
// Created by Kalash on ٢٩/٠٥/٢٠٢٢.
//

#include "stdexcept"
#include "kalashMaxHeap.h"
#include "cmath"
#include "iostream"
#include "iomanip"
using namespace std;

#define root  1



template<typename heapItem,typename compartor>
kalashMaxHeap<heapItem,compartor>::kalashMaxHeap(int elementsNum, const heapItem *array )
    :maxSize(elementsNum+1), usedSlots(0), heapContent(new heapItem[maxSize])
{
    for (int i = 0; i < maxSize; ++i) {
        heapContent[i]=-1;
    }
    insert(elementsNum,array);

}

template<typename heapItem,typename compartor>
kalashMaxHeap<heapItem,compartor>::kalashMaxHeap(int maxSize)
        :maxSize(maxSize+1), usedSlots(0), heapContent(new heapItem[maxSize]){}
template<typename heapItem,typename compartor>
int kalashMaxHeap<heapItem,compartor>::parentPos(int oneBasedIndex)const
{
    if(oneBasedIndex==0)
        throw std::out_of_range("Indexing starts from 1 not 0 \n");
    else if(oneBasedIndex==1)
        throw std::logic_error("This is the root! \n");
    else
        return oneBasedIndex/2; // floor
}

template<typename heapItem,typename compartor>
int kalashMaxHeap<heapItem,compartor>::lChildPos(int oneBasedIndex)const
{
    /*
     * first we must make sure that this node has a left child,
     * By calculating the left Child Pos and check if it is within the size of the Array or not.
     * If not, the function will return -1.
     * left child index = 2*parentIndex.
     */

    return (((2*oneBasedIndex)<=usedSlots) ? (2*oneBasedIndex):-1 );
}

template<typename heapItem,typename compartor>
int kalashMaxHeap<heapItem,compartor>::rChildPos(int oneBasedIndex)const
{
    /*
    * first we must make sure that this node has a right child,
    * By calculating the right Child Pos and check if it is within the size of the Array or not.
    * If not, the function will return -1.
     * right child index = (2*parentIndex+1 ) or (lChildPos+1).
    */
    return (((2*oneBasedIndex+1)<=usedSlots) ? (2*oneBasedIndex+1):-1 );
}

template<typename heapItem,typename compartor>
bool kalashMaxHeap<heapItem,compartor>::isLeaf(int oneBasedIndex)const
{
    /*
     * A node will be a leaf if it does not have nether a left child nor a right child.
     *
     */
    int leftChild = lChildPos(oneBasedIndex);
    int rightChild = rChildPos(oneBasedIndex);
    if(leftChild==-1 && rightChild==-1)
        return true;
    return false;
}

template<typename heapItem,typename compartor>
int kalashMaxHeap<heapItem,compartor>::getLevel(int oneBasedIndex)const
{
    return floor(log2(oneBasedIndex));
}

template<typename heapItem,typename compartor>
int kalashMaxHeap<heapItem,compartor>::getHeight() const
{
    return getLevel(usedSlots)+1;;
}

template<typename heapItem,typename compartor>
void kalashMaxHeap<heapItem,compartor>::insert(heapItem item)
{
    if(isFull())
        throw std::logic_error("from function \"insert\": The heap Is full \n");
    heapContent[++usedSlots] = item;
    bubbleUp(usedSlots);
}

template<typename heapItem,typename compartor>
void kalashMaxHeap<heapItem,compartor>::insert(int elementsNum, const heapItem *array)
{
    if(elementsNum>((maxSize-1)-usedSlots))
        throw std::range_error("from function \"insert\": Array size is more than the free slots\n");
    for (int i = 0; i < elementsNum; ++i)
        insert(array[i]);
}

template<typename heapItem,typename compartor>
heapItem kalashMaxHeap<heapItem,compartor>::getRoot()
{
    return heapContent[root];
}

template<typename heapItem,typename compartor>
void kalashMaxHeap<heapItem,compartor>::remove(int oneBasedIndex)
{
    if(isEmpty())
        throw underflow_error(" From function \"remove\":  empty heap");
    if(oneBasedIndex ==0)
        throw std::out_of_range("From function \"remove\":  Out of range! Remember the indexing starts from 1 not zero\n");
    else if(oneBasedIndex < 1 || oneBasedIndex>usedSlots)
        throw std::out_of_range("From function \"remove\": Out of range!\n");
    swap(oneBasedIndex,usedSlots);
    usedSlots--;
    bubbleDown(oneBasedIndex);
}

template<typename heapItem,typename compartor>
heapItem kalashMaxHeap<heapItem,compartor>::getAndRemoveRoot()
{
    heapItem rooot=getRoot();
    remove(root);
    return rooot;
}

template<typename heapItem,typename compartor>
void kalashMaxHeap<heapItem,compartor>::bubbleUp(int oneBasedIndex)
{
    int childIndex = oneBasedIndex;
    if(childIndex != root)
    {
        int parentIndex = parentPos(childIndex);
        //IsFirstPrior(heapContent[childIndex],heapContent[parentIndex]); // (heapContent[childIndex] > heapContent[parentIndex])
        while (  childIndex != root && IsFirstPrior(heapContent[childIndex], heapContent[parentIndex]) )  // while 'child' is prior keep going(bubble it up).
        { //cout << " انا هنا يا جو ";
            swap(childIndex, parentIndex);
            childIndex = parentIndex;
            if(childIndex != root)  // if the condition is 'false' the parentIndex will not be updated and will be = childIndex and then this will break the loop condition
                parentIndex = parentPos(childIndex);
        }
    }
}

template<typename heapItem,typename compartor>
void kalashMaxHeap<heapItem,compartor>::bubbleDown(int oneBasedIndex)
{
    if(!isLeaf(oneBasedIndex))
    {
        int parentIndex = oneBasedIndex;
        int lChildIndex = lChildPos(parentIndex);
        int rChildIndex = rChildPos(parentIndex);
        // IsFirstPrior(heapContent[lChildIndex],heapContent[parentIndex]); // (heapContent[parentIndex]<heapContent[lChildIndex])
        // IsFirstPrior(heapContent[rChildIndex],heapContent[parentIndex]); // (heapContent[parentIndex]<heapContent[rChildIndex])
        bool ParentlessL = ((lChildIndex==-1)? false: IsFirstPrior(heapContent[lChildIndex], heapContent[parentIndex]) );
        bool ParentLessR = ((rChildIndex==-1)? false: IsFirstPrior(heapContent[rChildIndex], heapContent[parentIndex]) );
        while (!isLeaf(parentIndex) && (ParentlessL || ParentLessR)  )
        {
            if(lChildIndex==-1 )
            {
                swap(parentIndex, rChildIndex);
                parentIndex = rChildIndex;
            }

            else if (rChildIndex==-1 )
            {
                swap(parentIndex, lChildIndex);
                parentIndex = lChildIndex;
            }
            // IsFirstPrior(heapContent[rChildIndex],heapContent[lChildIndex])  // heapContent[rChildIndex]>heapContent[lChildIndex]
            else if ( IsFirstPrior(heapContent[rChildIndex], heapContent[lChildIndex]) ) // if right child is prior than left child.
            {
                swap(parentIndex, rChildIndex);
                parentIndex = rChildIndex;
            }else /*if(heapContent[lChildIndex]>=heapContent[rChildIndex])*/ // else if left child is prior than right child.
            {
                swap(parentIndex, lChildIndex);
                parentIndex = lChildIndex;
            }

            lChildIndex = lChildPos(parentIndex);
            rChildIndex = rChildPos(parentIndex);
            ParentlessL = ((lChildIndex==-1)? false: IsFirstPrior(heapContent[lChildIndex], heapContent[parentIndex]) );
            ParentLessR = ((rChildIndex==-1)? false: IsFirstPrior(heapContent[rChildIndex], heapContent[parentIndex]) );
            /*ParentlessL = ((lChildIndex==-1)? false: (heapContent[parentIndex]<heapContent[lChildIndex]) );
            ParentLessR = ((rChildIndex==-1)? false: (heapContent[parentIndex]<heapContent[rChildIndex]) );*/

        }
    }
}

template<typename heapItem,typename compartor>
void kalashMaxHeap<heapItem,compartor>::swap(int oneBasedIndex, int oneBasedIndex2)
{
    heapItem temp = heapContent[oneBasedIndex];
    heapContent[oneBasedIndex] = heapContent[oneBasedIndex2];
    heapContent[oneBasedIndex2] = temp;
}

template<typename heapItem,typename compartor>
void kalashMaxHeap<heapItem,compartor>::print()
{
    for (int i = 1; i <= usedSlots; ++i)
    {
        cout << heapContent[i] << " ";
    }
}

template<typename heapItem,typename compartor>
bool kalashMaxHeap<heapItem,compartor>::isValid()
{

    int parentIndex = 0;
    while ( ++parentIndex <= usedSlots  )
    {
        if (isLeaf(parentIndex))
            continue;
        int lChildIndex = lChildPos(parentIndex);
        int rChildIndex = rChildPos(parentIndex);
        //IsFirstPrior(heapContent[parentIndex],heapContent[lChildIndex]); // heapContent[parentIndex]>heapContent[lChildIndex]
        //IsFirstPrior(heapContent[parentIndex], heapContent[rChildIndex]); // heapContent[parentIndex]>heapContent[rChildIndex]
        bool ParentGreaterEqL = ((lChildIndex==-1)? true: IsFirstPrior(heapContent[parentIndex], heapContent[lChildIndex]) || !IsFirstPrior(heapContent[lChildIndex], heapContent[parentIndex]) );
        bool ParentGreaterEqR = ((rChildIndex==-1)? true: IsFirstPrior(heapContent[parentIndex], heapContent[rChildIndex]) || !IsFirstPrior(heapContent[rChildIndex], heapContent[parentIndex]) );
        if( !ParentGreaterEqL || !ParentGreaterEqR)
            return false;
    }

    return true;

}

template<typename heapItem,typename compartor>
void kalashMaxHeap<heapItem,compartor>::heapSort()
{
    int sortedEnd = usedSlots;
    while(usedSlots>1)
    {
        remove(root);
    }
    usedSlots=sortedEnd;
}

template<typename heapItem,typename compartor>
bool kalashMaxHeap<heapItem,compartor>::isEmpty() {
    return (usedSlots==0);
}

template<typename heapItem,typename compartor>
bool kalashMaxHeap<heapItem,compartor>::isFull() {
    return (usedSlots==maxSize-1);
}

/*template<typename heapItem,typename compartor>
bool kalashMaxHeap<heapItem>::hasLeftChild(int oneBasedIndex)
{
    return ((2*oneBasedIndex)<=usedSlots);
}*/

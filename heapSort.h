//
// Created by Kalash on ١٧/٠٦/٢٠٢٢.
//

#ifndef DATA_STRUCTURES_HEAPSORT_H
#define DATA_STRUCTURES_HEAPSORT_H
#include "stdexcept"
#include "cmath"
#include "iostream"
using namespace std;

#define root  0

int heapEnd=-1;

int   parentPos (int index)
{
     if(index==root)
        throw std::logic_error("This is the root! \n");
     return( ceil((double) index/2.0)-1);
}
int   lChildPos (int index)
{
    /*
     * first we must make sure that this node has a left child,
     *    by calculating the left Child Pos and check if it is within the size of the Array or not.
     * If not, the function will return -1.
     * left child index = 2*parentIndex+1.
     */

    return ( ((2*index+1)<=heapEnd) ? (2*index+1):-1 );
}
int   rChildPos (int index)
{
    /*
    * first we must make sure that this node has a right child,
    * By calculating the right Child Pos and check if it is within the size of the Array or not.
    * If not, the function will return -1.
     * right child index = (2*parentIndex+2 ) or (lChildPos+1).
    */
    return (((2*index+2)<=heapEnd) ? (2*index+2):-1 );
}
bool  isFull    (int right) {
    return (heapEnd>=right);
}
bool  isLeaf    (int index)
{
    /*
     * A node will be a leaf if it does not have nether a left child nor a right child.
     *
     */
    int leftChild = lChildPos(index);
    int rightChild = rChildPos(index);
    if(leftChild==-1 && rightChild==-1)
        return true;
    return false;
}
int   getLevel  (int index)
{
    return floor(log2(index + 1));
}
bool  isEmpty   () {
    return (heapEnd==-1);
}

template<typename TypeSupportComp>
bool greaterIsPrior(TypeSupportComp first, TypeSupportComp second)
{
    /* Tips for creating a comparator function:
          * ---------------------------------------
          * Returns 'true' if first has more priority than second, and 'false' if second has more priority.
          * The item with high priority will be on the top(root) and when sorting it will swap to be at the last index,
          *   so if you want to sort in increasing order based on the priority ,consider making the less priority on the top(root),
          *   and do the revers with decreasing order sort.
          * If first > second  then first has more priority else second has more priority OR first = second in priority.
    */
    return (first > second) ;
}

template<typename heapItem>
void  swap(heapItem arr[], int index, int index2)
{
    heapItem temp = arr[index];
    arr[index] = arr[index2];
    arr[index2] = temp;
}

template<typename heapItem>
void  bubbleUp(heapItem arr[], int index, bool (*firstIsPrior)(heapItem first, heapItem second))
{
    int childIndex = index;
    if(childIndex != root)
    {
        int parentIndex = parentPos(childIndex);
        //IsFirstPrior(arr[childIndex],arr[parentIndex]); is equal to--> (arr[childIndex] > arr[parentIndex])
        while (  childIndex > root  && firstIsPrior(arr[childIndex],arr[parentIndex]) )  // while 'child' is prior keep going(bubble it up).
        {
            //cout << " انا هنا يا جو ";
            //cout << arr[childIndex] << " " <<childIndex<< " "<<parentIndex<<  endl;
            swap(arr,childIndex, parentIndex);
            //cout << "after swaping " << " " <<childIndex<< " "<<parentIndex<<  endl;

            childIndex = parentIndex;
            if(childIndex != root)  // if the condition is 'false' the parentIndex will not be updated and will be = childIndex and then this will break the loop condition
                parentIndex = parentPos(childIndex);

        }
    }
}

template<typename heapItem>
void bubbleDown(heapItem arr[], int index, bool (*firstIsPrior)(heapItem first, heapItem second))
{
    if(!isLeaf(index))
    {
        int parentIndex = index;
        int lChildIndex = lChildPos(parentIndex);
        int rChildIndex = rChildPos(parentIndex);
        // IsFirstPrior(arr[lChildIndex],arr[parentIndex]); // (arr[parentIndex]<arr[lChildIndex])
        // IsFirstPrior(arr[rChildIndex],arr[parentIndex]); // (arr[parentIndex]<arr[rChildIndex])
        bool ParentlessL = ((lChildIndex==-1)? false: firstIsPrior(arr[lChildIndex], arr[parentIndex]) );
        bool ParentLessR = ((rChildIndex==-1)? false: firstIsPrior(arr[rChildIndex], arr[parentIndex]) );
        while (!isLeaf(parentIndex) && (ParentlessL || ParentLessR)  )
        {
            //cout << "---------------------";
            if(lChildIndex==-1 )
            {
                swap(arr,parentIndex, rChildIndex);
                parentIndex = rChildIndex;
            }

            else if (rChildIndex==-1 )
            {
                swap(arr,parentIndex, lChildIndex);
                parentIndex = lChildIndex;
            }
                // IsFirstPrior(arr[rChildIndex],arr[lChildIndex])  // arr[rChildIndex]>arr[lChildIndex]
            else if ( firstIsPrior(arr[rChildIndex], arr[lChildIndex]) ) // if right child is prior than left child.
            {
                swap(arr,parentIndex, rChildIndex);
                parentIndex = rChildIndex;
            }
            else /*else if(arr[lChildIndex]>=arr[rChildIndex])*/ // else if left child is prior than right child.
            {
                swap(arr,parentIndex, lChildIndex);
                parentIndex = lChildIndex;
            }

            lChildIndex = lChildPos(parentIndex);
            rChildIndex = rChildPos(parentIndex);
            ParentlessL = ((lChildIndex==-1)? false: firstIsPrior(arr[lChildIndex], arr[parentIndex]) );
            ParentLessR = ((rChildIndex==-1)? false: firstIsPrior(arr[rChildIndex], arr[parentIndex]) );
            /*ParentlessL = ((lChildIndex==-1)? false: (arr[parentIndex]<arr[lChildIndex]) );
            ParentLessR = ((rChildIndex==-1)? false: (arr[parentIndex]<arr[rChildIndex]) );*/

        }
    }
}

template<typename heapItem>
void constructHeap(heapItem arr[],int& left, int right, bool (*firstIsPrior)(heapItem first, heapItem second))
{
    heapEnd=-1;
    while(!isFull(right))
    {
        //cout << "constructHeap ";
        heapEnd++;   // equal to--> arr[++heapEnd] = arr[left]; Because (heapEnd+1 = left)
        //cout << "heapEnd= "<< heapEnd<< endl;
        left++;
        bubbleUp(arr,heapEnd, firstIsPrior);
    }
}

template<typename heapItem>
void  removeRoot(heapItem arr[], bool (*firstIsPrior)(heapItem first, heapItem second))
{
    swap(arr,root,heapEnd);
    heapEnd--;
    bubbleDown(arr, root, firstIsPrior);
}

template<typename heapItem>
bool  isValid(heapItem arr[], bool (*firstIsPrior)(heapItem first, heapItem second))
{

    int parentIndex = -1;
    while ( ++parentIndex <= heapEnd  )
    {
        if (isLeaf(parentIndex))
            continue;
        int lChildIndex = lChildPos(parentIndex);
        int rChildIndex = rChildPos(parentIndex);
        //IsFirstPrior(arr[parentIndex],arr[lChildIndex]); // arr[parentIndex]>arr[lChildIndex]
        //IsFirstPrior(arr[parentIndex], arr[rChildIndex]); // arr[parentIndex]>arr[rChildIndex]
        bool ParentGreaterEqL = ((lChildIndex==-1)? true: firstIsPrior(arr[parentIndex], arr[lChildIndex]) || !firstIsPrior(arr[lChildIndex], arr[parentIndex]) );
        bool ParentGreaterEqR = ((rChildIndex==-1)? true: firstIsPrior(arr[parentIndex], arr[rChildIndex]) || !firstIsPrior(arr[rChildIndex], arr[parentIndex]) );
        if( !ParentGreaterEqL || !ParentGreaterEqR)
            return false;
    }

    return true;

}

template<typename heapItem>
void  heapSort(heapItem arr[],int left, int right, bool (*firstIsPrior)(heapItem first,  heapItem second)=greaterIsPrior)
/* Tips for creating a comparator function:
          * ---------------------------------------
          * Returns 'true' if first has more priority than second, and 'false' if second has more priority.
          * The item with high priority will be on the top(root) and when sorting it will swap to be at the last index,
          *   so if you want to sort in increasing order based on the priority ,consider making the less priority on the top(root),
          *   and do the revers with decreasing order sort.
          * By default, If first > second  then first has more priority else second has more priority OR first = second in priority.
*/
{
    constructHeap(arr,left,right,firstIsPrior);
    int tempEnd = heapEnd;
    while(heapEnd>=0)
    {
        removeRoot(arr, firstIsPrior);
    }
    heapEnd=tempEnd;
}













#endif //DATA_STRUCTURES_HEAPSORT_H

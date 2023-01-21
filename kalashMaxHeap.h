//
// Created by Kalash on ٢٩/٠٥/٢٠٢٢.
//

#include "string"
using namespace std;
#ifndef DATA_STRUCTURES_KALASHMAXHEAP_H
#define DATA_STRUCTURES_KALASHMAXHEAP_H

class defaultCompartor
{
public:
    /* compartor:
     *      it should return true "only" if the first parameter is 'prior than' or 'equal to' the second
     */
    template<typename TypeSupportComp>
    bool operator()(TypeSupportComp first, TypeSupportComp second)
    {
        /* Tips for creating a comparator functor:
         * ---------------------------------------
         * Returns 'true' if first has more priority than second, and 'false' if second has more priority.
         * The item with high priority will be on the top(root) and when sorting it will swap to be at the last index,
         *   so if you want to sort in increasing order based on the priority ,consider making the less priority on the top(root),
         *   and do the revers with decreasing order sort.
         * If first < second  then has more priority else second has more priority OR first = second in priority.
        */
        return (first < second) ;
    }
};





template<typename heapItem,typename compartor= defaultCompartor>
class kalashMaxHeap
{
private:
    int usedSlots;  // one Based.
    int maxSize;    // zero base, and the usable slots starts from [1 : maxSize-1].
    heapItem* heapContent ; // the first position is left empty ,and we start indexing from index 1.
    compartor IsFirstPrior;

    // helper funs
    void bubbleUp(int oneBasedIndex);
    void bubbleDown(int oneBasedIndex);
    void swap(int oneBasedIndex,int oneBasedIndex2);
    //bool hasLeftChild(int oneBasedIndex);
public:
    kalashMaxHeap    ()=delete;
    kalashMaxHeap    (int elementsNum, const heapItem* array );
    explicit kalashMaxHeap    (int maxSize );
    int  parentPos   (int oneBasedIndex )const;
    int  lChildPos   (int oneBasedIndex )const;
    int  rChildPos   (int oneBasedIndex )const;
    bool isLeaf      (int oneBasedIndex)const;
    int  getLevel    (int oneBasedIndex)const;
    int  getHeight   ()const;
    bool isEmpty     ();
    bool isFull      ();
    void insert      (heapItem item);
    void insert      (int elementsNum, const heapItem* array);
    heapItem getRoot ();
    heapItem getAndRemoveRoot();
    void remove      (int oneBasedIndex);
    bool isValid     ();
    void heapSort    ();
    void print       ();

};




#endif //DATA_STRUCTURES_KALASHMAXHEAP_H

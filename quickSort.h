//
// Created by Kalash on ٠٥/٠٦/٢٠٢٢.
//

#ifndef DATA_STRUCTURES_QUICKSORT_H
#define DATA_STRUCTURES_QUICKSORT_H
    void swap(int arr[],int firstIndex, int secondIndex)
    {
        int temp =arr[firstIndex];
        arr[firstIndex]=arr[secondIndex];
        arr[secondIndex]=temp;
    }
void partitioning(int arr[], int left, int& midIndex, int right, char mode='a')  // the fun will tell us what is the value of midIndex, not we, so it was passed by ref.
{
    /*
     * we have 2 sets set1 and set2:
     * set1 is (the less than subArray). If it is not empty, It starts with left+1.
     * set2 is (the greater than subArray). 's2' points to the 1st item in set2.
     */
    int i=left+1,
            pivotIndex=left,
            s2=left+1; // it always points to the 1st item in set2 (the greater than subArray).if set2 is empty then 's2' points to 'right+1'. So 's2-1' points to the last item in set1(the less than subArray)
    while (i<=right)
    {
        if(mode=='a')
        {
            if (arr[i] < arr[pivotIndex]) {
                swap(arr, i, s2);
                s2++;
            }
        }
        else if(mode=='d')
        {
            if (arr[i] > arr[pivotIndex]) {
                swap(arr, i, s2);
                s2++;
            }
        }
        i++;
    }
    swap(arr,pivotIndex,s2-1);
    pivotIndex=s2;
    midIndex=pivotIndex;  // midIndex=s2
}
void quicksort(int arr[],int left,int right,char mode='a')
{
    if(left>=right)
        return;
    int mid;
    partitioning(arr,left,mid,right,mode);
    int leftSubArrEnd= mid - 1;
    int RightSubArrStart= mid + 1;
    quicksort(arr, left, leftSubArrEnd,mode);
    quicksort(arr, RightSubArrStart, right,mode);

}


//-----------------------------------------------------------------------------------
void swapMe(int& a, int& b){ int temp = a; a=b; b=temp; }
int partitioning (vector<int>& arr,int left,  int right)
{
    int pivot = left;

    for (int i = left+1; i <= right ; ++i) {
        if(arr[i] < arr[pivot]){
            swapMe(arr[pivot+1], arr[i]);
            swapMe(arr[pivot], arr[pivot+1]);
            pivot++;
        }
    }
    return pivot;
}

void quickSort(vector<int>& arr,int left,  int right)
{
    if(left >= right){ return;}

    int pivot = partitioning(arr, left, right);
    quickSort(arr, left, pivot-1);
    quickSort(arr, pivot+1, right);

    if(left<pivot-1) { for (int i = left; i < pivot; i++) { cout << arr[i] << " "; }}
    if(left<pivot-1) { cout << endl; }
    if(right > pivot+1) { for (int i = pivot + 1; i <= right; i++) { cout << arr[i] << " "; }}
    if(right > pivot+1) { cout << endl; }
}

//-----------------------------------------------------------------------------------
















#endif //DATA_STRUCTURES_QUICKSORT_H

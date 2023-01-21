//
// Created by Kalash on ٠٣/٠٦/٢٠٢٢.
//
#include "iostream"
#include <bits/stdc++.h>
using namespace std;
#ifndef DATA_STRUCTURES_MERGESORT_H
#define DATA_STRUCTURES_MERGESORT_H


vector<int> tempArr(1e5+10);
void mergee (vector<int>& arr, int left, int mid, int right)
{
    // mid is included in the left subArray, and the right subArray starts from mid+1;
    int l_idx = left, r_idx = mid+1, tempArr_idx = left;

    // merging to sorted parts in one sorted part that is tempList.
    while(l_idx<=mid && r_idx <= right){
        if( arr[l_idx] <= arr[r_idx]) { tempArr[tempArr_idx++] = arr[l_idx++]; }
        else {  tempArr[tempArr_idx++]=arr[r_idx++];
        }
    }

    // pushing the remaining items in each of the two parts if any.
    while (l_idx <= mid ) { tempArr[tempArr_idx++] = arr[l_idx++]; }
    while (r_idx <= right){ tempArr[tempArr_idx++] = arr[r_idx++]; }

    // putting them pack in their original place
    for (int i = left, j=left; i <= right ; ++i, ++j) { arr[i] = tempArr[j]; }

}

void mergeSort(vector<int>& arr, int left, int right)
{

    if(left >= right){ return;}

    int mid = left + (right-left)/2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);

    mergee(arr, left, mid, right);

}




















#endif //DATA_STRUCTURES_MERGESORT_H

/*
 * QuickSort.h
 *
 *  Created on: 22.12.2016
 *      Author: nlz
 */

#ifndef HEADERS_QUICKSORT_H_
#define HEADERS_QUICKSORT_H_



template<std::size_t N, typename T>
size_t hoare_partition(std::array<T, N>& arr, size_t p, size_t r){
    T x = arr[p];
    size_t i = p - 1;
    size_t j = r + 1;
    //hoare_partition
    while(true){
        do{
            j--;
        }while(arr[j] > x);
        do{
            i++;
        }while(arr[i] < x);
        if(i < j){
        	std::swap(arr[i],arr[j]);
        }
        else
            return j;
    }
}

template<std::size_t N, typename T>
void startquickSort(std::array<T, N>& arr, size_t p, size_t r){
    if(p < r){
        size_t q = hoare_partition(arr, p, r);
        startquickSort(arr, p, q);
        startquickSort(arr, q+1, r);
    }
}

template<std::size_t SIZE, typename T>
void quickSort(std::array<T, SIZE>& arr){
        startquickSort(arr, 0, SIZE-1);
}

#endif /* HEADERS_QUICKSORT_H_ */

/*
 * QuickSort.h
 *
 *  Created on: 22.12.2016
 *      Author: nlz
 */

#ifndef HEADERS_QUICKSORT_H_
#define HEADERS_QUICKSORT_H_

#include "CheckArrrays.h"
#include "ButtomUpMergesort.h"
#include "Constants.h"

template<typename T, std::size_t N>
void threeWaySort(std::array<T, N> &a, size_t l, size_t r) {

	if (r <= l) {
		return;
	}

	size_t i = l - 1;
	size_t j = r;
	size_t p = l;
	size_t q = r - 1;

	std::swap(a[(l + r) / 2], a[r]);
	T v = a[r];

	for (;;) {
		while (a[++i] < v)
			;

		while (v < a[--j]) {
			if (j == l)
				break;
		}
		if (i >= j) {
			break;
		}

		std::swap(a[i], a[j]);

		if (a[i] == v) {
			std::swap(a[p], a[i]);
			p++;
		}
		if (v == a[j]) {
			std::swap(a[j], a[q]);
			q--;
		}
	}

	std::swap(a[i], a[r]);

	j = (i == 0) ? 0 : (i - 1);
	i = i + 1;

	for (size_t k = l; k < p; k++) {
		std::swap(a[k], a[j]);
		if (j > 0) {
			j--;
		}
	}

	for (size_t k = r - 1; k > q; k--, i++) {
		std::swap(a[i], a[k]);
	}

	threeWaySort(a, l, j);
	threeWaySort(a, i, r);
}

template<std::size_t N, typename T>
void threeWaySortHybrid(std::array<T, N> &a,std::array<T, N> &wrkArray, size_t l, size_t r) {
	if (r <= l) {
		return;
	}
	if ((r - l) <= SWITCH_SORT_ALGO) {
		insertionSortPrefetchIndexes(a, l, r);
	} else {
		size_t i = l - 1;
		size_t j = r;
		size_t p = l;
		size_t q = r - 1;

		std::swap(a[(l + r) / 2], a[r]);
		T v = a[r];

		for (;;) {
			while (a[++i] < v)
				;

			while (v < a[--j]) {
				if (j == l)
					break;
			}
			if (i >= j) {
				break;
			}

			std::swap(a[i], a[j]);

			if (a[i] == v) {
				std::swap(a[p], a[i]);
				p++;
			}
			if (v == a[j]) {
				std::swap(a[j], a[q]);
				q--;
			}
		}

		std::swap(a[i], a[r]);

		j = (i == 0) ? 0 : (i - 1);
		i = i + 1;

		for (size_t k = l; k < p; k++) {
			std::swap(a[k], a[j]);
			if (j > 0) {
				j--;
			}
		}

		for (size_t k = r - 1; k > q; k--, i++) {
			std::swap(a[i], a[k]);
		}


		if (( (j - l) > (WORST_CASE_CONST * (r - i)) )
				|| (    (r - i) >   ( (j - l) * WORST_CASE_CONST))) {
			size_t middle = (l + r) / 2;
			threeWaySortHybrid(a,wrkArray, l, middle);
			threeWaySortHybrid(a,wrkArray, middle + 1, r);
			mergeBitonic(a, wrkArray, middle + 1, l, r);
		} else {
			threeWaySortHybrid(a,wrkArray, l, j);
			threeWaySortHybrid(a,wrkArray, i, r);
		}
	}
}

template<typename T, std::size_t N>
void quicksortHybrid(std::array<T, N> &a) {
	std::shared_ptr<std::array<T, N>> wrkArray(new std::array<T, N>);
	threeWaySortHybrid(a,*wrkArray, 0, N - 1);
}

template<std::size_t N, typename T>
void quickSort(std::array<T, N> &a) {
	threeWaySort(a, 0, (N - 1));
}

#endif /* HEADERS_QUICKSORT_H_ */

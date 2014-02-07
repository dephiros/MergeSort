/**
 * Implement mergesort algorithm from Intro to Design & Analysis of Algorithm 3e
 * Second implementation with better memory management
 * Inspired by http://vinayakgarg.wordpress.com/2012/11/08/merge-sort-program-in-c/
 */

#include <stdlib.h>
#include <stdio.h>

void mergeSort(int *, int, int);
void merge(int * , int, int, int);

int main() {
  int testArray[10] = {10, 5, 9, 2, 0, 6, 7, 4, 8, 3};
  int i;
  for (i = 0; i < 10; i++) printf("%d ", testArray[i]);
  printf(" test array \n");
  mergeSort(testArray, 0, 9);
  for (i = 0; i < 10; i++) {
    printf("%d ", testArray[i]);
  }
  printf("\n");
}

void mergeSort(int * a, int left, int right) {
  int len = right - left + 1;
  int mid = (right + left) / 2;
  if (len > 1) {
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
  }

}

void merge(int * a, int left, int mid, int right) {
  int * temp = (int *) malloc(sizeof(int) * (right - left + 1));
  int i = left, j = mid + 1, k = 0;
   while (i <= mid && j <= right) {
    if (a[i] <= a[j]) {
      temp[k] = a[i];
      i++;
    } else {
      temp[k] = a[j];
      j++;
    }
    k++;
  }
  while (i <= mid) {
    temp[k] = a[i];
    i++; k++;
  }
  while (j <= right) {
    temp[k] = a[j];
    j++; k++;
  }
  k--;
  while(k >= 0) {
    a[left + k] = temp[k];
    k--;
  }
  free(temp);
}

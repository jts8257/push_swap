#include <stdlib.h>

void merge(int *arr, int *sorted, int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;
    
    while(i<=mid && j<=right){
        if(arr[i]<=arr[j])
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }

  if(i>mid){
      for(l=j; l<=right; l++)
        sorted[k++] = arr[l];
    } else {
        for(l=i; l<=mid; l++)
        sorted[k++] = arr[l];
    }
    
    for(l=left; l<=right; l++) {
        arr[l] = sorted[l];
    }
}

void merge_sort(int *arr, int *stored, int left, int right) {
    int mid;
    if (left<right) {
        mid = (left + right) / 2;
        merge_sort(arr, stored, left, mid);
        merge_sort(arr, stored, mid + 1, right);
        merge(arr, stored, left, mid, right);
    }
}

int *sort(int *arr, int size) {
    int *stored = (int *)malloc(sizeof(int) * size);
    if (stored == NULL)
        exit (1);
    merge_sort(arr, stored, 0, size - 1);
    free(stored);
    stored = NULL;
    return arr;
}
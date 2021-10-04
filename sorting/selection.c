int *sort(int *arr, int size) {
    int min;
    int tmp;
    int pos = 0;
    for (int i = 0 ; i < size - 1 ; i++) {
        min = arr[i];
        for (int j = i + 1 ; j < size ; j++) {
            if (arr[j] < min) {
                pos = j;
            }
        }
        if (i != pos) {
            SWAP(arr[i], arr[pos], tmp);
        }
    }
    return arr;
}

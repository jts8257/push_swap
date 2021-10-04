int *sort(int *arr, int size) {
    int key_idx, key_value, i;

    for (key_idx = 1; key_idx < size ; key_idx++) {
        key_value = arr[key_idx];
        for (i = key_idx - 1; i >= 0 && arr[i] > key_value ; i--) {
          arr[i+1] = arr[i];
        }
        arr[i+1] = key_value;
    }
    return arr;
}
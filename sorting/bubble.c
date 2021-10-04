// 버블정렬
// 인접한 2개의 레코드를 비교하여 크기가 순서대로 되어 있지 않으면 서로 교환한다.
// 0 번째 원소와 1번째 원소를 비교 후 정렬 .... n-1 번째 원소와 n 번째 원소를 비교 후 정렬
// O(n^2)
// 버블정렬은 거의 모든 상황에서 최악의 성능을 보여주지만, 이미 정렬된 자료에서는 1번만 순회하면 되기 때문에 최선의 성능을 보여주는 알고리즘이다.

# define SWAP(x, y, tmp) ( (tmp)=(x), (x)=(y), (y)=(tmp))

int *sort(int *arr, int size) {
    int tmp;

    for(int i = 0 ; i < size ; i++) {
        for (int j = i + 1; j < size ; j++) {
            if (arr[i] > arr[j]) {
                SWAP(arr[i], arr[j], tmp);
            }
        }
    }
    return arr;
}
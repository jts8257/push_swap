# define SWAP(x, y, tmp) ( (tmp)=(x), (x)=(y), (y)=(tmp) )

int pivoting(int *arr, int left, int right, int trial ) {
    int pivot = arr[left]; //초기 pivot 0번째 인덱스 값으로 지정함.
    int low = left + 1; int high = right; // 피봇을 기준으로 정렬할 양쪽 끝의 인덱스 값을 할당.
    int tmp;
    // low 와 high 가 교차할때까지 loop 를 돌리면서 pivot 이 가리키는 값을 기준으로 작은 값은 왼쪽, 큰 값은 오른쪽으로 정렬함.
    while (low < high) {
        // low 인덱스 값이 최대값(right)을 넘지 않은 수준에서, low 인덱스가 가리키는 값이 pivot 이 가리키는 값보다 클때까지 low 의 인덱스를 증가시킴
       while (low <= right && arr[low] < pivot)
           low++;
        // high 인덱스 값이 최소값(left)을 넘지 않은 수준에서, high 인덱스가 가리키는 값이 pivot 이 가리키는 값보다 작을때까지 high 의 인덱스를 감소시킴
        while (high >= left && arr[high] > pivot)
            high--;
        // 위의 두 loop 가 끝났을 때 low 인덱스가 high 인덱스보다 작은 상황이라면, 두 인덱스가 가리키는 값을 교환함.
        if (low < high) {
            SWAP(arr[low], arr[high], tmp);
        }
    }
    // pivot(arr[left]) 의 값을 중앙으로 옮김.
    if (arr[left] > arr[high])
        SWAP(arr[left], arr[high], tmp);
    // 중앙 idx 값을 반환
    return high;
}

void quick_sort(int *arr, int left, int right, int trial) {
    if (left < right) {
        int p = pivoting(arr, left, right, trial);
        quick_sort(arr, left, p - 1,  ++trial);
        quick_sort(arr, p + 1, right,  ++trial);
    }
}

int *sort(int *arr, int size) {
    quick_sort(arr, 0, size-1, 1);
    return arr;    
}
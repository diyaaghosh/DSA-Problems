#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void maxheapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxheapify(arr, n, largest);
    }
}


void build_max_heap(vector<int>& heap, int k) {
    for (int i = k / 2 - 1; i >= 0; i--) {
        maxheapify(heap, k, i);
    }
}

int kth_smallest(vector<int>& arr, int n, int k) {
    vector<int> heap(arr.begin(), arr.begin() + k);
    build_max_heap(heap, k);

    for (int i = k; i < n; i++) {
        if (arr[i] < heap[0]) { 
            heap[0] = arr[i]; 
            maxheapify(heap, k, 0);
        }
    }
    return heap[0]; 
}

int main() {
    int n;
    cout << "Enter dimension: ";
    cin >> n;

    vector<int> arr(n);
    int mx, mn;
    cout << "Enter maximum value of array element: ";
    cin >> mx;
    cout << "Enter minimum value of array element: ";
    cin >> mn;

    srand(time(0));
    cout << "Generated array: ";
    for (int i = 0; i < n; i++) {
        int random_val = mn + (rand() % (mx - mn + 1));
        arr[i] = random_val;
        cout << arr[i] << " ";
    }
    cout << endl;

    int k;
    cout << "Enter k: ";
    cin >> k;

    while (k <= 0 || k > n) {
        cout << "Invalid k, enter again: ";
        cin >> k;
    }

    int ans = kth_smallest(arr, n, k);
    cout << k << "th smallest element: " << ans << endl;

    return 0;
}

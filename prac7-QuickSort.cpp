#include <iostream>
#include <vector>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int pivot = arr[high];
    int i = low - 1;

    // Partition the array
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot at its correct position
    swap(arr[i + 1], arr[high]);

    int pi = i + 1;

    // Recursive calls
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr.data(), 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
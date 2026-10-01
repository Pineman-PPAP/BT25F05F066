#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the two sorted halves
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= right)
        temp.push_back(arr[j++]);

    for (int k = 0; k < (int)temp.size(); k++)
        arr[left + k] = temp[k];
}

int main() {
    int choice, n;

    cout << "1. Bubble Sort\n";
    cout << "2. Merge Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        cout << "Invalid choice!\n";
        return 0;
    }

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of elements must be positive.\n";
        return 0;
    }

    vector<int> arr(n);

    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    switch (choice) {
        case 1:
            bubbleSort(arr);
            break;

        case 2:
            mergeSort(arr, 0, n - 1);
            break;
    }

    cout << "Sorted array: ";
    for (int value : arr)
        cout << value << " ";

    cout << '\n';
    return 0;
}
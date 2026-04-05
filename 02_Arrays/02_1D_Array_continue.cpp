#include <iostream>
#include <algorithm> // For sort()
using namespace std;

int main() {
    // 1. One Dimensional Array (continued)
    int arr[] = {15, 3, 9, 8, 12}; // 2. Omit Array Size

    // 2. Foreach loop
    cout << "Array elements using foreach loop:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    // 3. Omit Elements on declaration
    int arr2[5]; // declare empty array
    for(int i = 0; i < 5; i++) arr2[i] = i+1;

    // 4. Get the size of an array
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Size of array: " << size << endl;

    // 5. Loop through array with sizeof()
    cout << "Elements using sizeof loop:\n";
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 6. Arithmetic operations on arrays
    int sum = 0;
    for(int i = 0; i < size; i++) sum += arr[i];
    cout << "Sum of array: " << sum << endl;

    // 7. Searching in arrays
    int key = 9;
    bool found = false;
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            found = true;
            cout << "Sequential Search: Found " << key << " at index " << i << endl;
            break;
        }
    }

    // 8. Binary search (array must be sorted first)
    sort(arr, arr + size);
    bool binFound = binary_search(arr, arr + size, key);
    cout << "Binary Search: " << (binFound ? "Found" : "Not Found") << endl;

    // 9. Sorting arrays
    // Ascending order
    sort(arr, arr + size);
    cout << "Ascending order: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    // Descending order
    sort(arr, arr + size, greater<int>());
    cout << "Descending order: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    // 10. Selection sort
    int selArr[] = {29, 10, 14, 37, 13};
    int selSize = sizeof(selArr)/sizeof(selArr[0]);
    for(int i = 0; i < selSize-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < selSize; j++) {
            if(selArr[j] < selArr[minIdx]) minIdx = j;
        }
        swap(selArr[i], selArr[minIdx]);
    }
    cout << "Selection Sort: ";
    for(int x : selArr) cout << x << " ";
    cout << endl;

    // 11. Bubble sort
    int bubArr[] = {5, 1, 4, 2, 8};
    int bubSize = sizeof(bubArr)/sizeof(bubArr[0]);
    for(int i = 0; i < bubSize-1; i++) {
        for(int j = 0; j < bubSize-i-1; j++) {
            if(bubArr[j] > bubArr[j+1]) swap(bubArr[j], bubArr[j+1]);
        }
    }
    cout << "Bubble Sort: ";
    for(int x : bubArr) cout << x << " ";
    cout << endl;

    return 0;
}
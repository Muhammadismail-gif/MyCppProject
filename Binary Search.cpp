#include <iostream>
using namespace std;
    int binarySearch(int arr[], int n, int target) {
    int low = 0;        
    int high = n - 1;    
    
    while (low <= high) {
       int mid = (low + high) / 2;  
        
        if (arr[mid] == target)      
            return mid;
        else if (target < arr[mid])  
            high = mid - 1;
        else                         
            low = mid + 1;
    }  
    return -1;  
    };
    int main() {
    
    int arr[12] = {15, 18, 22, 24, 25, 28, 32, 40, 0, 0, 0, 0};
    int n = 8;
    int target = 22;
    
    int result = binarySearch(arr, n, target);
    
cout << "22 found on index :" << result;
      return 0;
   }

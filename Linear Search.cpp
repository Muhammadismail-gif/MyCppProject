#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) 
{
    for(int i = 0; i < n; i++) 
    {
        if(arr[i] == target)
            return i; 
    	}
	    return -1; 
}
int main() 
{
    
    int arr[12] = {15, 18, 22, 24, 25, 28, 32, 40, 0, 0, 0, 0};
    int n = 8;
    int target = 25;
    int result = linearSearch(arr, n, target);
    cout << "25 are in Indux " << result;
}

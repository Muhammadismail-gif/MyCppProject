#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	
	int A[12] = {15, 18, 22, 24, 25, 28, 32, 40, 0, 0, 0, 0};
    int N = 8; //Current No of elements
	// Reverse the array using built-in function
    reverse(A, A + N);
   // Print the reversed array
	for (int i = 0; i < N; i++)
        	cout << A[i] << " ";

    return 0;
}
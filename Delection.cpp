#include <iostream>
using namespace std;

int main(){
	
	int A[12] = {15, 18, 22, 24, 25, 28, 32, 40, 0, 0, 0, 0};
    int N = 8; //Current No of elements
	int K = 1; // Delete element at index 2
    //Step-1: store item to be deleted
	int ITEM=A[K]; 
    //step-2: shift elements left
    for(int J=K; J<N; J++){
    A[J]=A[J+1];
    }
    // STEP-3: REDUCE the Arry Size
    N=N-1;
    // Output final array
    cout<<"Array Before Delection:15, 18, 22, 24, 25, 28, 32, 40, 0, 0, 0, 0 \n";
    cout<<"Array After Delection:";
    for(int i=0;i<N;i++){
    	cout<<A[i]<<" ";
	}
	cout<<"\nDeleted item:"<<ITEM<<endl;
    return 0;
}
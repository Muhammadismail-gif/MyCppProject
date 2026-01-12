#include <iostream>
using namespace std;

int main(){
	
	int A[12] = {15, 18, 22, 24, 25, 28, 32, 40, 0, 0, 0, 0};
    int N = 8; 
	int K = 3;
	int ITEM = 23;
    int j = N - 1;
 while (j>=K) {
 	A[j+1]=A[j];
 	j=j-1;
 }
 A[K]=ITEM;
 N = N + 1;
 cout<<"Arry Befor Insertion:15 18 22 24 25 28 32 40 \n";
 cout<<"Arry After Insertion:";
 for(int i=0; i < N; i++){
 	cout<<A[i]<<" ";
 	
 }
    return 0;
}
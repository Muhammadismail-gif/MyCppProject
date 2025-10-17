#include <iostream>
#include <windows.h>
using namespace std;

 int main(){
 

int duration = 500;
int elapsed = 0;

while (elapsed < duration){
	Beep(1000,300);
	Beep(1200,300);
}
	elapsed += 300;
}
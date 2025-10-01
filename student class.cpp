#include <iostream>
using namespace std;

class student {
public: 
string name;
int rollNumber;
float mark;

void display(){
	cout<<" Student Name : "<<name<<endl;
	cout<<" Roll Number : "<<rollNumber<<endl;
	cout<<" Mark : "<<mark;
}
};

int main(){
	
	student s1;
	s1.name= "ismail";
	s1.rollNumber= 101;
	s1.mark= 87.5;
	s1.display();
	return 0;
}
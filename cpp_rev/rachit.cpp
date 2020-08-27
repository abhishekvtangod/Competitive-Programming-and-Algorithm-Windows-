#include<iostream>
using namespace std;

/*
	Given a class A, we want to know at any time, how many objects of A live in the "heap" memory.
*/

class A{
public:
	static int x ;
	A(){
		// x++;
	}
	~A(){
		x--;
	}
	void* operator new (size_t sz){
		x++;
	}


};

int A::x = 0;

int main(){

	A a,b,c;
	A* temp1 = new A;
	A* temp2 = new A;
	cout<<A::x;

	return 0;
}
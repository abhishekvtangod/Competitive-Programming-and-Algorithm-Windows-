#include<bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif

	srand(time(NULL)); 

	long long int n = 1 + rand() % (100000); 
	long long int d = 1 + rand() % (1000000000); 

	cout<<n<<" "<<d<<endl;
	for (int j=1; j<=n; j++) 
		cout<<rand()%(1000000000000000);

	cout<<endl;

	return(0); 
} 

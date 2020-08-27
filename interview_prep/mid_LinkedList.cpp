/**
 *    author:  abhishekvtangod
 *    created:        
**/

#include<bits/stdc++.h>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)

typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset<pair<ll,ll>> indexed_set;


#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };


struct Node
{
	int val;
	Node* next;
	
	
	Node():val(0),next(NULL){}
	Node(int x):val(x),next(NULL){}
	Node(int x,Node* nex):val(x),next(nex){}
	
};

ll mid(Node* root)
{
	Node* a=root;
	Node *b=root;
	
	while(b!=nullptr)
	{
		//a++
		//b++
		//b++
		b=b->next;

		if(b==nullptr)
			return a->val;
		
		a=a->next;
		b=b->next;
		
	}
	return a->val;	
	
}

void solve()
{
	Node* root=new Node(1);
	Node* ptr= root;
	
	
	ptr->next = new Node(2);ptr=ptr->next;
	ptr->next = new Node(3);ptr=ptr->next;
	ptr->next = new Node(4);ptr=ptr->next;
	ptr->next = new Node(5);ptr=ptr->next;
	ptr->next = new Node(6);ptr=ptr->next;
	ptr->next = new Node(7);ptr=ptr->next;
	
	//ptr->next = new Node(8);ptr=ptr->next;

	Node* a=root;
	while(a!=nullptr)
	{
		cout<<a->val<<" ";
		a=a->next;
	}
	cout<<endl;
	cout<<"Mid: "<<mid(root)<<endl;
	

}


int main()
{   
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	//ll t;cin>>t;
	//while(t--)
	//{
		solve();
	//}
	

    return 0;
}

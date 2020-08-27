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
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define debug(x) cerr<<#x<<": "<<x<<" "<< endl;

typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset<pair<ll,ll>> indexed_set;

// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(-1),left(nullptr),right(nullptr) {}
	TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
};

TreeNode* insertLevelOrder(vector<int> v,TreeNode* root, int i , int n){
	if(i<n){
		TreeNode* temp = new TreeNode(v[i]);
		root = temp;

		root -> left = insertLevelOrder(v,root->left,2*i+1,n);
		root -> right = insertLevelOrder(v,root->right,2*i+2,n);
	}
	return root;
}

void preorder(TreeNode* root){
	if(!root){
		return;
	}
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

void iter_preorder(TreeNode* root){
	TreeNode* curr = root;
	stack<TreeNode*> s;
	while(curr || s.empty() == false){
		while(curr){
			cout<<curr->val<<" ";
			s.push(curr);
			curr = curr -> left;
		}
		curr = s.top();
		s.pop();
		
		curr = curr->right;

	}
}

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i =0 ;i<n;i++){
		cin>>v[i];
	}
	TreeNode* root = insertLevelOrder(v,root,0,n);


	cout<<"Recursive Preorder: ";
	preorder(root);
	cout<<endl;

	cout<<"Iterative Preorder: ";
	iter_preorder(root);
	cout<<endl;


}


int main()
{   
	IOS;

	#ifndef ONLINE_JUDGE
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\input.txt", "r", stdin);
		freopen("C:\\Users\\Thangod\\Desktop\\zAbhi\\output.txt", "w", stdout);
	#endif


	// ll t;cin>>t;
	// while(t--)
	// {
		solve();
	// }
	

    return 0;
}
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

void postorder(TreeNode* root){
	if(!root){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->val<<" ";

}

void iter_postorder(TreeNode* root){

	unordered_map<TreeNode*,int> mp;
	stack<TreeNode*> s;


	s.push(root);
	while(s.empty()==false){
	
		TreeNode* curr = s.top();

		if(curr == nullptr){
			s.pop();continue;
		}


		if(mp[curr] == 0){
			s.push(curr->left);
		}
		else if(mp[curr] == 1){
			s.push(curr->right);
		}
		else if(mp[curr] == 2){
			cout<<curr->val<<" ";
		}
		else{
			s.pop();
		}

		mp[curr]++;

	}


}


// dfs:
// 	dfs->left
// 	dfs->right
// 	print data

//	 	  1
// 	  2	      3
//  4  5    6   7

void optimised_iter(TreeNode* root){
	stack<pair<TreeNode*,int>> s;

	s.push({root,0});
	while(s.empty()==false){
		TreeNode* curr = s.top().first;
		int state = s.top().second;

		s.pop();

		if(curr == nullptr || state == 3){
			continue;
		}

		s.push({curr,state+1});

		if(state == 0){
			s.push({curr->left,0});
		}
		else if(state == 1){
			s.push({curr->right,0});
		}
		else if(state == 2){
			cout<<curr->val<<" ";
		}

		

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


	cout<<"Recursive Postorder: ";
	postorder(root);
	cout<<endl;

	cout<<"Iterative Postorder: ";
	iter_postorder(root);
	cout<<endl;

	cout<<"Space Optimised Iterative Postorder: \n";
	optimised_iter(root);
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
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

struct ListNode{
	int val;
	ListNode *next;
	ListNode(): val(-1),next(nullptr){}
	ListNode(int x): val(x), next(nullptr){}
};

ListNode* reverse(ListNode* head){
	ListNode* prev = nullptr;
	ListNode* cur = head;
	ListNode* nxt = nullptr;
	while(cur!=nullptr){
		nxt=cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	return prev;
}
ListNode* middlee(ListNode* head){

    if(head == nullptr){
        return nullptr;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    
    while(fast->next!=nullptr){
        fast = fast->next;
        if(fast->next == nullptr){
            return slow;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

void solve(){
	int n;cin>>n;
	ListNode* head = new ListNode();
	ListNode* curr = head;
	for(int i =0;i<n;i++){
		int t;cin>>t;
		ListNode* temp = new ListNode(t);

		curr->next = temp;
		curr=curr->next;
	}
	ListNode* a = head->next;
	ListNode* b = middlee(a);

	b = reverse(b);	
	while(b!=nullptr && a!=nullptr){
		if(b->val != a->val){
			cout<<"NO"<<endl;
			return;
		}
		a=a->next;
		b=b->next;
	}
	cout<<"YES"<<endl;


}



int main()
{   
	IOS;
 
 	#ifndef ONLINE_JUDGE
		freopen("/home/abhi/Documents/input.txt", "r", stdin);
		freopen("/home/abhi/Documents/output.txt", "w", stdout);
	#endif 
 
	// ll t;cin>>t;
	// while(t--){
		solve();
	// }
	
 
    return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#define ll long long
using namespace std;
 
void solve(){

		ll n, l, r, e, o;
		string s;
		cin >> n >> s;
		l = 0;
		r = n;
		e = 0;
		o = 0;
		deque<char> q;
		vector<ll> ans;
 
		for(int i = 0; i < n; i++){
				if(s[i] == '0') e++;
				else o++;
				q.push_back(s[i]);
		}

		if(e != o){
				cout << -1 << '\n';
				return;

		}
		
 

		// 110001
		// 01 110001
		// 1 11000
		//  1100
		while(!q.empty()){

				if(q.front() == '0' && q.back() == '0'){

						q.push_back('0');
						q.push_back('1');
						ans.push_back(r);
						r += 2;

 
				}
				else if(q.front() == '1' && q.back() == '1'){
						q.push_front('1');

						q.push_front('0');
						ans.push_back(l);
						r += 2;
				}
				else{
						q.pop_front();
						q.pop_back();
						l++;
						r--;
				}
		}
				

				
		cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); i++){
				cout << ans[i] << ' ';
				if(i == ans.size() - 1) cout << '\n';
		}

}
 
int main(){
		ll t;
		cin >> t;
		while(t--) solve();

}

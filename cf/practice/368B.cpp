#include<iostream>
#include<set>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

int main(){
		ll n, m, dp[N], a[N], l;
		cin >> n >> m;
		for(int i = 0; i < n; i++) cin >> a[i];
		set<ll> S;
		S.insert(a[n - 1]);
		dp[n - 1] = 1;

		for(int i = n - 2; i >= 0; i--){
				if(S.find(a[i]) != S.end()){
						dp[i] = dp[i + 1];
				}
				else{
						S.insert(a[i]);
						dp[i] = dp[i + 1] + 1;
				}
		}
		
		for(int i = 0; i < m; i++){
				cin >> l;
				l--;
				cout << dp[l] << '\n';
		}




}




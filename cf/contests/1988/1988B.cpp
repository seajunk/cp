// 01010111010
// 0101011

#include<iostream>
#include<string>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
		ll n, cnt0, cnt1;
		string s;
		cin >> n >> s;
		cnt0 = 0;
		cnt1 = 0;

		for(int i = 0; i < n; i++){
				if(i == 0){
						if(s[i] == '0') cnt0++;
						else cnt1++;
				}
				else{
						if(s[i] == '0' && s[i - 1] != '0') cnt0++;
						else if(s[i] == '1') cnt1++;
				}
		}

		if(cnt1 > cnt0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
}	

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}

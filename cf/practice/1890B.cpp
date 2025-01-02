#include<iostream>
#include<string>
#define ll long long
using namespace std;

void solve(){
		string s, t;
		ll n, m;
		char l, r;
		bool tg;

		cin >> n >> m >> s >> t;
		l = t[0];
		r = t[m - 1];
		tg = true;
		for(int i = 0; i < m - 1; i++){
				if(t[i] == t[i + 1]){
						tg = false;
				}
		}




		for(int i = 0; i < n - 1; i++){
				if(s[i] == s[i + 1]){
						if(!tg || !(s[i] != l && s[i] != r)){
								cout << "NO" << '\n';
								return;
						}
				}
		}

		cout << "YES" << '\n';
}

int main(){
		ll t;
		cin >> t;
		for(int i = 0; i < t; i++) solve();
}

#include<iostream>
#include<string>
#define ll long long
using namespace std;

void solve(){
		ll n, m;
		string s;
		cin >> n >> m;
		ll a[n][m], b[n][m];

		for(int i = 0; i < n; i++){
				cin >> s;
				for(int j = 0; j < m; j++) a[i][j] = s[j];
		}

		for(int i = 0; i < n; i++){
				cin >> s;
				for(int j = 0; j < m; j++) b[i][j] = s[j];
		}

		ll cnta, cntb;

		for(int i = 0; i < n; i++){
				cnta = 0;
				cntb = 0;
				for(int j = 0; j < m; j++){
						cnta += a[i][j];
						cntb += b[i][j];
				}
				if(cnta % 3 != cntb % 3){
						cout << "NO" << '\n';
						return;
				}
		}


		for(int i = 0; i < m; i++){
				cnta = 0;
				cntb = 0;
				for(int j = 0; j < n; j++){
						cnta += a[j][i];
						cntb += b[j][i];
				}
				if(cnta % 3 != cntb % 3){
						cout << "NO" << '\n';
						return;
				}
		}

		cout << "YES" << '\n';
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}

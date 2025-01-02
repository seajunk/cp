#include<iostream>
#include<string>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
		string a, b;
		ll n, cnt;
		cin >> n;
		cin >> a;
		cin >> b;
		cnt = 0;

		for(int i = 0; i < n - 2; i++){
				if(a[i] == 'x' && a[i + 1] == '.' && a[i + 2] == 'x' && b[i] == '.' && b[i + 1] == '.' && b[i + 2] == '.' ) cnt++;
				else if(b[i] == 'x' && b[i + 1] == '.' && b[i + 2] == 'x' && a[i] == '.' && a[i + 1] == '.' && a[i + 2] == '.' ) cnt++;
		}

		cout << cnt << '\n';
}

int main(){
		ll t;
		cin >> t;
		while(t--) solve();
}

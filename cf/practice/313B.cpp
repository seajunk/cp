#include<iostream>
#include<string>
#define ll long long
const ll N = 2e5 + 5;

using namespace std;



int main(){
		string s;
		ll m, l, r, a[N], b[N];
		cin >> s >> m;
		
		for(int i = 0; i < s.size() - 1; i++){
				if(s[i] == s[i + 1]){
						a[i] = 1;
				}
				else a[i] = 0;
		}
		a[s.size() - 1] = 0;
		
		b[0] = 0;
		for(int i = 1; i <= s.size(); i++){
				b[i] = b[i - 1] + a[i - 1];
		}

		
		for(int i = 0; i < m; i++){
				cin >> l >> r;
				l--;
				r--;

				cout << b[r] - b[l] << '\n';
		}
		






}

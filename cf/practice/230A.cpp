#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;


int main(){
		ll s, n;
		cin >> s >> n;
		vector<vector<ll>> a(n, vector<ll>(2));	
		for(int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
		sort(a.begin(), a.end(), [](auto l, auto r){return l[0] < r[0];});

		for(int i = 0; i < n; i++){
				if(s <= a[i][0]){cout << "NO" << '\n'; return 0;};
				s += a[i][1];
		}

		cout << "YES" << '\n';




			
		
}


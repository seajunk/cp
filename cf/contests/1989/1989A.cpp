#include<iostream>
#define ll long long
using namespace std;

int main(){
		ll n, x, y;
		cin >> n;

		for(int i = 0; i < n; i++){
				cin >> x >> y;
				if(y < -1) cout << "NO" << '\n';
				else cout << "YES" << '\n';

		}
}



#include<iostream>
#define ll long long
using namespace std;

int main(){
		ll n, X, Y, Z;
		cin >> n;
		X = 0;
		Y = 0;
		Z = 0;
		for(int i = 0; i < n; i++){
				ll x, y, z;
				cin >> x >> y >> z;
				X += x;
				Y += y;
				Z += z;
		}
		if(X == 0 && Y == 0 && Z == 0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
}

#include<iostream>
#define ll long long
using namespace std;

int main(){
		ll m, n;
		cin >> m >> n;
		if(m % 2 == 1) cout << (m / 2) * n + (n / 2) << '\n';
		else cout << m / 2 * n << '\n';

}

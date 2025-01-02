#include<iostream>
#include<unordered_set>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

int main(){
		ll a, b, c, n, in;
		a = 0;
		b = 0;
		c = 0;
		cin >> n;
		for(int i = 0; i < n; i++){
				cin >> in;
				a += in;
		}
		for(int i = 0; i < n - 1; i++){
				cin >> in;
				b += in;
		}
		for(int i = 0; i < n - 2; i++){
				cin >> in;
				c += in;
		}

		cout << a - b << '\n';
		cout << b - c << '\n';
		








		



}


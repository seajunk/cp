#include<iostream>
#define ll long long
using namespace std;

int main(){
		ll a, b, c, ans;
		cin >> a >> b >> c;
		ans = 0;

		cout << max(a + b + c, max((a + b) * c, max(a * (b + c), a * b * c))) << '\n';
		







		


}

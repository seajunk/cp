#include<iostream>
#define ll long long
using namespace std;

int main(){
		ll k, n, w;
		cin >> k >> n >> w;
		cout << max((ll)0, k * (w * (w + 1) / 2) - n) << '\n';
}

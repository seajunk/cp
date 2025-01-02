#include<iostream>
#define ll long long
using namespace std;

int main(){
		ll x;
		cin >> x;
		cout << ((x/5) + (x%5 != 0)) << '\n';
}

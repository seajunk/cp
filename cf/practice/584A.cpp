#include<iostream>
#define ll long long
using namespace std;

int main(){
		ll n, t, v;
		cin >> n >> t;
		if(n == 1 && t == 10) cout << -1 << '\n';
		else if(t == 10){
				for(int i = 0; i < n - 1; i++){
						cout << 1;
				}
				cout << 0 << '\n';
		}
		else{
				for(int i = 0; i < n; i++) cout << t;
				cout << '\n';
		}










}

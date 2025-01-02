#include<iostream>
#include<utility>
#include<algorithm>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;


int main(){
		ll n, a, b;
		pair<ll, ll> arr[N];

		cin >> n;
		for(int i = 0; i < n; i++){
				cin >> a >> b;
				arr[i] = make_pair(a, b);
		}
		
		sort(arr, arr+n, [](auto l, auto r){return l.first < r.first;});

		for(int i = 1; i < n; i++){
				if(arr[i - 1].second > arr[i].second){
						cout << "Happy Alex" << '\n';
						return 0;
				}
		}

		cout << "Poor Alex" << '\n';





}

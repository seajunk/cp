#include<iostream>
#include<queue>
#define ll long long
const ll N = 2e5;
using namespace std;

int main(){
		queue<ll> q;
		ll n, k, h[N], curr, mn, ans;
		curr = 0;
		mn = 10e9;
		ans = 1;
		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> h[i];

		for(int i = 0; q.size() < k; i++){
				q.push(h[i]);
				curr += h[i];
		}
		mn = min(mn, curr);

		for(int i = k; i < n; i++){
				curr -= q.front();
				q.pop();
				q.push(h[i]);
				curr += h[i];
				if(curr <= mn) ans = i - k + 2;
				mn = min(mn, curr);
		}

		cout << ans << '\n';



}


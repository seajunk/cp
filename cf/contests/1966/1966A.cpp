#include<iostream>
#include<algorithm>
#include<unordered_map>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
  unordered_map<ll, ll> h;
  ll n, k, in, ans, carry;
  carry = 0;
  ans = 0;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> in;
    if(h.find(in) == h.end()) h[in] = 1;
    else h[in] += 1;
  }

  for(unordered_map<ll, ll>::iterator it = h.begin(); it != h.end(); it++){
    if((*it).second >= k){
      cout << k - 1 << '\n';
      return;
    }
  }

  cout << n << '\n';

 }

int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}



#include<iostream>
#include<unordered_map>
#define ll long long
using namespace std;

void solve(){
  ll n, in, ans;
  ans = 0;
  unordered_map<ll, ll> h;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> in;
    if(h.find(in) == h.end()) h[in] = 1;
    else h[in] += 1;
  }

  for(auto it = h.begin(); it != h.end(); it++) if((*it).second == 2) ans++;
  
  cout << ans << '\n';
}

int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}

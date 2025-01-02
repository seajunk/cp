#include <iostream>
#include <unordered_map>
typedef long long ll;
const ll N = 2e5 + 5;
using namespace std;

void solve(){
  ll n, in, mx;
  cin >> n;
  mx = 0;
  unordered_map<ll, ll> h;
  for(int i = 0; i < n; i++){
    cin >> in;
    if(h.find(in) == h.end()) h[in] = 1;
    else h[in] += 1;
    mx = max(mx, h[in]);
  }

  cout << n - mx << '\n';
}

int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}


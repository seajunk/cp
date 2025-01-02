#include<iostream>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
  ll k, q, a[N], n[N];
  cin >> k >> q;

  for(int i = 0; i < k; i++) cin >> a[i];
  for(int i = 0; i < q; i++) cin >> n[i];

  for(int i = 0; i < q; i++){
    cout << min(a[0] - 1, n[i]) << ' ';
  }
  cout << '\n';
}

int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}

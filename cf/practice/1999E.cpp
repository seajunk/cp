#include <iostream>
#define ll long long
using namespace std;
const ll N = 2e5 + 5;

ll ps[N];
ll a[N];

ll base3(ll x){
  if(x == 0) return 1;
  ll count = 0;
  while(x > 0){
    count += 1;
    x /= 3;
  }
  return count;
}

void precomp(){
  for(int i = 0; i < 2e5 + 5; i++){
    a[i] = base3(i);
  }
  ps[0] = a[0];
  for(int i = 1; i < 2e5 + 5; i++){
    ps[i] = ps[i - 1] + a[i];
  }
}

void solve(){
  ll l, r, ans;
  cin >> l >> r;

  ans = base3(l);

  ans += ps[r] - ps[l - 1];

  cout << ans << '\n';

}

int main(){
  precomp();
  ll t;
  cin >> t;
  while(t--) solve();
}

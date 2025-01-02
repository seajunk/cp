#include<iostream>
#include<algorithm>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
  ll n, a[N], m, ans;
  ans = 0;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  m = (n + 2 - 1) / 2 - 1;
  ll *it = upper_bound(a, a + n, a[m]);
  ll *i = a + m;
  while(i != it){
    ans++;
    i++;
  }
  cout << ans << '\n';
}



int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}

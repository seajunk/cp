#include <iostream>
#include <string>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
  ll n, a[N], ps[N], ans;
  ans = 0;
  string s;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  ps[0] = 0;
  for(int i = 1; i <= n; i++){
    ps[i] = ps[i - 1] + a[i - 1];
  }
  cin >> s;

  for(ll l = 0, r = n - 1; l < r;){
    if(s[l] == 'L' && s[r] == 'R'){
      ans += ps[r + 1] - ps[l];
      l++;
      r--;
    }
    else{
      if(s[l] != 'L') l++;
      if(s[r] != 'R') r--;
    }
  }

  cout << ans << '\n';

}

int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}

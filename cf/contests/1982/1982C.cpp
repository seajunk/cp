#include<iostream>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

// USE HALF OPEN INTERVALS ALWAYS ALWAYS ALWAYS

void solve(){
  ll n, l, r, a[N], ans;
  cin >> n >> l >> r;
  for(int i = 0; i < n; i++) cin >> a[i];
  ans = 0;
  
  ll R = 0;
  ll L = 0;
  ll sum = 0;
  while(R < n){
    sum += a[R];
    R++;

    if(l <= sum && sum <= r){
      L = R;
      ans++;
      sum = 0;
    }

    while(sum > r){
      sum -= a[L];
      L++;
      if(l <= sum && sum <= r){
        sum = 0;
        ans++;
        L = R;
      }
    }
  }

  cout << ans << '\n';

}

int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}

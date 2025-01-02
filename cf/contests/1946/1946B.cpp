#include<iostream>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
  ll n, k, a[N], mx, curr, sum, ans;
  sum = 0;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  mx = 0;
  curr = -1 * 1e10;// this one acc doesnt matter

  for(int i = 0; i < n; i++){
    if(i == 0){
      curr = a[i];
    }
    else{
      curr = max(a[i], curr + a[i]);
    }
    mx = max(mx, curr);
  }

  ans = sum;
  while(k--){
    ans += mx;
    mx += mx;
  }

  cout << ans << '\n';

}


int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}

#include<iostream>
#include<algorithm>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;


void solve(){
  ll n, k, a[N];
  cin >> n >> k;

  if(k % 2 == 1){
    cout << "NO" << '\n';
    return;
  }

  for(int i = 0; i < n; i++){
    a[i] = i + 1;
  }
  // k = 10
  // 1 2 3 4 5 6 7 8
  // 1 2 3 4 5 6 7 8
  // 
  
  ll ans = 0;
  for(int l = 0, r = n - 1; l < r && ans < k;){
    if(k - ans >= 2 * abs(a[r] - a[l])){
      ans += 2 * abs(a[r] - a[l]);
      swap(a[r], a[l]);
      l++;
      r--;
    }   
    else{
      l++;
    }
  }

  if(ans == k){
    cout << "YES" << '\n';
    for(int i = 0; i < n; i++){
      cout << a[i] << ' ';
    }
    cout << '\n';

  }
  else cout << "NO" << '\n';
  


}


int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}

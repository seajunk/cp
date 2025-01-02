#include<iostream>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
  ll n, ans;
  cin >> n;
  ans = 0;
  // dont feel like calcualting O(1)
  // 1 2 3   n
  // 2 2 3   n
  // 3 3 3   n
  //         n
  // n n n n n 
  for(int i = 1; i <= n; i++){
    ans += i * (2 * (i - 1) + 1);
  }

  cout << ans << ' ' << 2 * n << '\n';


  for(int i = n; i >= 1; i--){
    for(int j = 1; j <= 2; j++){
      cout << j << ' ';
      cout << i << ' ';
      
      for(int k = 1; k <= n; k++) cout << k << ' ';
      cout << '\n';
    }
  }

  // no lie, why does this even work lol






}

int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}

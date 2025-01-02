#include<iostream>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;


void solve(){
  ll x, y, n;
  cin >> x >> y >> n;
  for(int i = 1; i <= n; i++){
    cout << i << ' ' << (x^i) << ' ' <<(y^i) << '\n';
  }

}




int main(){
  //ll t;
  //cin >> t;
  //while(t--) solve();
  solve();
  
  
}

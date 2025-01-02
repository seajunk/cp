#include<iostream>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;


void solve(){
  ll p1, p2, p3, mx;
  mx = 0;
  cin >> p1 >> p2 >> p3;

  if((p1 + p2 + p3) % 2 != 0){
    cout << -1 << '\n';
  }
  else{
    for(ll d12 = 0; d12 <= 30; d12++){
      for(ll d13 = 0; d13 <= 30; d13++){
        for(ll d23 = 0; d23 <= 30; d23++){
          if(d13 <= min(p1, p3) && d12 <= min(p1, p2) && d23 <= min(p2, p3)){
            if((p1 % 2 == 0 || (d12 > 0 || d13 > 0)) && (p2 % 2 == 0 || (d12 > 0 || d23 > 0)) && (p3 % 2 == 0 || (d13 > 0 || d23 > 0))){
           if((p1 >= d12 + d13) && (p2 >= d12 + d23) && (p3 >= d13 + d23))mx = max(mx, d12 + d13 + d23);
 
            }          }
        }
      }
    }
    cout << mx << '\n';
  }
}

// p1 >= d12 + d13


int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}

#include <iostream>
typedef long long ll;
const ll N = 2e5 + 5;
using namespace std;


void solve(){
  /*
     1 2 3 -> 3 1 2 -> (1, 2), (3) | (1), (2, 3)
     1 2 3 4 -> 
     1 2 3 4 5 -> 5 3 1 2 4 -> (1, 2) (3, 4) (5) | (1) (2, 3) (4, 5)
  */
  ll n;
  cin >> n;
  if(n % 2 == 0) cout << - 1 << '\n';
  else{
    ll m = n;
    for(int i = 0; i < n; i++){
      cout << m << ' ';
      if(i < n / 2){
        m -= 2;
      }
      else{
        if(i == n / 2) m += 1;
        else m += 2;
      }
    }
    cout << '\n';
  }

}

int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}

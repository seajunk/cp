#include<iostream>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
  ll n, a[N], mex, mx;
  mex = 1;
  mx = -1;
  cin >> n;
  bool b[N];
  fill(b, b + n + 2, false);

  for(int i = 0; i < n; i++){
    cin >> a[i];
    mx = max(mx, a[i]);
    if(a[i] <= n + 1) b[a[i]] = true;
  }
  while(b[mex]) mex++;

  if(mex > mx){
    if(mx % 2 == 1) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
  }
  else{
    if(mex % 2 == 1) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
  }
  
}

int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}

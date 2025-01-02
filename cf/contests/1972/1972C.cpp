#include<iostream>
#include<algorithm>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
  ll n, k, a[N], rs[N], h, used, mx, j;
  j = 0;
  mx = 0;
  used = 0;
  h = 0;
  cin >> n >> k;
  for(int i = 0; i < n; i++){ 
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  sort(a, a + n);

  for(int i = 0; i < n; i++){
    if(i == 0) rs[i] = a[i];
    else rs[i] = a[i] + rs[i - 1];
  }

  for(int i = 0; k >= a[i] * (i + 1) - rs[i] && i < n; i++){ 
    j = i;
    used = a[i] * (i + 1) - rs[i];
    h = a[i];
  }
  k -= used;
  if(h == 0){
    cout << 0 << '\n';
  } 
  else if(h == mx){
    h += k / n;
    cout << (h * n) - (n - 1) + (k % n) << '\n';
  }
  else{
    h += k / (j + 1);
    cout << (h * n) - (n - 1) + (k % (j + 1)) + (n - 1 - j) << '\n'; 
  }
  






  
   






}

int main(){

  ll t;
  cin >> t;   
  while(t--) solve();
}


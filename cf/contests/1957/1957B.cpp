#include<iostream>
#include<cmath>
#include<string>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

ll pow2(ll x){
  ll r = 1;
  for(int i = 0; i < x; i++){
    r *= 2;
  }
  return r;
}

ll getbin(ll n, string &s){
  ll cnt1 = 0;
  if(n == 0){
    s += "0";
    return cnt1; 
  }

  while(n != 0){
    if(n % 2 == 0){ s = "0" + s;}
    else{s = "1" + s; cnt1++;}
    n /= 2;
  }
  return cnt1;
}


void solve(){
  ll n, k, cnt1;
  string s;
  cin >> n >> k;
  cnt1 = getbin(k, s);
  if(n == 1) cout << k << '\n';
  else{
    if(cnt1 == s.size()){
      cout << k << ' ';
      for(int i = 1; i < n; i++) cout << 0 << ' ';
      cout << '\n';
    }
    else{
      cout << pow2(s.size() - 1) - 1 << ' ' << k - (pow2(s.size() - 1) - 1) << ' ';
      for(int i = 2; i < n; i++) cout << 0 << ' ';
      cout << '\n';
    }
  }
}







int main(){
  ll t;
  cin  >> t;
  while(t--) solve();
}

#include<iostream>
#include<unordered_set>
#define ll long long
using namespace std;



void solve(){
  unordered_multiset<ll> S;
  ll n, in, ans;
  cin >> n;
  ans = 0;
  for(int i = 0; i < n; i++){
    cin >> in;
    S.insert(in);
    if(S.count(in) == 3){
      S.erase(in);
      ans++;
    }
  }
  cout << ans << '\n';
}

int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}

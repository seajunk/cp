#include <iostream>
#include <cmath>
#include <utility>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

double distance(pair<ll, ll> a, pair<ll, ll> b){
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

void solve(){
  ll n;
  pair<ll, ll> a[N], s, t;
  double d;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i].first; // x
    cin >> a[i].second; // y
  }

  cin >> s.first >> s.second;
  cin >> t.first >> t.second;

  d = distance(s, t);

  for(int i = 0; i < n; i++){
    if(distance(a[i], t) <= d){
      cout << "NO" << '\n';
      return;
    }
  }

  cout << "YES" << '\n';
  
}

int main(){
  ll t;
  cin >> t;
  while(t--) solve();
}

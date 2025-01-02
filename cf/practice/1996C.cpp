#include <iostream>
#include <vector>
#include <string>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
  string a, b;
  ll n, q, l, r;
  cin >> n >> q;
  cin >> a >> b;
  n = a.size();
  vector<vector<ll>> psa(26, vector<ll>(n + 1, 0)), psb(26, vector<ll>(n + 1, 0));

  for(int i = 0; i < 26; i++){
    for(int j = 1; j <= n; j++){
      psa[i][j] = psa[i][j - 1] + (a[j - 1] == 97 + i);
      psb[i][j] = psb[i][j - 1] + (b[j - 1] == 97 + i);
    }
  }

  while(q--){
    cin >> l >> r;
    l--;
    ll ans = 0;
    for(int i = 0; i < 26; i++){
      if(psa[i][r] - psa[i][l] < psb[i][r] - psb[i][l]){
        ans += (psb[i][r] - psb[i][l]) - (psa[i][r] - psa[i][l]);
      }
    }
    cout << ans << '\n';
  }

}

void test(){
  string a;
  ll n;
  cin >> a;
  n = a.size();
  vector<vector<ll>> psa(26, vector<ll>(n + 1, 0));

  for(int i = 0; i < 26; i++){
    for(int j = 1; j <= n; j++){
      psa[i][j] = psa[i][j - 1] + (a[j - 1] == 97 + i);
    }
  }

  cout << '\n';
  cout << "    ";
  for(int i = 0; i < n; i++){
    cout << ' ' << a[i];
  }
  cout << '\n';
  for(int j = 0; j < 26; j++){
    cout << (char)(j + 97) << " = ";
    for(int i = 0; i <= n; i++){
      cout << psa[j][i] << ' ';
    }
    cout << '\n';
  }

  while(1){
    ll l, r;
    char c;
    cin >> l >> r >> c;
    cout << psa[c - 97][r] - psa[c - 97][l] << '\n'; 
  }

}

int main(){
  ll t;
  cin >> t;
  while(t--) solve();

  //test();
}

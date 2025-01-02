#include<iostream>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;



// 4, 3
// a = 1 2 5 6
// a%2k = 1 2 5 0
// c = 1 1 0 -1 -1 0

void solve(){
  ll n, k, a[N], ps[N], d[N], mx;
  cin >> n >> k;
  mx = -1;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    mx = max(a[i], mx);
    a[i] = a[i] % (2*k);
  }

  for(int i = 0; i < n; i++){
    d[a[i]]++;
    d[(a[i] + k) % (2*k)]--;
  }

  for(int i = 0; i < 2*k; i++){
    cout << d[i] << '\n';
  }


}

int main(){
  solve();
}

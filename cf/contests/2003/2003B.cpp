#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

void solve(){
    ll n, a[N];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    cout << a[n / 2] << '\n';
}

int main(){
    ll t;
    cin >> t;
    while(t--) solve();
}


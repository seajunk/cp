#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    // conj: we currently have curr tickets, then we need k - curr tickets. If were on the ith day we buy m tickets, the ticket price is essentially <a[i]*m + (k-curr-m) * m> where <a[i]*m> is the actual price of the m tickets and <(k-curr-m)*m> is the added price for the remaining (k-curr-m) tickets we still need to buy, each of which became m units more expensive 

    // conj: day i penalty = sum[0, i) of buy array where b[i] = # of tickets bought on day i 
    // heur: we generally want to minimize the number of days we buy tickets on

    // greedily buy all tickets on days sorted increasing?


    ll n, m, k; cin >> n >> m >> k;
    vector<vector<ll>> a(n, vector<ll>(2)); // index, value
    vector<ll> value(n);
    for(int i = 0; i < n; i++){
        a[i][0] = i;
        cin >> a[i][1];
        value[i] = a[i][1];
    }

    sort(a.begin(), a.end(), [](auto l, auto r){
            return l[1] < r[1];
            });

    vector<ll> buy(n, 0);


    ll curr = 0;
    for(int i = 0; i < n; i++){
        ll bought = min(m, k - curr);
        curr += bought;
        buy[a[i][0]] = bought;
        if(curr == k) break;
    }

    ll ps[n + 1];
    ps[0] = 0;
    for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] + buy[i - 1];

    ll ans = 0;

    for(int i = 0; i < n; i++){
        ans += (ps[i] + value[i]) * buy[i];
    }

    cout << ans << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

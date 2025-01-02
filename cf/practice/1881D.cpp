#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // 100 2 50 10 1

    // 1 * 2 * 2 * 5 * 5
    // 1 * 2
    // 1 * 5 * 5 * 2
    // 1 * 2 * 5
    // 1 

    // cnt[1] = 5
    // cnt[2] = 5
    // cnt[5] = 5

    // conj: works if each prime factor count is divisible by n

    // shitty prime factorization

    unordered_map<ll, ll> cnt;

    for(int i = 0; i < n; i++){
        for(int j = 2; j <= (int)sqrt(a[i]); j++){
            while(a[i] % j == 0){
                if(cnt.find(j) == cnt.end()) cnt[j] = 1;
                else cnt[j]++;
                a[i] /= j;
            }
        }
        if(a[i] > 1){
            if(cnt.find(a[i]) == cnt.end()) cnt[a[i]] = 1;
            else cnt[a[i]]++;
        }
    }

    for(auto [k, v] : cnt){
        if((v % n) != 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    ll count[5] = {0};
    for(int i = 0; i < n; i++){
        count[i%5]++;
    }
    
    for(int v = 0; v < 5; v++){
        for(int i = 0; i < count[v]; i++){
            cout << vowels[v];
        }
    }
    cout << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


// aeiouuuu
// aaeeiioo

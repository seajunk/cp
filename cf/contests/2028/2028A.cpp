#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, a, b; cin >> n >> a >> b;

    string s; cin >> s;

    ll dx = 0;
    ll dy = 0;


    if(dx == a && dy == b){
        cout << "YES\n";
        return;
    }

    for(int i = 0; i < 100; i++){
        for(char c : s){
            if(c == 'N') dy++;
            if(c == 'W') dx--;
            if(c == 'S') dy--;
            if(c == 'E') dx++;

            if(dx == a && dy == b){
                cout << "yes\n";
                return;
            }
        }
    }

    cout << "NO\n";








}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

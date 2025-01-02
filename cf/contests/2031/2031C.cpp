#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve(){
    ll n; cin >> n;

    if(n % 2 == 0){
        for(int i = 1; i <= n/2; i++){
            cout << i << ' ' << i << ' ';
        }
        cout << '\n';
        return;
    }
    if(n < 27){
        cout << -1 << '\n';
        return;
    }

    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
    // 1, 10, 26

    ll curr = 3;
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        if(i == 1 || i == 10 || i == 26){
            cout << 1 << ' ';
        }
        else if(i == 27 || i == 23){
            cout << 2 << ' ';
        }
        else if(cnt < 2){
            cout << curr << ' ';
            cnt++;
        }

        if(cnt == 2){
            cnt = 0;
            curr++;
        }
    }
    cout << '\n';


}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

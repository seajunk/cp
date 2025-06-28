#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    if(a[n - 1] != 0){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    // can create any binary string which ends with 0

    // seperate string into blocks eg
    // 0011010110110
    // 00 110 10 110 110

    // (# of 1s, # of 0s) -> 
    // (0, 0) (2, 1) (1, 1) (2, 1) (2, 1)
    // note only first block can have 0 ones

    vector<vector<ll>> blocks;


    ll onecnt = 0, zerocnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) zerocnt++;
        else onecnt++;

        if(i == n - 1){
            blocks.push_back({onecnt, zerocnt});
        }
        else if(a[i] == 0 && a[i + 1] == 1){
            blocks.push_back({onecnt, zerocnt});
            onecnt = 0;
            zerocnt = 0;
        }
    }

    for(auto it = blocks.rbegin(); it != blocks.rend(); it++){
        auto block = *it;
        for(int i = 1; i < block[1]; i++){
            cout << 0 << ' ';
        }
        for(int i = 0; i < block[0]; i++){
            cout << 0 << ' ';
        }
        cout << block[0] << ' ';
    }
    cout << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

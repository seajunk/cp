#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    char instruction[n];
    vector<ll> cnt(4, 0);
    for(int i = 0; i < n; i++){
        char in; cin >> in;
        instruction[i] = in;
        if(in == 'N') cnt[0]++;
        if(in == 'S') cnt[1]++;
        if(in == 'E') cnt[2]++;
        if(in == 'W') cnt[3]++;
    }

    ll mny = min(cnt[0], cnt[1]);
    ll mnx = min(cnt[2], cnt[3]);


    ll remainderx = cnt[0] - mnx + cnt[1] - mnx;
    ll remaindery = cnt[2] - mny + cnt[3] - mny;

    if((remainderx) % 2 != 0){
        cout << "NO" << '\n';
        return;
    }
    if((remaindery) % 2 != 0){
        cout << "NO" << '\n';
        return;
    }


    char ans[n]; fill(ans, ans + n, 'H');
    ll rn = (cnt[0] - mny) / 2;
    ll rs = (cnt[1] - mny) / 2;
    ll re = (cnt[2] - mnx) / 2;
    ll rw = (cnt[3] - mnx) / 2;



    if((mnx + mny < 2) && (remainderx + remaindery == 0)){
        cout << "NO" << '\n';
        return;
    }

    if(mnx + mny >= 2){
        if(mnx == 1 && mny == 1){
            rn++;
            rs++;
        }
        else if(mnx >= 2){
            re++;
            rw++;
        }
        else if(mny >= 2){
            rn++;
            rs++;
        }
    }


    ll currn = 0;
    ll currs = 0;
    ll curre = 0;
    ll currw = 0;

    for(int i = 0; i < n; i++){
        if(instruction[i] == 'N'){
            if(currn < rn){
                ans[i] = 'R';
                currn++;
            }
        }
        if(instruction[i] == 'S'){
            if(currs < rs){
                ans[i] = 'R';
                currs++;
            }
        }
        if(instruction[i] == 'E'){
            if(curre < re){
                ans[i] = 'R';
                curre++;
            }
        }
        if(instruction[i] == 'W'){
            if(currw < rw){
                ans[i] = 'R';
                currw++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << ans[i];
    }
    cout << '\n';








}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

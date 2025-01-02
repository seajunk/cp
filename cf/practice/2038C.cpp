#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;

    map<ll, ll> cnt;
    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        if(cnt.find(in) == cnt.end()) cnt[in] = 1;
        else cnt[in]++;
    }


    ll x1 = LLONG_MIN;
    ll x2 = LLONG_MIN;
    ll y1 = LLONG_MIN;
    ll y2 = LLONG_MIN;

    for(auto it = cnt.begin(); it != cnt.end(); it++){
        if(it->second >= 2){
            x1 = it->first;
            cnt[x1] -= 2;
            break;
        }
    }

    for(auto it = cnt.rbegin(); it != cnt.rend(); it++){
        if(it->second >= 2){
            x2 = it->first;
            cnt[x2] -= 2;
            break;
        }
    }


    for(auto it = cnt.begin(); it != cnt.end(); it++){
        if(it->second >= 2){
            y1 = it->first;
            cnt[y1] -= 2;
            break;
        }
    }

    for(auto it = cnt.rbegin(); it != cnt.rend(); it++){
        if(it->second >= 2){
            y2 = it->first;
            cnt[y2] -= 2;
            break;
        }
    }


    if(x1 == LLONG_MIN || x2 == LLONG_MIN || y1 == LLONG_MIN || y2 == LLONG_MIN){
        cout << "NO\n";
        return;
    }

    ll points[4] = {x1, x2, y1, y2};


    cout << "YES\n";
    ll mx = LLONG_MIN;

    for(int a = 0; a < 4; a++){
        for(int b = 0; b < 4; b++){
            if(b == a) continue;
            for(int c = 0; c < 4; c++){
                if(c == a || c == b) continue;
                for(int d = 0; d < 4; d++){
                    if(d == a || d == b || d == c) continue;

                    // (a, b, c, d) 
                    mx = max(mx, abs(points[a] - points[b]) * abs(points[c] - points[d]));

                }
            }
        }
    }


    // pretty scuffed
    for(int a = 0; a < 4; a++){
        for(int b = 0; b < 4; b++){
            if(b == a) continue;
            for(int c = 0; c < 4; c++){
                if(c == a || c == b) continue;
                for(int d = 0; d < 4; d++){
                    if(d == a || d == b || d == c) continue;

                    // (a, b, c, d) 
                    ll curr = abs(points[a] - points[b]) * abs(points[c] - points[d]);

                    if(curr == mx){
                        cout << points[a] << ' ' << points[c] << ' ' << points[a] << ' ' << points[d] << ' ';
                        cout << points[b] << ' ' << points[c] << ' ' << points[b] << ' ' << points[d] << '\n';
                        return;
                    }

                }
            }
        }
    }






}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

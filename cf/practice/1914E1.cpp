#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    ll a[n], b[n];

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    // conj: the value for a colour i for alice is a[i] - 1 + b[i] 
    // the value for a colour i for bob is b[i] - 1 + a[i] 
    // choose max value at each step?

    // a[i] + b[i] - 1

    map<ll, stack<ll>> score;

    for(int i = 0; i < n; i++){
        if(a[i] > 0 && b[i] > 0){
            score[a[i] + b[i] - 1].push(i);
        }
    }

    bool turn = true;

    for(auto it = score.rbegin(); it != score.rend();){
        if(turn){
            a[it->second.top()]--;
            b[it->second.top()] = 0;
        }
        else{
            b[it->second.top()]--;
            a[it->second.top()] = 0;
        }
        turn = !turn;
        it->second.pop();
        if(it->second.size() == 0) it++;
    }

    ll A = 0;
    ll B = 0;

    for(int i = 0; i < n; i++){
        A += a[i];
        B += b[i];
    }

    cout << A - B << '\n';

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}


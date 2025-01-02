#include <iostream>
#include <unordered_set>
#define ll long long 
using namespace std;

// simulate jumping k times for each player and keep track of where they are at each jump
// then calculate the values that the players would end up with if they stay at the ith jump and stay there for the reminaing turns.
// get the max of these values and compare between players.
void solve(){
    ll n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    pb--; ps--;
    ll a[n], p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    ll mxb = -1, mxs = -1, currb = 0, currs = 0;
    unordered_set<ll> visitedb, visiteds;
    for(int i = 0; i < k; i++){
        mxb = max(mxb, currb + a[pb] * (k - i));
        mxs = max(mxs, currs + a[ps] * (k - i));
        currb += a[pb];
        currs += a[ps];
        pb = p[pb];
        ps = p[ps];

        if(visitedb.find(pb) == visitedb.end() || visiteds.find(ps) == visiteds.end()){
            visitedb.insert(pb);
            visiteds.insert(ps);
        }
        else{
            break;
        }
    }
    if(mxb > mxs) cout << "Bodya" << '\n';
    else if(mxb < mxs) cout << "Sasha" << '\n';
    else cout << "Draw" << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

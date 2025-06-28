#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k; cin >> n >> k;
    ll c[n];
    for(int i = 0; i < n; i++) cin >> c[i];


    /*
       have array, want to find start at left of index 0, can choose some colour and jump only on that colour. can colour any index the chosen colour. what is minimum max jump length needed to get to end of array.

       iterate over array and keep track of last seen position of colour i. then we have max min jump length needed before the one paint we get.

       need the count of lengths per colour too. then update values so that any colour whose max jump length appears once, we half(?) it and check for new min in the colour. then answer is the min of these values. 
    */

    map<ll, map<ll, ll>> s; // s[colour][length] = count of length 
    map<ll, ll> lastSeen; // lastSeen[colour] index of last seen plank of colour


    for(int i = 0; i < n; i++){
        ll dist;
        if(lastSeen.find(c[i]) == lastSeen.end()){
            dist = i; // jumping from index -1 to i
            lastSeen[c[i]] = i;
        }
        else{
            dist = i - (lastSeen[c[i]] + 1);
            lastSeen[c[i]] = i;
        }

        if(s[c[i]].find(dist) == s[c[i]].end()) s[c[i]][dist] = 1; 
        else s[c[i]][dist]++;
    }
    for(auto p : lastSeen){
        ll colour = p.first;
        ll idx = p.second;

        ll dist = n - (idx + 1);
        if(s[colour].find(dist) == s[colour].end()) s[colour][dist] = 1; 
        else s[colour][dist]++;
    }

    for(auto &p : s){
        ll colour = p.first;
        ll mxDist = prev(p.second.end())->first;
        ll cnt = prev(p.second.end())->second;
        if(cnt == 1){
            p.second.erase(mxDist);
            ll newDist = mxDist / 2; 
            if(p.second.find(newDist) == p.second.end()) p.second[newDist] = 1;
            else p.second[newDist]++;
        }
    }

    ll ans = LLONG_MAX;
    for(auto p : s){
        ans = min(ans, prev(p.second.end())->first);
    }
    cout << ans << '\n';
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

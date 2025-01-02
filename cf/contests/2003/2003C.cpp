#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#define ll long long
const ll N = 2e5 + 5;
using namespace std;

// turtle -> turlet
// edddf -> ddefd
// aabb -> abab
// aabb -> aabb
// aaabbb -> ababab
// edddf -> defdd
// turtle -> turlet
void solve(){
    ll n;
    string s;
    cin >> n >> s;

    vector<pair<ll, ll>> c(26, {0, 0});

    for(int i = 0; i < 26; i++){
        c[i].first = i;
        c[i].second = 0;
    }

    for(int i = 0; i < n; i++){
        c[s[i] - 'a'].second++;
    }
    
    sort(c.begin(), c.end(), [](auto l, auto r){
            return l.second < r.second;
            });
    

    string ans = "";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            if(c[j].second > 0){
                ans += 'a' + c[j].first;
                c[j].second--;
            }
        }
    }


    cout << ans << '\n';

}

int main(){
    ll t; 
    cin >> t;
    while(t--) solve();
}


#include <bits/stdc++.h>
#define ll long long
using namespace std;


vector<vector<ll>> p(ll n){
    vector<vector<ll>> ans;

    stack<pair<vector<ll>, set<ll>>> s;
    s.push({{}, {}});

    while(s.size()){
        pair<vector<ll>, set<ll>> top = s.top();
        s.pop();

        if(top.first.size() == n){
            ans.push_back(top.first);
            continue;
        }

        for(int i = 0; i < n; i++){
            if(top.second.find(i) == top.second.end()){
                pair<vector<ll>, set<ll>> child;
                child.first = top.first;
                child.second = top.second;
                child.first.push_back(i);
                child.second.insert(i);
                s.push(child);
            }
        }
    }

    return ans;
}

void solve(){
    ll n; cin >> n;
    ll arr[3][n];
    for(int i = 0; i < n; i++) cin >> arr[0][i];
    for(int i = 0; i < n; i++) cin >> arr[1][i];
    for(int i = 0; i < n; i++) cin >> arr[2][i];
    ll total = 0;
    for(int i = 0; i < n; i++) total += arr[0][i];


    vector<vector<ll>> permutations = p(3);

    for(vector<ll> permutation : permutations ){
        ll curr = 0;
        vector<pair<ll, ll>> ans;
        ll lo = 0; // [lo, hi)


        for(int i = 0; i < 3; i++){
            for(int hi = lo + 1; hi <= n; hi++){
                curr += arr[permutation[i]][hi - 1]; 
                if(curr >= (total + 2)/3){
                    ans.push_back({lo, permutation[i]});
                    ans.push_back({hi, permutation[i]});
                    lo = hi;
                    curr = 0;
                    break;
                }
            }
        }



        if(ans.size() == 6){

            sort(ans.begin(), ans.end(), [](pair<ll, ll> l, pair<ll, ll> r){
                    if(l.second != r.second) return l.second < r.second;
                    else return l.first < r.first;
                    });

            ans[0].first ++;
            ans[2].first ++;
            ans[4].first ++; 


            for(int i = 0; i < 6; i++){
                cout << ans[i].first << ' ';
            }
            cout << '\n';
            return;
        }
    }

    cout << -1 << '\n';






}

int main(){
    ll t; cin >> t;
    while(t--) solve();


}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m, h; cin >> n >> m >> h;
    vector<vector<ll>> t(n, vector<ll>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> t[i][j];
    }

    /*
       always optimal to take shorter questions first. Since if we supposed otherwise that optimal answer contains ... a b ... where a is longer than b then cost is a + a + b
       then we can swap a and b to get cost of b + b + a which is less. 
    */

    for(int i = 0; i < n ; i++){
        sort(t[i].begin(), t[i].end());
    }

    vector<vector<ll>> rank(n, vector<ll>(3)); // rank[i] = {index, score, penalty};
    for(int i = 0; i < n; i++){
        ll time = 0;
        ll penalty = 0;
        ll score = 0;
        for(int j = 0; j < m; j++){
            if(time + t[i][j] <= h){
                time += t[i][j];
                penalty += time;
                score += 1;
            }
            else break;
        }
        rank[i] = {i, score, penalty};
    }

    sort(rank.begin(), rank.end(), [](auto l, auto r){
            if(l[1] != r[1]) return l[1] > r[1];
            else return l[2] < r[2];
            });

    ll ourscore, ourpenalty;
    for(int i = 0; i < n; i++){
        if(rank[i][0] == 0){
            ourscore = rank[i][1]; 
            ourpenalty = rank[i][2]; 
        }
    }


    set<ll> temp;
    for(int i = 0; i < n; i++){
        if(rank[i][1] == ourscore && rank[i][2] == ourpenalty){
            temp.insert(i + 1);
        }
    }

    cout << *temp.begin() << '\n';



}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m; cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    deque<vector<ll>> trailing;
    vector<ll> len(n);


    for(int i = 0; i < n; i++){
        len[i] = a[i].size();


        ll cnt = 0;
        for(int j = len[i] - 1; j >= 0 && a[i][j] == '0'; j--) cnt++; 
        trailing.push_back({i, cnt}); // a[i] has cnt trailing zeros
    }

    sort(trailing.begin(), trailing.end(), [](auto l, auto r){
            return l[1] < r[1];
            });

    // on annas turn: flip number with most trailing zero
    // on sashas turn: combine max and min of trailing zeros 

    bool anna = true;

    while(trailing.size() > 1 || anna){
        if(anna){
            vector<ll> back = trailing.back();
            trailing.pop_back();
            len[back[0]] -= back[1];
            back[1] = 0;
            trailing.push_front(back);
        }
        else{
            vector<ll> front = trailing.front();
            vector<ll> back = trailing.back();
            trailing.pop_front();
            trailing.pop_back();

            len[front[0]] += len[back[0]];
            trailing.push_front(front);
        }
        anna = !anna;
    }


    if(len[trailing.front()[0]] - 1 >= m) cout << "Sasha\n";
    else cout << "Anna\n";









}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

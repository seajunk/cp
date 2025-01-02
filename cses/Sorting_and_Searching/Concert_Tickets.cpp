#include <bits/stdc++.h>
#define ll long long
using namespace std;




int main(){
    ll n, m, in; cin >> n >> m;
    ll t[m];
    map<ll, ll> h;
    for(int i = 0; i < n; i++){
        cin >> in;
        if(h.find(in) == h.end()) h[in] = 1;
        else h[in]++;
    }
    for(int i = 0; i < m; i++) cin >> t[i];

    for(int i = 0; i < m; i++){
        map<ll, ll>::iterator it = h.lower_bound(t[i]);
        if(it->first == t[i]){
            cout << it->first << '\n';
            h[it->first]--;
            if(h[it->first] == 0){
                h.erase(it);
            }
        }
        else if(it == h.begin()){
            cout << -1 << '\n';
        }
        else{
            it = prev(it);
            cout << it->first << '\n';
            h[it->first]--;
            if(h[it->first] == 0){
                h.erase(it);
            }
        }

    }




    return 0;
}

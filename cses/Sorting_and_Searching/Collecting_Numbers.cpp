#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n; cin >> n;
    unordered_map<ll, ll> m;
    for(int i = 0; i < n; i++){
        ll in; cin >> in;
        m[in] = i;
    }



    ll count = 1;

    for(int i = 2; i <= n; i++){
        if(m[i] < m[i - 1]) count++;
    }

    cout << count << '\n';

}


void sol1(){

    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    // 5 7 1 6 3 4 2 8
    // [5, 6] [7, 8] [1, 2] [3, 4]

    set<ll> s;

    
    for(int i = 0; i < n; i++){
        if(s.find(a[i] - 1) == s.end()){
            s.insert(a[i]);
        }
        else{
            s.erase(a[i] - 1);
            s.insert(a[i]);
        }
    }

    cout << s.size() << '\n';




}

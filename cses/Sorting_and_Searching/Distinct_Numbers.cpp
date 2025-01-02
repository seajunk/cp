#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, in; cin >> n;
    set<ll> S;
    for(int i = 0; i < n; i++){
        cin >> in;
        S.insert(in);
    }

    cout << S.size() << '\n';



    return 0;
}


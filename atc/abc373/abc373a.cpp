#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    vector<string> a(12);
    for(int i = 0 ; i < 12; i++) cin >> a[i];
    ll ans = 0;
    for(int i = 0; i < 12; i++){
        if(i + 1 == a[i].size()) ans++;
    }

    cout << ans << '\n';
}


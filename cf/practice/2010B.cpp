#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll ans = 0;
    ans ^= 1;
    ans ^= 2;
    ans ^= 3;
    ll first, second; cin >> first >> second;
    ans ^= first;
    ans ^= second;

    cout << ans << '\n';

}

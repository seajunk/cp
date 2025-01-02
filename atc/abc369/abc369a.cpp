#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a, b; cin >> a >> b;
    if(a == b) cout << 1 << '\n';
    else if(abs(a - b) % 2 == 0 && abs(a - b) > 0) cout << 3 << '\n';
    else cout << 2 << '\n';
    




}

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, m, k; cin >> n >> m >> k;
    ll a[n], b[m];
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    ll count = 0;
    for(ll aptr = 0, bptr = 0; aptr < n && bptr < m;){
        if(a[aptr] - k <= b[bptr] && b[bptr] <= a[aptr] + k){
            aptr++;
            bptr++;
            count++;
        }
        else if(b[bptr] < a[aptr] - k){
            bptr++;
        }
        else{
            aptr++;
        }
    }
    cout << count << '\n';
}


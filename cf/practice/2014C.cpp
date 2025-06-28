#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


void solve(){
    ll n; cin >> n;
    ll a[n];
    ll mx = LLONG_MIN;
    ll j = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(mx < a[i]){
            j = i;
            mx = a[i];
        }
    }


    ll lo = 0, hi = LLONG_MAX/2; // pretty sure something like hi = max(a) * n * 5 works but whatever
    while(lo < hi){
        ll mid = (hi - lo)/2 + lo;
        ll b[n];
        for(int i = 0; i < n; i++) b[i] = a[i];
        b[j] += mid;

        ld avg = 0;
        for(int i = 0; i < n; i++) avg += b[i];
        avg /= n;
        avg /= 2;

        ll unhappy = 0;
        for(int i = 0; i < n; i++){
            if(b[i] < avg) unhappy += 1;
        }
        //printf("unhappy = %lld, x = %lld, avg = %LF\n", unhappy, mid, avg);
        ld half = n;
        half /= 2;

        if(unhappy > half) hi = mid;
        else lo = mid + 1;
    }
    if(lo == LLONG_MAX/2){
        cout << -1 << '\n'; 
    }
    else{
        cout << lo << '\n';
    }

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

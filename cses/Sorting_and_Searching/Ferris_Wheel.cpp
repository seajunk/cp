#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, x; cin >> n >> x;
    ll p[n];
    for(int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);
    ll l = 0, r = n - 1;
    ll count = 0;
    while(l <= r){
        if(l == r){
            count++;
            l++;
            r--;
        }
        else if(p[l] + p[r] <= x){
            count++;
            l++;
            r--;
        }
        else{
            r--;
            count++;
        }
    }

    cout << count << '\n';



    return 0;
}

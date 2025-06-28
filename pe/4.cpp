#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll mx = -1;

    for(int i = 0; i <= 999; i++){
        for(ll j = i; j <= 999; j++){
            string s = to_string(i*j);

            bool pal = true;
            for(ll l = 0, r = s.size() - 1; l < r; ){
                if(s[l] != s[r]) pal = false;
                l++;
                r--;
            }
                if(pal){
                    mx = max(mx, i*j);
                    cout << i << ' ' << j << ' ' << i * j << '\n';
                }
        }
    }
    cout << mx << '\n';
}

// 2 3 2 5 7 2 3 11 13 2 17 19

#include <iostream>
#define ll long long 
using namespace std;

void solve(){
    ll n; cin >> n;
    ll a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i];  
    for(int i = 0; i < n; i++) cin >> b[i];  

    ll maxa[n + 1], maxb[n];

    maxa[n] = 0;
    maxb[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        maxa[i] = (a[i] < 1) ? maxa[i + 1] : maxa[i + 1] + 1;
        maxb[i] = (b[i] < 1) ? maxb[i + 1] : maxb[i + 1] + 1;
    }

    ll ascore = 0, bscore = 0;

    for(int i = 0; i < n; i++){
        if(a[i] == b[i]){
            if(a[i] == 1){
                if(maxa[i] + ascore > maxb[i] + bscore){
                    bscore++;
                }
                else{
                    ascore++;
                }
            }
            else if(a[i] == -1){
                if(maxa[i] + ascore > maxb[i] + bscore){
                    ascore--;
                }
                else{
                    bscore--;
                }
            }
        }
        else{
            if(a[i] == -1) bscore += b[i]; 
            else if(b[i] == -1) ascore += a[i];
            else if(a[i] == 0) bscore += b[i]; 
            else if(b[i] == 0) ascore += a[i];
        }
    }

    cout << min(ascore, bscore) << '\n';










}



int main(){
    ll t; cin >> t;
    while(t--) solve();
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll pow(ll a, ll k){
    if(k == 0) return 1;
    ll temp = pow(a, k/2);
    if(k%2 == 0) return temp*temp;
    else return temp*temp*a;
}

void solve(){
    ll n, q; cin >> n >> q;

    /*
       2^n x 2^n grid

       14
       32


    */

    for(int i = 0; i < q; i++){
        string type; cin >> type;

        if(type == "->"){
            ll x, y; cin >> x >> y;

            // each iteration, calculate which corner (x, y) belongs to
            ll lo = 1, hi = pow(2, 2*n);
            ll quarter = pow(2, 2*n - 2); // quarter of number values inside current range
            ll half = pow(2, n - 1); // half the side length of the current grid
            while(lo < hi){

                // top left
                if(x <= half && y <= half){
                    hi -= 3*quarter;
                }

                // bottom right
                if(x > half && y > half){
                    lo += quarter;
                    hi -= 2*quarter;
                    x -= half;
                    y -= half;
                }

                // bottom left
                if(x > half && y <= half){
                    lo += 2*quarter;
                    hi -= quarter;
                    x -= half;
                }

                // top right
                if(x <= half && y > half){
                    lo += 3*quarter;
                    y -= half;
                }

                half /= 2;
                quarter /= 4;
            }
            cout << lo << '\n';
        }
        else{
            ll d; cin >> d;

            // each iteration, calculate which quarter d belongs to 
            ll lox = 1, hix = pow(2, n);
            ll loy = 1, hiy = pow(2, n);
            ll quarter = pow(2, 2*n - 2); // quarter of number values inside current range
            ll half = pow(2, n - 1); // half the side length of current grid
            while(lox < hix){
                // first quarter
                if(d <= quarter){
                    hix -= half;
                    hiy -= half;
                }

                // second quarter
                else if(d <= 2*quarter){
                    lox += half;
                    loy += half;
                    d -= quarter;
                }

                // third quarter
                else if(d <= 3*quarter){
                    lox += half;
                    hiy -= half;
                    d -= 2*quarter;
                }

                // fourth quarter
                else if(d <= 4*quarter){
                    hix -= half;
                    loy += half;
                    d -= 3*quarter;
                }

                half /= 2;
                quarter /= 4;
            }
            cout << lox << ' ' << loy << '\n';
        }








    }

}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

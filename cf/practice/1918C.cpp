#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a, b, r; cin >> a >> b >> r;

    // find min of |a^x - b^x| for 0 <= x <= r

    // want to minimize difference in a^x, b^x.

    // if a = 0, b = 0, x doesnt matter
    // if a = 1, b = 0, x 


    // x is a mask that can swap upto floor(log2(r))th bit in a and b


    // 0110110 ->  
    // 1101101

    // wlog find most significant bit where a = 1 and b = 0, afterwards, in any bit where a != b, give b the bit

    bitset<64> A(a), B(b);


    if(A == B){
        cout << 0 << '\n';
        return;
    }



    bool Abigger = true;
    int j = -1; // first index A and B differ
    for(int i = 63; i >= 0; i--){
        if(A[i] != B[i]){
            if(A[i] == 0) Abigger = false;
            j = i;
            break;
        }
    }


    bitset<64> x(0);

    for(int i = j - 1; i >= 0; i--){
        bitset<64> temp = x;

        if(Abigger){
            if(A[i] == 1 && B[i] == 0){
                temp[i] = 1;
            }
        }
        else{
            if(A[i] == 0 && B[i] == 1){
                temp[i] = 1;
            }
        }

        if(temp.to_ullong() <= r){
            x = temp;
        }
    }

    ll al = (A^x).to_ullong();
    ll bl = (B^x).to_ullong();


    cout << abs(al - bl) << '\n';













}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

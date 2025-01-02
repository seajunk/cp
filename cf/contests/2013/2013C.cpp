#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;

    // pw = 001100
    // 0? 1
    // 00? 1
    // 000? 0
    // 001? 1
    // 0010? 0
    // 0011? 1
    // 00110? 1
    // 001100? 1


    // pw = 101100
    // 0? 1
    // 00? 1
    // 000? 0
    // 001? 0 // now we know string ends with 100(?)
    // 0100? 0
    // 1100? 1
    // 01100? 1
    // 001100? 0
    // 101100? 1

    // if query b0 ? and b1 ? both get answered no, b is suffix of pw(?) so change directions


    bool goright = true;
    ll cntno = 0;
    string curr = "";
    for(int i = 0; i < 2*n; i++){

        ll reply;
        if(goright){
            cout << "? " << curr << '0' << '\n';
            cin >> reply;
            if(reply == 0){
                cout << "? " << curr << '1' << '\n';
                cin >> reply;
                if(reply == 0){
                    // curr is suffix of pw(?)
                    goright = !goright;
                }
                else{
                    curr = curr + "1";
                }
            }
            else{
                curr = curr + "0";
            }
        }

        else{
            cout << "? " << '1' << curr << '\n';
            cin >> reply;
            if(reply == 0){
                cout << "? " << '0' << curr  << '\n';
                cin >> reply;
                if(reply == 0){
                    // curr is suffix of pw(?)
                    goright = !goright;
                }
                else{
                    curr = "0" + curr;
                }
            }
            else{
                curr = "1" + curr;
            }
        }


        if(curr.size() == n){
            cout << "! " << curr << '\n';
            fflush(stdout);
            return;
        }
    }
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
}

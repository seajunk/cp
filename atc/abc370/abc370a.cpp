#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll l, r; cin >> l >> r;
    if(l == 0 && r == 1){
        cout << "No" << '\n';
    }
    else if(l == 1 && r == 0){
        cout << "Yes" << '\n';
    }
    else{
        cout << "Invalid" << '\n';
    }
    return 0;
}

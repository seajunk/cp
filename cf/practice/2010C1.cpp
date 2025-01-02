#include <iostream>
#include <string>
#define ll long long
using namespace std;

void solve(){
    string s;
    cin >> s;
    ll n = s.size();
    if(n < 3){
        cout << "NO" << '\n';
        return;
    }

    for(int i = n / 2 + 1; i <= n - 1; i++){
        // 0 1 2 3 4
        // 0 1 2  
        //     2 3 4
        if(s.substr(0, i) == s.substr(n - i, i)){
            cout << "YES" << '\n';
            cout << s.substr(0, i) << '\n';
            return;
        }
    }
    cout << "NO" << '\n';

}

int main(){
    solve();
}

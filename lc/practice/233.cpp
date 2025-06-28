#include <bits/stdc++.h>
using namespace std;


long long countDigitOne(int n) {



    string s = to_string(n);


    long long ans = 0;
    long long curr = 10;

    for(int i = 0; i < s.size(); i++){

        ans += (n / curr) * (curr / 10);
        long long r = n % curr;
        if(r / (curr / 10) > 1) ans += curr / 10; 
        else if(r / (curr / 10) == 1) ans += r - (curr / 10) + 1;
        curr *= 10;
    }


    cout << ans << '\n';
    return ans;
}

int main(){
    while(true){
        int n; cin >> n;
        countDigitOne(n);
    }
}

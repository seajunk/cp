#include <bits/stdc++.h>
#define ll long long
using namespace std;





void solve2(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<ll>> dp(n/2, {LLONG_MAX, LLONG_MAX}); // dp[i][0] => didnt flip, dp[i][1] => fliped

    ll cnt = 0;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]) cnt++;
    }
    dp[0][0] = cnt;

    cnt = 0;
    vector<ll> b = a;
    swap(b[0], b[n - 1]);
    for(int i = 1; i < n; i++){
        if(b[i] == b[i - 1]) cnt++;
    }
    dp[0][1] = cnt;

    for(int i = 1; i < n/2; i++){
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);

        b = a;
        // nff
        swap(b[i], b[n - 1 - i]);
        ll curr, prev;
        
        prev = (a[i - 1] == a[i]) + (a[i] == a[i + 1]) + (a[n - 1 - (i - 1)] == a[n - 1 - (i)]) + (a[n - 1 - i] == a[n - 1 - (i + 1)]) - ((abs(n - 1 - i - i) < 2) && (a[i] == a[n - 1 - i]));
        curr = (b[i - 1] == b[i]) + (b[i] == b[i + 1]) + (b[n - 1 - (i - 1)] == b[n - 1 - (i)]) + (b[n - 1 - i] == b[n - 1 - (i + 1)]) - ((abs(n - 1 - i - i) < 2) && (b[i] == b[n - 1 - i]));

        dp[i][1] = dp[i - 1][0] + (curr - prev);

        b = a;
        swap(b[i - 1], b[n - 1 - (i - 1)]);
        swap(b[i], b[n - 1 - i]);

        prev = (a[i - 1] == a[i]) + (a[i] == a[i + 1]) + (a[n - 1 - (i - 1)] == a[n - 1 - (i)]) + (a[n - 1 - i] == a[n - 1 - (i + 1)]) - ((abs(n - 1 - i - i) < 2) && (a[i] == a[n - 1 - i]));
        curr = (b[i - 1] == b[i]) + (b[i] == b[i + 1]) + (b[n - 1 - (i - 1)] == b[n - 1 - (i)]) + (b[n - 1 - i] == b[n - 1 - (i + 1)]) - ((abs(n - 1 - i - i) < 2) && (b[i] == b[n - 1 - i]));

        dp[i][1] = min(dp[i][1], dp[i - 1][1] + (curr - prev));

    }


    cout << min(dp[n/2 - 1][1], dp[n/2 - 1][0]) << '\n';



}





// dp manually simulates swap and counts disturbence
void solve1(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<ll>> dp(n/2, {LLONG_MAX, LLONG_MAX}); // dp[i][0] => didnt flip, dp[i][1] => fliped

    ll cnt = 0;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]) cnt++;
    }
    dp[0][0] = cnt;

    cnt = 0;
    vector<ll> b = a;
    swap(b[0], b[n - 1]);
    for(int i = 1; i < n; i++){
        if(b[i] == b[i - 1]) cnt++;
    }
    dp[0][1] = cnt;

    for(int i = 1; i < n/2; i++){
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);

        cnt = 0;
        b = a;
        swap(b[i], b[n - 1 - i]);
        for(int j = 1; j < n; j++){
            if(b[j - 1] == b[j]) cnt++;
        }

        dp[i][1] = cnt;

        b = a;
        swap(b[i - 1], b[n - 1 - (i - 1)]);
        swap(b[i], b[n - 1 - i]);


        for(int j = 1; j < n; j++){
            if(b[j - 1] == b[j]) cnt++;
        }

        dp[i][1] = min(dp[i][1], cnt);
        

    }



    for(vector<ll> e : dp){
        cout << e[0] << ' ' << e[1] << '\n';
    }



}

int main(){
    ll t; cin >> t;
    while(t--) solve2();
}

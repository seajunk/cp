#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices){
    int n = prices.size();

    int pfmn[n + 1]; 
    pfmn[0] = INT_MAX;
    for(int i = 1; i <= n; i++) pfmn[i] = min(prices[i - 1], pfmn[i - 1]);

    int sfmx[n + 1];
    sfmx[n] = 0;
    for(int i = n - 1; i >= 0; i--) sfmx[i] = max(sfmx[i + 1], prices[i]);


    int a[n]; // a[i] = optimal profit if we buy prices[i]
    for(int i = 0; i < n; i++){
        a[i] = sfmx[i] - prices[i];
    }

    int b[n]; // b[i] = optimal profit if we sell prices[i]
    for(int i = 0; i < n; i++){
        b[i] = prices[i] - pfmn[i + 1];
    }

    int pfopt[n + 1]; // optimal profit from trade in [0, i)
    pfopt[0] = 0;
    for(int i = 1; i <= n; i++) pfopt[i] = max(pfopt[i - 1], b[i - 1]);


    int sfopt[n + 1]; // optimal profit from trade in [i, n)
    sfopt[n] = 0;
    for(int i = n - 1; i >= 0; i--) sfopt[i] = max(sfopt[i + 1], a[i]);

    int ans = 0;


    for(int i = 0; i <= n; i++){
        ans = max(ans, sfopt[i] + pfopt[i]);
    }




    return ans;
}

int main(){
    vector<int> prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices) << '\n';
}

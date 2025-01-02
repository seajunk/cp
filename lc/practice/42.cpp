#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height){
    int n = height.size();

    int pfmx[n + 1]; // pfmx[i] = max on [0, i)
    pfmx[0] = -1;
    for(int i = 1; i <= n; i++) pfmx[i] = max(pfmx[i - 1], height[i - 1]);


    int sfmx[n + 1]; // sfmx[i] = max on [i, n)
    sfmx[n] = -1;
    for(int i = n - 1; i >= 0; i--) sfmx[i] = max(sfmx[i + 1], height[i]);




    int ans = 0;


    for(int i = 0; i < n; i++){
        int leftmx = pfmx[i]; // [0, i)
        int rightmx = sfmx[i + 1]; // [i + 1, n)


        if(height[i] < min(leftmx, rightmx)) ans += min(leftmx, rightmx) - height[i];
    }





    return ans;
}

int main(){

    vector<int> height = {4, 2, 0, 3, 2, 5};

    cout << trap(height) << '\n';;

}

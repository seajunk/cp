#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){


    // o: left partition of the merged array consists of prefix of the two arrays since otherwise the merged array isnt sorted 

    // fixing prefix for one of the arrays also fixes the prefix for other array. then its possible to iterate over each possible prefix for O(n)

    int n = nums1.size();
    int m = nums2.size();

    // search space for i [max((n + m)/2 - m, 0) , (n + m)/2]  
    // want smallest i such that largest guy in left partition is less than smallest guy in right partition ? 

    // 2 4 6 8 10
    // 1 3 5

    // 2 , 4 6 8 10
    // 1 3 5,

    // 2 4 6, 8 10
    // 1, 3 5

    // 2 4 ,6 8 10
    // 1 3 ,5

    int lo = max((n + m)/2 - m, 0), hi = min((n + m)/2, n) + 1;
    printf("lo = %d, hi = %d\n", lo, hi);

    while(lo < hi){
        int i = (hi - lo)/2 + lo;

        int j = (n + m)/2 - i;

        // these choices of prefix work if max(nums1[i - 1], nums2[j - 1]) <= min(nums1[i], nums2[j])

        int a = (i == 0) ? -1 : nums1[i - 1];
        int b = (i == n) ? INT_MAX : nums1[i];
        int c = (j == 0) ? -1 : nums2[j - 1];
        int d = (j == m) ? INT_MAX : nums2[j];

        if(c <= b) hi = i; 
        else lo = i + 1;
    }
    if(lo == (n + m)/2 + 1){
        cout << "shit went wrong\n";
        return -1;
    }

    int i = lo;
    int j = (n + m)/2 - i;

    int a = (i == 0) ? -1 : nums1[i - 1];
    int b = (i == n) ? INT_MAX : nums1[i];
    int c = (j == 0) ? -1 : nums2[j - 1];
    int d = (j == m) ? INT_MAX : nums2[j];

    double ans = (max(a, c) + min(b, d));
    ans /= 2;
    if((n + m) % 2 == 0) return ans;
    else return min(b, d);
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    cout << findMedianSortedArrays(a, b) << '\n';



}

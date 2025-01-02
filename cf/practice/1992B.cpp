#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

// greedy two pointers. Sort pieces by length. Keep track of smallest and largest pieces. While more than one piece left, if smallest is == 1, add it to biggest. If smallest is > 1, split into 1, smallest - 1. In the code, instead of re adding 1 back into start of array, we instead subtract 1 from left and add it to right. 

int main(){
	ll t, n, k, in, l, r, ans;
	vector<ll> a;

	cin >> t;
	for(int test = 0; test < t; test++){
		cin >> n >> k;
		a.clear();
		for(int i = 0; i < k; i++){
			cin >> in;
			a.push_back(in);
		}
		sort(a.begin(), a.end());
		l = 0;
		r = k - 1;
		ans = 0;
		while(l < r){
			if(a[l] == 1){
				a[r] += 1;
				ans += 1;
			}
			else{
				a[r] += a[l];
				ans += 2 * a[l] - 1;
			}
			l += 1;
		}
		cout << ans << '\n';

	}
}

// Takeaway:
// Good job on noticing that the looping process of "choosing" which action to perform doesnt actually need to be simulated, eg if we know we have [3, 5], we dont need to simulate every single step like dividing 3 to 1, 2, adding 1 to 5, etc. you were slightly invorrect tho. Instead of cutting cost by just combining the division step and adding to max step, we can see that all of mn will eventually be divided and added to mx over 2 * mn - 1 steps so just increment ans and largest element by this these values in one iteration instead. the -1 term because eventualyl when mn reaches 1, we only need to add it to mx, instead of dividing then adding to mx.

// The actualy correctness arguemtn is as follows. Suppose our algorithm is about to make its kth choice. Suppose that there exists a sequence of choices O which is a supset of the set of our algorithms first k - 1 choices, eg our current k - 1 choices can be extended to an optimal solution O. We would like to show that after the kth choices, our k choices can be extended to an optimal solution. 
// Now suppose that O_k, the kth choice made by O, is C_k, the kth choice made by our algorithm. Clearly, we can extend first k choices to optimal by just copying O.
// Now suppose that O_k is different to C_k. Suppose our algorithm chooses to add mn, 1, to mx. Well notice that the optimal solution chose instead either split some number, or add 1 to other number. suppose that other number is also mx. Then we can just swap the choices made by our algorithm and the optimal, so our choices are optimlly extendable. Now suppose that number is not mx. Then we have a contradiction as O is wasting moves as at best this num will now equal to mx, at which point one of the maxes will have to decompose into the other one, which means removing from num again, which is a wasted move and is not optimal, so this case cant happen. Now suppose then that O chose to split sum other number. Well we know eventually O will need to add to mx or possible some other parition with equal length to mx. Suppose O adds to mx. Then we can swap this choicie with O's kth choice to get a new optimal O', which is a supset of C_k, so optimally extendable. Now suppose O adds to some other partiiton with same length as mx. Well we can just swap O_k and C_k and this new O' is still optimal since partitions with same length are indistinguishable in the ways that matter. so extendable in this case. Now Suppose our algorithm decided to split mn into 1, mn - 1. If O_k does something different, it nessecarily follows that it must have split sosme other number than mn. This is because for O_k to be splitting a mn means no 1's exist at this moment, thus O cant add anything to anything. Now lets suppose O_k split some other value num which is not mn(lets ignore the case theyre equal since argument is same as previous case, just tedious). Clearly, num > mn since arr is sorted. Notice that O will eventually also need to split mn since if we suppose otherwise, then that means mn is what O adds to construct n, which is not possbile since that will result in wasted moves since num > mn, so at the very least, using num to construct n will result in strictly less steps, thus contradiction. So we have that O eventually splits mn at some point O_l. Now just swap O_l and O_k to get O' and we have that O' is still optimal since swapping moves preserves number of steps, and O' is superset of C_k. All cases solved, QED.




#include<iostream>
#include<string>
#include<cctype>
#include<set>
using namespace std;

int main(){
		set<char> bag = {'a', 'e', 'i', 'o' ,'u', 'y'};
		string s, ans;
		cin >> s;
		ans = "";


		for(int i = 0; i < s.size(); i++){
				if(bag.find(tolower(s[i])) != bag.end()) continue;
				else{
						ans += ".";
						ans += tolower(s[i]);
				}

		}
		cout << ans << '\n';

}

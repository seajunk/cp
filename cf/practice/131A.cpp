#include<iostream>
#include<string>
#include<cctype>
using namespace std;


int main(){
		string s;
		cin >> s;
		int c = 0;
		for(int i = 1; i < s.size(); i++){
				if(isupper(s[i])) c++;
		}
		if(c != s.size() - 1) cout << s << '\n';
		else{
				for(int i = 0; i < s.size(); i++){
						if(islower(s[i])) s[i] = toupper(s[i]);
						else s[i] = tolower(s[i]);
				}
				cout << s << '\n';
		}
				

}


#include <bits/stdc++.h>
using namespace std;

string s;

int dp(int x, map<int, int> &memo) {
	if (x == s.size()) return 1;
	else if (memo.count(x)) return memo[x];

	int ans = 0;

	if (s[x] >= '1')
		ans += dp(x+1,memo);

	if (x < s.size()-1 && s[x] >= '1' && s[x] <= '2' && s[x+1] <= '6')
		ans += dp(x+2,memo);

	return memo[x]=ans;
};


int main () {

	while (1) {
		cin >> s;
		if (s=="0") break;
		map<int, int> memo;
		cout << dp(0, memo) << "\n";
	}



};
#include <bits/stdc++.h>

using namespace std;

int main () {

	int n; cin >> n;
	set<long long> s;
	while(n--) {
		long long v; cin >> v; s.insert(v);
	}

	cout << s.size() << "\n";

	return 0;
}
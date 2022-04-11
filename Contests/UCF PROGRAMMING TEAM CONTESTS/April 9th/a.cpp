#include <bits/stdc++.h>
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

int main () {

    int letters; cin >> letters;
    map<char, bool> letterMap;

    int i = 0;
    while (letters--) {
        char boolVal; cin >> boolVal;
        if (!letterMap.count('A'+i))
            letterMap['A'+i] = boolVal == 'T';
        i++;
    };

    char nl;
    scanf("%c", &nl);
    string opstr;
    vector<bool> ops;
    getline(cin, opstr);

    int x;
    range(0, opstr.size(), 1, x) {
        char c = opstr[x];
        if (c == ' ') continue;
        else if (ops.size() == 0) {
            ops.push_back(letterMap[c]);
        } else {
            if (c == '*') {

                int u = ops.back();
                ops.pop_back();
                int v = ops.back();
                ops.pop_back();
                ops.push_back(u && v);

            } else if (c == '+') {

                int u = ops.back();
                ops.pop_back();
                int v = ops.back();
                ops.pop_back();
                ops.push_back(u || v);

            } else if (c == '-') {

                int u = ops.back();
                ops.pop_back();
                ops.push_back(!u);

            } else {
                ops.push_back(letterMap[c]);
            };
        };
    };

    cout << (ops.back() ? 'T' : 'F') << "\n";
    return 0;
};
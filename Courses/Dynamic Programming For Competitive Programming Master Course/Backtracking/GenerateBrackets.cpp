#include <bits/stdc++.h>
 
#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*DEFINES*/

#define add push_back
#define rem pop_back
#define ins insert
#define co count
#define fi first
#define se second
#define sorter(a, comp) sort(a.begin(), a.end(), comp)
#define sz(a) a.size()
#define nl << "\n"
#define cnl cout << "\n"


/*
TYPEDEFS
*/

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pllll;

/*
SET TYPEDEFS
*/

typedef set<int> si;
typedef set<ll> sll;
typedef set<string> ss;
typedef set<pii > spii;
typedef set<pllll > spllll;

/*
VECTOR TYPEDEFS
*/

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii > vpii;

/*
MAP TYPEDEFS
*/

typedef map<int, int> mii;
typedef map<ll, ll> mllll;
typedef map<string, int> msi;
typedef map<char, int> mci;
typedef map<int, vi > mivi;
typedef map<string, vs > msvs;

// Bruteforce solution. Only count / print the valid solutions...
// Naive with solution balancing.
// Time Complexity: O(n2^n)
// Space Complexity: O(2^n)
int generateBracketsNaive(int open, int closed, string s = "") {
    // if we have exhausted all possible placement options... n pairs of ( and )
    if (open == 0 && closed == 0) {
        // use vector as a stack for balance checking...
        vector<char> stk;
        // iterate through the possible solution...
        for (char c: s) {
            // if nothing is in the stack, add whatever is found.
            if (sz(stk) == 0)
                stk.push_back(c);
            // if something is in the stack...
            else {
                // balanced subsequence found... pop open bracket.
                if (stk.back() == '(' && c == ')')
                    stk.pop_back();
                // unbalanced case! add it in for balance verification based on size...
                else
                    stk.push_back(c);
            };
        };

        // if stack size is 0, this solution is balanced and therefore valid.
        if (stk.size() == 0) {
            // print and account for the solution.
            cout << s nl;
            return 1;
        };

        // do not account for the solution, it is invalid.
        return 0;
    
    // if we overplaced... stop exploring. do not account for.
    } else if (open < 0 || closed < 0)
        return 0;

    int ans = 0;
    // take the open parenthesis, recurse, and backtrack
    s.push_back('(');
    ans += generateBracketsNaive(open-1, closed, s);
    s.pop_back();

    // take the closed parenthesis, recurse, and backtrack
    s.push_back(')');
    ans += generateBracketsNaive(open, closed-1, s);
    s.pop_back();

    // return count valid!
    return ans;
};


void generateBrackets(int n, int open = 0, int close = 0, string s = "") {
    if (sz(s) == (n<<1)) {
        cout << s nl;
        return;
    };

    if (open < n)
        generateBrackets(n, open+1, close, s+'(');
    
    if (close < open)
        generateBrackets(n, open, close+1, s+')');

};

int main () {

    int n; cin >> n;
    generateBrackets(n);

    return 0;
};
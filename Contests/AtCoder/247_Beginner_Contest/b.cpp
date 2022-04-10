#include <iostream>
#include <string>
#include <vector>
#include <set>

#define range(startInc, endEx, step, var) for (var = startInc; step < 0 ? var > endEx : var < endEx; var += step)
using namespace std;

/*

I had to resubmit this solution multiple times as I was failing a test case due to a condition that was very subtle and indirect I did not pick up on.
I did not understand what they meant by a_i is s_i and/or t_i...
This means the person can have the same given name and last name, like the greatest Gambean player of all time, Biri Biri.

The strategy is simple:

Read in all the pairs of an a_ith person.
As they are read in, if the full name of the given person is exact to that of an already read in person, then stop, it is not possible to give everyone nicknames.
Else, add the full name pair to the fullNames set. Also, add to seen names the given name, and ONLY IF s_i DOES NOT EQUAL t_i add in the family name.
    - This is important, seeing a name twice for one person really only counts as one for that person and in general.

Then, iterate through the set of full name pairs.
If at any given full name pair the count of both the given name and the family name are > 1, then it is not possible to give everyone nicknames.

Indirectly, we are saying to let a_i "assume" 1 of two names possible per a_i that only has a count of 1, however it does not need to be explicitly handled.
If we get through all fine, it is possible to give everyone nicknames.

*/

int main () {

    int n; cin >> n;
    set<pair<string, string> > fullNames;
    multiset<string> seenNames;

    while (n--) {
        string s, t; cin >> s >> t;
        pair<string, string> fn = make_pair(s, t);
        if (fullNames.count(fn)) {
            cout << "No\n";
            return 0;
        };

        fullNames.insert(fn);
        seenNames.insert(s);

        // EDGE CASE!
        if (s != t)
            seenNames.insert(t);
    };

    set<pair<string, string> >::iterator it = fullNames.begin();
    while (it != fullNames.end()) {
        if (seenNames.count((*it).first) > 1 && seenNames.count((*it).second) > 1) {
            cout << "No\n";
            return 0;
        };

        it++;
    };

    cout << "Yes\n";

    return 0;
}
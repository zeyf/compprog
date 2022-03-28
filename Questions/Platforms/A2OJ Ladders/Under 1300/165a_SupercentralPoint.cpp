#include <bits/stdc++.h>
 
#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

int shift(int i) { return i+1000; };

/*

Idea:

Create an alternative data structure to store the points and their relationships to other points in an easy, and inexpensive manner.
Went with a vector of pointers to sets (most are null except on very sparse graphs)
Two of these set vectors, one for the X axis, one for the Y axis.
For a point with a given x axis, the y axis of that point was added into the set for that x axis.
For a point with a given y axis, the x axis of that point was dded into the set for that y axis.
These numbers where shifted upwards based on the constraints -- FORALL |x|,|y|IN SET COMPLEMENT(Z-)(0<=x<=1000, 0<=y<=1000)
This means that at most each axis had 2001 pointers, [-1000,1000]. by adding 1000, this range is indexable to [0,2000]

Then I iterated over the points again, and took the shifted x axis and y axis and did the following to both:
    - Search for lower value in the set of points than the shifted X axis (Y axis)
    - Search for higher value in the set of points than the shifted X axis (Y axis)
    - Search for lower value in the set of points than the shifted Y axis (X axis)
    - Search for higher value in the set of points than the shifted Y axis (X axis)

If a lower y axis for an x was found, a higher y axis for an x was found, a lower x axis for a given y was found, and a higher x axis for a given y was found, then a supercentral point was found.

*/

int main () {
 
    int n;
    cin >> n;
    vector<pair<int, int> > points;
    vector<set<int>*> xAxis(2001, NULL), yAxis(2001, NULL);

    loop(0, n) {
        int a, b, shiftedA, shiftedB;
        cin >> a >> b;
        points.push_back(make_pair(a, b));
        shiftedA = shift(a), shiftedB = shift(b);

        if (xAxis[shiftedA] == NULL)
            xAxis[shiftedA] = new set<int>();
        xAxis[shiftedA]->insert(shiftedB);

        if (yAxis[shiftedB] == NULL)
            yAxis[shiftedB] = new set<int>();
        yAxis[shiftedB]->insert(shiftedA);

    };

    int scp = 0;

    loop(0, n) {
        pair<int, int> point = points[x];
        int shiftedA = shift(point.first), shiftedB = shift(point.second);
        set<int>::iterator xAxisLowBound = xAxis[shiftedA]->upper_bound(-1), xAxisHighBound = xAxis[shiftedA]->upper_bound(shiftedB), yAxisLowBound = yAxis[shiftedB]->upper_bound(-1), yAxisHighBound = yAxis[shiftedB]->upper_bound(shiftedA);
        
        if (*xAxisLowBound != shiftedB && xAxisHighBound != xAxis[shiftedA]->end() && *yAxisLowBound != shiftedA && yAxisHighBound != yAxis[shiftedB]->end())
            scp++;
    };

    cout << scp << "\n";

    return 0;
}
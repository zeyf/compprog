#include <bits/stdc++.h>
 
#define loop(s, e) for (int x = s; x < e; x++)
using namespace std;

/*

Idea:

Read in the pages count, store the pages read on each day of the week.
Then while page count is greater than 0, read the pages. if that finishes the book, break out.
Else, increment the weekDay as you are not yet done with your book.
If you get to weekDay 8, you know that you have hit another week and must reset weekday to 1.
Print the final weekDay.

*/

int main () {
 
    int pc, weekSum = 0;
    cin >> pc;
    int *arr = new int[7];
    loop(0, 7) {
        cin >> arr[x];
        weekSum += arr[x];
    };


    int weekDay = 1;
    while (pc > 0) {
        loop(0, 7) {
            pc -= arr[x];
            if (pc <= 0) break;
            weekDay++;
        };
        if (weekDay == 8) weekDay = 1;
    };


    cout << weekDay << "\n";

    return 0;
}
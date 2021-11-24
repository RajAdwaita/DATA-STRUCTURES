// Let's denote the Manhattan distance between two points p1 (with coordinates (x1,y1)) and p2 (with coordinates (x2,y2)) as d(p1,p2)=|x1−x2|+|y1−y2|. For example, the distance between two points with coordinates (1,3) and (4,2) is |1−4|+|3−2|=4.

//     You are given two points,
//     A and B.The point A has coordinates(0, 0), the point B has coordinates(x, y).

//                                                    Your goal is to find a point C such that :

//     both coordinates of C are non - negative integers;
// d(A, C) = d(A, B) 2(without any rounding);
// d(B, C) = d(A, B) 2(without any rounding).Find any point C that meets these constraints, or report that no such point exists.

//                                                                                              Input
//                                                                                              The first line contains one integer t(1≤t≤3000) — the number of test cases.

//                                                                                              Each test case consists of one line containing two integers x and y(0≤x, y≤50) — the coordinates of the point B.

//                                                                                              Output
//                                                                                              For each test case,
//      print the answer on a separate line as follows :

//     if it is impossible to find a point C meeting the constraints,
//      print "-1 -1"(without quotes);
// otherwise, print two non - negative integers not exceeding 106 — the coordinates of point C meeting the constraints.If there are multiple answers, print any of them.It can be shown that if any such point exists, it's possible to find a point with coordinates not exceeding 106 that meets the constraints.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if ((x + y) % 2 != 0)
        {
            cout << "-1 -1" << endl;
        }
        else
        {
            if (x % 2 == 0 && y % 2 == 0)
            {
                cout << x / 2 << " " << y / 2 << endl;
            }
            else
            {
                int tot = x + y;
                tot /= 2;
                if (x > y)
                {
                    cout << abs(x - tot) << " " << y << endl;
                }
                else
                {
                    cout << x << " " << abs(y - tot) << endl;
                }
                // else
                // {
                //     cout << x << " " << y << endl;
                // }
            }
        }
    }
    return 0;
}
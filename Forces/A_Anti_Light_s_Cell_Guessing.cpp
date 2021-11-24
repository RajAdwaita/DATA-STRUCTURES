// You are playing a game on a n×m grid, in which the computer has selected some cell (x,y) of the grid, and you have to determine which one.

// To do so, you will choose some k and some k cells (x1,y1),(x2,y2),…,(xk,yk), and give them to the computer. In response, you will get k numbers b1,b2,…bk, where bi is the manhattan distance from (xi,yi) to the hidden cell (x,y) (so you know which distance corresponds to which of k input cells).

// After receiving these b1,b2,…,bk, you have to be able to determine the hidden cell. What is the smallest k for which is it possible to always guess the hidden cell correctly, no matter what cell computer chooses?

// As a reminder, the manhattan distance between cells (a1,b1) and (a2,b2) is equal to |a1−a2|+|b1−b2|.

// Input
// The first line of the input contains a single integer t (1≤t≤104) — the number of test cases. The description of test cases follows.

// The single line of each test case contains two integers n and m (1≤n,m≤109) — the number of rows and the number of columns in the grid.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int k;
        cin >> k;
        int x, y;
        cin >> x >> y;
        vector<int> b(k);
        for (int i = 0; i < k; i++)
            cin >> b[i];
        sort(b.begin(), b.end());
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            int cur = b[i];
            int l = 0, r = k - 1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (b[mid] <= cur)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            ans = max(ans, k - l);
        }
        cout << ans << "\n";
    }

    return 0;
}
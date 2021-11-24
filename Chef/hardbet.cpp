#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int sa, sb, sc;
        cin >> sa >> sb >> sc;
        if (sb < sa && sb < sc)
        {
            cout << "Bob" << endl;
        }
        else if (sc < sa && sc < sb)
        {
            cout << "Alice" << endl;
        }
        else {
            cout << "Draw" << endl;
        }

    }
    return 0;
}
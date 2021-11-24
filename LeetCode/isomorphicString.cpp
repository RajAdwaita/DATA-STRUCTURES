#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    set<char> s1;
    set<char> s2;

    for (int i = 0; i < s.length(); i++)
    {

        s1.insert(s[i]);
        s2.insert(t[i]);
    }

    if (s1.size() == s2.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    if (isIsomorphic("raj", "adw"))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

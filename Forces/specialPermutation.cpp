// A permutation of length n is an array p = [ p1, p2,…, pn ] which contains every integer from 1 to n(inclusive) exactly once.For example, p = [ 4, 2, 6, 5, 3, 1 ] is a permutation of length 6.

//                                                                                                                                          You are given three integers n,
//                                       a and b, where n is an even number.Print any permutation of length n that the minimum among all its elements of the left half equals a and the maximum among all its elements of the right half equals b.Print - 1 if no such permutation exists.

//                                                                                                                                                                                                                                                        Input The first line of the input contains one integer t(1≤t≤1000),
//                                       the number of test cases in the test.The following t lines contain test case descriptions.

//                                       Each test case description contains three integers n,
//                                       a, b(2≤n≤100; 1≤a, b≤n; a≠b), where n is an even number(i.e.nmod2 = 0).

#include <bits/stdc++.h>
using namespace std;

vector<int> specialPermutation(int n, int a, int b)
{
    vector<int> ans;
    vector<int> array;
    for (int i = 0; i < n; i++)
    {
        array.push_back(i + 1);
    }
    vector<int> left;
    vector<int> right;

    for (int i = 0; i < n; i++)
    {
        if (i < a - 1 && i + 1 != a && i + 1 != b)
        {
            right.push_back(array[i]);
            // array.erase(array.begin() + i);
        }
        else if (i > b - 1 && i + 1 != a && i + 1 != b)
        {
            left.push_back(array[i]);
            // array.erase(array.begin() + i);
        }
    }

    left.push_back(a);
    right.push_back(b);
    vector<int> tt;
    for (auto &i : left)
    {
        tt.push_back(i);
    }
    for (auto &i : right)
    {
        tt.push_back(i);
    }
    sort(tt.begin(), tt.end());
    vector<int> ee;
    // array.erase(array.begin() + a - 1);
    // array.erase(array.begin() + b - 1);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != tt[k])
            ee.push_back(i + 1);
        else
        {
            k++;
        }
    }

    int ansMaxSize = n / 2;
    for (int i = 0; i < ee.size(); i++)
    {
        if (ee[i] > a && left.size() < ansMaxSize)
        {
            left.push_back(ee[i]);
        }
        else if (ee[i] < b && right.size() < ansMaxSize)
        {
            right.push_back(ee[i]);
        }
    }
    if (left.size() > n / 2 || right.size() > n / 2)
    {
        ans.push_back(-1);
    }
    else
    {
        for (int i = 0; i < left.size(); i++)
        {
            ans.push_back(left[i]);
        }
        for (int i = 0; i < right.size(); i++)
        {
            ans.push_back(right[i]);
        }
    }
    return ans;
    // for (int i = a; i < b; i++)
    // {
    //     if (array[i] > a && left.size() <= ansMaxSize)
    //     {
    //         left.push_back(array[i]);
    //     }
    //     else if (array[i] < b && right.size() <= ansMaxSize)
    //     {
    //         right.push_back(array[i]);
    //     }
    // }
    // if (left.size() + right.size() != n)
    // {
    //     ans.push_back(-1);
    // }
    // else
    // {
    //     for (int i = 0; i < left.size(); i++)
    //     {
    //         ans.push_back(left[i]);
    //     }
    //     for (int i = 0; i < right.size(); i++)
    //     {
    //         ans.push_back(right[i]);
    //     }
    // }
    // return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> ans = specialPermutation(n, a, b);

        for (auto &i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
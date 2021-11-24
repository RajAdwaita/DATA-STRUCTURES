#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int n, m, k;
    std::vector<int> final;
    while (t--)
    {
        cin >> n >> m >> k;
        int arr[k];
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
        }

        unordered_set<int> s;
        for (int i : arr) {
            s.insert(i);
        }

        // for (int i : s)
        // {
        //     cout << i << endl;
        // }

        for (int i = 0; i < s.size(); i++)
        {
            int pre = s[i];
            for (int j = 0; j < k; j++)
            {
                if (arr[j] == )

                }
        }




    }

}
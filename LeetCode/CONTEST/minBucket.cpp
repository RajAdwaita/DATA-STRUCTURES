
// class Solution
// {
// public:
//     int minimumBuckets(string street)
//     {
//         int bucks = 0;
//         if (street.length() == 0)
//             return 0;
//         for (int i = 0; i < street.length(); i++)
//         {
//             if (i == 0 && street[i] == '.')
//             {
//                 if (street[i + 1] == 'H')
//                     bucks++;
//             }
//             if (i == street.size() - 1 && street[i] == '.')
//             {
//                 if (street[i - 1] == 'H')
//                     bucks++;
//             }
//             else
//             {
//                 if ((street[i] == '.' && street[i - 1] == 'H') && street[i + 1] == 'H')
//                     bucks++;
//                 else if ((street[i] == 'H' && street[i + 1] == '.') && street[i + 2] == '.')
//                 {
//                     bucks += 2;
//                     i += 4;
//                 }
//             }
//         }
//         return bucks;
//     }
// };

#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string street = ".H.H";
    int bucks = 0;
    if (street.length() == 0)
        return 0;
    for (int i = 0; i < street.length(); i++)
    {
        if (i == 0 && street[i] == '.')
        {
            if (street[i + 1] == 'H')
                bucks++;
        }
        if (i == street.size() - 1 && street[i] == '.')
        {
            if (street[i - 1] == 'H')
                bucks++;
        }
        else
        {
            if ((street[i] == '.' && street[i - 1] == 'H') && street[i + 1] == 'H')
                bucks++;
            else if ((street[i] == 'H' && street[i + 1] == '.') && street[i + 2] == '.')
            {
                bucks += 2;
                i += 4;
            }
        }
    }
    cout << bucks << endl;

    return 0;
}
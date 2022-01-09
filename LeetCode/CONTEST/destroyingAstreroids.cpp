// You are given an integer mass, which represents the original mass of a planet. You are further given an integer array asteroids, where asteroids[i] is the mass of the ith asteroid.

// You can arrange for the planet to collide with the asteroids in any arbitrary order. If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed.

// Return true if all asteroids can be destroyed. Otherwise, return false.

#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        int tot = 0;
        int ans = 0;
        sort(asteroids.begin(), asteroids.end());
        for (auto &i : asteroids)
        {
            if (i <= mass)
            {
                mass += i;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
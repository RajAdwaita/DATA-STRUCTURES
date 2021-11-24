#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        deque<int> stud;
        for (auto &i : students)
            stud.push_back(i);

        int max_attend = stud.size();
        int c = 0;
        int i = 0;
        while (c < max_attend && i < sandwiches.size())
        {
            if (stud.front() == sandwiches[i])
            {
                max_attend--;
                stud.pop_front();
                i++;
            }
            else
            {
                stud.push_back(stud.front());
                stud.pop_front();
                c++;
            }
        }

        return stud.size();
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

int main() {
        std::vector<int> v;
        v.push_back(12);
        v.push_back(34);

        v.push_back(76);

        v.push_back(189);

        v.push_back(4);

        v.push_back(78);



        std::vector<int> v2 ;
        // v2 = v;
        v2.insert(v2.end(), v.begin() , v.begin() + 2);

        for (auto i : v2)
        {
                cout << i << endl;
        }
}
#include <iostream>

using namespace std;

int main()
{

    int n, k;

    cin >> n >> k;

    int arr[n] = {};

    for (int i{}; i < n; i++)
    {

        cin >> arr[i];
    }

    int max = -1;

    int front[k];

    int back[k];

    front[0] = arr[0];

    for (int i{1}; i < k; i++)
    {

        front[i] = arr[i] + front[i - 1];
    }

    back[k - 1] = 0;

    int t{n - 1};

    for (int i{k - 2}; i >= 0; i--)
    {

        back[i] = arr[t] + back[i + 1];

        t -= 1;
    }

    for (int i{}; i < k; i++)
    {

        int sum = front[i] + back[i];

        if (sum > max)

            max = sum;
    }

    cout << max;
}
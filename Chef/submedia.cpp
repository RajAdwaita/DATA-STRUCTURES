// C++ implementation to find sum
// of all subsequences of length K

#include <bits/stdc++.h>
using namespace std;

int fact(int n);

// Function to find nCr
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Function that returns
// factorial of n
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

// Function for finding sum
// of all K length subsequences
int sumSubsequences(
    int arr[], int n, int k)
{

    int sum = 0;

    // Calculate the sum of array
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int kLengthSubSequence;

    // Calculate nCk
    kLengthSubSequence = nCr(n, k);

    int ans = sum * ((k * kLengthSubSequence) / n);

    // Return the final result
    return ans;
}

// Driver code
int main()
{

    int arr[] = {7, 8, 9, 2};

    int K = 2;

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << sumSubsequences(arr, n, K);
    return 0;
}

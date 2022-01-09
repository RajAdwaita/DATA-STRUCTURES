class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 > n2)
        {
            return false;
        }
        int arr[26] = {0};
        for (int i = 0; i < n1; i++)
        {
            arr[s1[i] - 'a']++;
            // arr[s2[i] - 'a']--;
        }

        for (int i = 0; i < n2 - n1 + 1; i++)
        {
            int arr1[26] = {0};
            for (int j = i; j < n1 + i; j++)
            {
                arr1[s2[j] - 'a']++;
            }
            if (arr = arr1)
            {
                return true;
            }
        }
        return false;
    }
};
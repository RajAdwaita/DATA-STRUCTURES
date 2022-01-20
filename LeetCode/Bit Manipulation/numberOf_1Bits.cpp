class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            count++;
            n &= (n - 1);
        }
        return count;
    }
};

// class Solution
// {
// public:
//     int hammingWeight(uint32_t n)
//     {
//         int count = 0;
//         while (n)
//         {
//             count += n % 2;
//             n /= 2;
//         }
//         return count;
//     }
// };
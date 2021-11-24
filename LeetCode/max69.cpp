class Solution
{
public:
    int maximum69Number(int num)
    {
        int res = 0;
        int flag = 0;
        int n1 = num;
        int p = 0;
        while (n1)
        {
            int d = n1 % 10;
            p = p * 10 + d;
            n1 /= 10;
        }
        num = p;
        while (num)
        {
            int tmp = num % 10;
            if (tmp == 6 && !flag)
            {
                flag = 1;
                res = res * 10 + 9;
            }
            else
            {
                res = res * 10 + tmp;
            }
            num /= 10;
        }
        return res;
    }
};
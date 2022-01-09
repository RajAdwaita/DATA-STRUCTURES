class Solution
{
public:
    int calculate(string s)
    {
        int temp = 0, ans = 0, res = 0;
        char symbol = '+';
        s += "##";
        for (auto &i : s)
        {
            if (i == ' ')
                continue;
            else if (isdigit(i))
            {
                temp = temp * 10 + (i - '0');
            }
            else
            {
                if (symbol == '*')
                    res *= temp;
                else if (symbol == '/')
                    res /= temp;
                else
                {
                    ans += res;
                    res = sumbol == '+' ? temp : -temp;


                }
                symbol = i;
                temp = 0;

            }


        }
        return ans;

    }
};
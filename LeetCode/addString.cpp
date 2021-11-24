class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        stringstream geek(num1);
        int a = 0;
        geek >> a;
        stringstream geek(num2);
        int b = 0;
        geek >> b;
        int c = a + b;
        stringstream ss;
        ss << c;
        string str = ss.str();
        return str;
    }
};
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int c = 0;
        vector<int> v1, v2;
        while (l1)
        {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        ListNode *a, *b;
        a = nullptr;
        int s1 = v1.size() - 1;
        int s2 = v2.size() - 1;

        int carry = 0;
        while (s1 >= 0 || s2 >= 0)
        {
            int sum = 0;
            if (s1 >= 0)
            {
                sum += v1[s1];
                s1--;
            }
            if (s2 >= 0)
            {
                sum += v2[s2];
                s2--;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode *temp = new ListNode(sum);
            temp->next = a;
            a = temp;
        }

        if (carry)
        {
            ListNode *temp = new ListNode(carry);
            temp->next = a;
            a = temp;
        }
        return a;
    }
};
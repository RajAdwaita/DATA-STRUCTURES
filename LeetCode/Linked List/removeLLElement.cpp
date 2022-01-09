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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        ListNode *curr = temp;
        ListNode *prev = temp;
        while (curr != nullptr)
        {
            if (curr->val == val)
            {
                prev->next = curr->next;
            }
            else
            {
                prev = curr;
            }

            curr = curr->next;
        }
        return temp->next;
    }
};
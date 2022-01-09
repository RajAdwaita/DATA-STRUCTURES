#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int i = 0, summ = 0;
    void calc_disp(ListNode *head)
    {
        if (head == nullptr)
            return;
        calc_disp(head->next);
        if (head->val == 1)
        {
            summ += pow(2, n);
        }
        n++;
    }
    int getDecimalValue(ListNode *head)
    {
        calc_disp(head);
        return summ;
    }
};
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }
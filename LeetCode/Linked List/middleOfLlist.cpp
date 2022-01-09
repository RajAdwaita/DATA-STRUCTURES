// #include<bits/stdc++.h>
// using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode *middleNode(ListNode *head)
    {
        int c = 0;
        ListNode *p = head;
        while (p != nullptr)
        {
            c++;
            p = p->next;
        }
        c /= 2;
        p = head;
        while (c)
        {
            p = p->next;
            c--;
        }
        return p->val;
    }
};
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }
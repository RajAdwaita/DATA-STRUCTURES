#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
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
    ListNode *merge(ListNode *A, ListNode *B)
    {
        ListNode *head = new ListNode();
        ListNode *cur = head;
        while (A && B)
        {
            if (A->val < B->val)
            {
                cur->next = A;
                A = A->next;
            }
            else
            {
                cur->next = B;
                B = B->next;
            }
            cur = cur->next;
        }
        if (A)
            cur->next = A;
        if (B)
            cur->next = B;
        return head->next;
    }

    ListNode *sortList(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *second = slow->next;
        slow->next = nullptr;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(second);

        return merge(l1, l2);
    }
};
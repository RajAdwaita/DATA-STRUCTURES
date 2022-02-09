/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start
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

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reorderList(ListNode *head)
    {

        vector<ListNode *> v;
        for (auto i = head; i; i = i->next)
        {
            v.push_back(i);
        }
        int l = 0;
        int r = v.size() - 1;
        for (int i = 0; i < size(v); i++, head = head->next)
        {
            if (i % 2 == 0)
            {
                head->next = v[l];
                l++;
            }
            else
            {
                head->next = v[r];
                r--;
            }
        }
        head->next = NULL;
    }
};
// @lc code=end

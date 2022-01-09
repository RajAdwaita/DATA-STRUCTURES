class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *temp = head;
        int cc = 1;

        while (cc != k)
        {
            temp = temp->next;
            cc++:
        }

        ListNode *temp1 = head;
        ListNode *temp2 = temp;

        while (temp1 && temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        swap(temp1->val, temp2->val);

        return head;
    }
};
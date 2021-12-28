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
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;

        int count = 1;
        ListNode *temp = head;
        while (temp->next)
        {
            count++;
            temp = temp->next;
        }

        if (k >= count)
            k = k % count;
        if (k == 0)
            return head;

        temp->next = head;
        int ind = count - k - 1;
        ListNode *curr = head;
        while (ind--)
        {
            curr = curr->next;
        }
        ListNode *nex = curr->next;
        curr->next = NULL;

        return nex;
    }
};
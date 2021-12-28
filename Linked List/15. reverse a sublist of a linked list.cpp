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
    ListNode *Reverse(ListNode *&head, int k)
    {

        if (!head)
            return NULL;
        ListNode *temp = head;
        ListNode *dummy = NULL;
        ListNode *nex = head->next;

        while (k--)
        {
            head->next = dummy;
            dummy = head;
            head = nex;
            if (nex != NULL)
                nex = nex->next;
        }
        head = temp;
        return dummy;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {

        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        ListNode *post = dummy;
        dummy->next = head;

        for (int i = 0; i < left - 1; i++)
        {
            pre = pre->next;
        }
        for (int i = 0; i < right + 1; i++)
        {
            post = post->next;
        }
        ListNode *curr = pre->next;
        pre->next = Reverse(curr, right - left + 1);
        curr->next = post;

        return dummy->next;
    }
};
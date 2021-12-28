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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return NULL;

        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;

        while (n-- && fast->next != NULL)
        {
            fast = fast->next;
        }
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if (slow == dummy)
        { //if the head node has to deleted
            return slow->next->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
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
    //time complexity:O(n1+n2)
    //space complexity:O(n1+n2)

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
            return NULL;

        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;

        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                ListNode *node = new ListNode(l2->val);
                dummy->next = node;
                l2 = l2->next;
            }
            else
            {
                ListNode *node = new ListNode(l1->val);
                dummy->next = node;
                l1 = l1->next;
            }
            dummy = dummy->next;
        }
        while (l1)
        {
            ListNode *node = new ListNode(l1->val);
            dummy->next = node;
            dummy = dummy->next;
            l1 = l1->next;
        }
        while (l2)
        {
            ListNode *node = new ListNode(l2->val);
            dummy->next = node;
            dummy = dummy->next;
            l2 = l2->next;
        }
        return head->next;
    }
};

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
    //time complexity:O(n1+n2)
    //space complexity:O(1)
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
            return NULL;

        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;

        while (l1 && l2)
        {
            if (l1->val > l2->val)
            {
                dummy->next = l2;
                l2 = l2->next;
            }
            else
            {
                dummy->next = l1;
                l1 = l1->next;
            }
            dummy = dummy->next;
        }
        while (l1)
        {
            dummy->next = l1;
            dummy = dummy->next;
            l1 = l1->next;
        }
        while (l2)
        {
            dummy->next = l2;
            dummy = dummy->next;
            l2 = l2->next;
        }
        return head->next;
    }
};
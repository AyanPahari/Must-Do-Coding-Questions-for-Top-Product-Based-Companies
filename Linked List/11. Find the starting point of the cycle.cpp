/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    //using hashing:

    //Time complexity:O(n)
    //Space complexity:O(n)

public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_map<ListNode *, int> mp;
        while (head != NULL)
        {
            if (mp[head] > 0)
                return head;
            mp[head]++;
            head = head->next;
        }
        return NULL;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    //using slow and fast pointer:

    //Time complexity:O(n)
    //Space complexity:O(1)
    
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        if (slow != fast)
            return NULL;

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
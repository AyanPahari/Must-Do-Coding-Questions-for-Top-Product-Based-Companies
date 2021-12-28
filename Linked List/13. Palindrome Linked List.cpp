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
    //niave approach
    //time complexity:O(n)
    //space complexity:O(n)

    bool isPal(vector<int> ans)
    {
        int i = 0;
        int j = ans.size() - 1;

        while (i < j)
        {
            if (ans[i] != ans[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    bool isPalindrome(ListNode *head)
    {
        vector<int> ans;
        while (head)
        {
            ans.push_back(head->val);
            head = head->next;
        }
        return isPal(ans);
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
    //optimal approach
    //time complexity:O(n)
    //space complexity:O(1)

    ListNode *reverse(ListNode *head)
    {

        if (!head)
            return head;

        ListNode *dummy = NULL;
        ListNode *nex = head->next;

        while (head)
        {
            head->next = dummy;
            dummy = head;
            head = nex;
            if (nex != NULL)
                nex = nex->next;
        }
        return dummy;
    }

    bool isPalindrome(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode *entry = head;

        while (slow)
        {
            if (slow->val != entry->val)
                return false;
            slow = slow->next;
            entry = entry->next;
        }

        return true;
    }
};
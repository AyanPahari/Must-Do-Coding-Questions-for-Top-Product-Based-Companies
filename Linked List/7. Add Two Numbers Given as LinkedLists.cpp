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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        int carry = 0;
        int data = 0;
        while (l1 && l2)
        {
            data = l1->val + l2->val + carry;
            carry = data / 10;
            data = data % 10;
            ListNode *node = new ListNode(data);
            dummy->next = node;
            l1 = l1->next;
            l2 = l2->next;
            dummy = dummy->next;
        }
        while (l1)
        {
            data = l1->val + carry;
            carry = data / 10;
            data = data % 10;
            ListNode *node = new ListNode(data);
            dummy->next = node;
            l1 = l1->next;
            dummy = dummy->next;
        }
        while (l2)
        {
            data = l2->val + carry;
            carry = data / 10;
            data = data % 10;
            ListNode *node = new ListNode(data);
            dummy->next = node;
            l2 = l2->next;
            dummy = dummy->next;
        }
        if (carry)
        {
            ListNode *node = new ListNode(carry);
            dummy->next = node;
            dummy = dummy->next;
        }
        return head->next;
    }
};

//for the gfg version of the question we have to first reverse the input and output, do the required addition and again reverse the result.
//link: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#

class Solution
{
public:
    //Function to add two numbers represented by linked list.

    Node *reverse(Node *head)
    {
        Node *dummy = NULL;
        Node *nex = head->next;

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

    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        Node *l1 = reverse(first);
        Node *l2 = reverse(second);

        Node *dummy = new Node(-1);
        Node *head = dummy;
        int carry = 0;
        int data = 0;
        while (l1 && l2)
        {
            data = l1->data + l2->data + carry;
            carry = data / 10;
            data = data % 10;
            Node *node = new Node(data);
            dummy->next = node;
            l1 = l1->next;
            l2 = l2->next;
            dummy = dummy->next;
        }
        while (l1)
        {
            data = l1->data + carry;
            carry = data / 10;
            data = data % 10;
            Node *node = new Node(data);
            dummy->next = node;
            l1 = l1->next;
            dummy = dummy->next;
        }
        while (l2)
        {
            data = l2->data + carry;
            carry = data / 10;
            data = data % 10;
            Node *node = new Node(data);
            dummy->next = node;
            l2 = l2->next;
            dummy = dummy->next;
        }
        if (carry)
        {
            Node *node = new Node(carry);
            dummy->next = node;
            dummy = dummy->next;
        }
        Node *ans = reverse(head->next);

        return ans;
    }
};

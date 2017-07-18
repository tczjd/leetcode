/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 时间复杂度O(n)空间复杂度O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next; 
            fast = fast->next->next;
        }
        ListNode* last = slow->next, *pre = head;
        while(last->next)
        {
            ListNode* temp = last->next;
            last->next = temp->next;
            temp->next = slow->next;
            slow->next = temp;
        }
        while(slow->next)
        {
            if(pre->val != slow->next->val)
                return false;
            slow = slow->next;
            pre = pre->next;
            
        }
        return true;
    }
};
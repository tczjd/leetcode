/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* l=nullptr;
	ListNode* end=nullptr;
	int go=0;
	int a=0,b=0;
	while(1)
	{
		if(l1==nullptr)
			a=0;
		else
		{
			a=l1->val;
			l1=l1->next;
		}
		if(l2==nullptr)
			b=0;
		else
		{
			b=l2->val;
			l2=l2->next;
		}
		int val=a+b + go;
		if(val>=10)
		{
			go=1;
			val-=10;
		}
		else
			go=0;
		
		ListNode* node=new ListNode(val);
		if(l==NULL)
		{
			l=node;
			end=node;
		}
		else
		{
			end->next=node;
			end=end->next;
		}
		if(l1==nullptr&&l2==nullptr&&go==0)
			break;
	}
	return l;
	}
};
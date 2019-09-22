/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
	if(head == NULL || n < 0){
		return NULL;
	}    

	struct ListNode *p = NULL, *fast = NULL, *tmp = NULL;
	
	p = head;
	fast = head;
	
	while(fast && n){
		fast = fast->next;	
		n --;
	}

	if(n == 0 && fast == NULL)
	{
		//remove header
		head = p->next;
		free(p);
	
		return head;	
	}	
	else if(n != 0 || fast == NULL)
	{
		//invalid n
		return NULL;	
	}
	
	while(fast){
		tmp = p;
		p = p->next;
		fast = fast->next;
	}
	
	tmp->next = tmp->next->next;
	free(p);
	
	return head;
}

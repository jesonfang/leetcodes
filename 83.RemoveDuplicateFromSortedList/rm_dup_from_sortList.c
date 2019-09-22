/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
    	return NULL;
    
	struct ListNode* p = NULL, *q = NULL;
	
	p = head;
	q = p->next;
	
	while(q)	
	{
		struct ListNode *tmp = q->next;
		
		if (!(p->val ^ q->val))
		{
			//same element
			p->next = tmp;
			free(q);	
			q = tmp;
		}
		else		
		{
			p = q;
			q = q->next;
		}
	}
	
	return head;
}

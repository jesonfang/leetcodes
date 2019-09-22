/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) 
{
	struct ListNode *faster = NULL;
	struct ListNode *slower = NULL;
	
	if(head == NULL || head->next == NULL){
		return false;
	}
	
	slower = head;
	faster = head->next;
	while(faster != slower){
		if(faster == NULL || faster->next == NULL)
		{
			return false;
		}
		
		faster = faster->next->next;
		slower = slower->next;
	}
	
	return true;
}

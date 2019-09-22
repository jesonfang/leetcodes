/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
		struct ListNode *pa = headA,*pb = headB;
        
        if(!pa || !pb)
        {
            return NULL;
        }
        
        struct ListNode *pa_last = NULL, *pb_last = NULL;
        
        while(pa != pb)
        {
          
            
            if(pa_last == NULL && pa->next == NULL)/* Last of PA */
            {
                pa_last = pa;
            }

            if(pb_last == NULL && pb->next == NULL)/* Last of PB */
            {
                pb_last = pb;
            }
            
            if(pa_last && pb_last && pa_last != pb_last)
            {
                return NULL;
            }
            
            pa = pa->next;
            pb = pb->next;

            if(pa == NULL){
                pa = headB;
            }
            else if(pb == NULL){
                pb = headA;
            }
        }
        
        return pa;
}
	

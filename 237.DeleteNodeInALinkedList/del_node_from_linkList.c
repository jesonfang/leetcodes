/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *p = node;
    
    if (p == NULL)
    {
        return;
    }
    
    p->val = p->next->val;
    p->next = p->next->next;
    
}


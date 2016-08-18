#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode {
    int val;
	struct ListNode *next;
};

struct ListNode ListHead_1;
struct ListNode ListHead_2;


int ListNode_init(struct ListNode *Head)
{
	int i = 0, j = 0;
	
	for (i = 1; i < 4; i ++)
	{
		struct ListNode *tmp = malloc(sizeof(struct ListNode));
		
		if (tmp)
		{
			tmp->val = i;
			tmp->next = Head->next;
			Head->next = tmp;
		}
		else
		{
			return -1;
		}
	}
	
	return 0;
}

void print_list(struct ListNode *ListHead)
{
	if (!ListHead)
	{
		return;
	}
	struct ListNode *p = ListHead->next;
	
	while (p){
		printf("%d", p->val);
		p = p->next;
		if (p)
		{
			printf("-->");	
		}
	}
	
	printf("\n");
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *p1 = NULL, *p2 = NULL, *m1 = NULL, *m2 = NULL;
    struct ListNode *tmpNode = NULL;
	p1 = l1; 
	p2 = p1->next;
	
	m1 = l2;
	m2 = m1->next;
	
	//return NULL;
	
	//alloc a head node
	struct ListNode *retHeadList = malloc(sizeof(struct ListNode));
	memset(retHeadList, 0, sizeof(struct ListNode));
	
	struct ListNode *lastNode = retHeadList;
	
	while(p2)
	{
		if (p2->next == NULL)//list 1 the last node
		{
			while(m2)
			{
				if (m2->next==NULL)
				{ 
					printf("Last L2 node:%d\n", m2->val);
					break;
				}
				
				m1 = m2;
				m2 = m2->next;	
			}
			
			if (m2)
			{
				tmpNode = malloc(sizeof(struct ListNode));
				tmpNode->val = p2->val + m2->val;
				tmpNode->next = NULL;
				
				//add to new list
				lastNode->next = tmpNode;
				lastNode = tmpNode;	
				
				free(p2);
				free(m2);
				
				//reset to header.
				p1->next= NULL;
				p2 = l1;
				
				m1->next= NULL;
				m2 = l2;	
			}
		}
		p1 = p2;
		p2 = p2->next;		
	}
	
	return retHeadList;
}

int main()
{
	ListNode_init(&ListHead_1);
	ListNode_init(&ListHead_2);
	
	printf("List12:\n");
	print_list(&ListHead_1);
	
	printf("List2:\n");
	print_list(&ListHead_2);
	
	struct ListNode *newList = addTwoNumbers(&ListHead_1, &ListHead_2);
	printf("New List:\n");
	print_list(newList);
	
	return 0;
}

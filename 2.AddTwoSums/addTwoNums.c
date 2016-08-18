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
    struct ListNode *p1 = NULL, *p2 = NULL;
	
	
}

int main()
{
	ListNode_init(&ListHead_1);
	ListNode_init(&ListHead_2);
	
	print_list(&ListHead_1);
	print_list(&ListHead_2);
	
	return 0;
}


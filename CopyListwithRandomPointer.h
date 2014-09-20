#ifndef CopyListwithRandomPointer_H
#define CopyListwithRandomPointer_H

#include "common.h"


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        for(RandomListNode *p = head; p != NULL;)
        {
            RandomListNode *node = new RandomListNode(p->label);
            node->next = p->next;
            p->next = node;
            p = node->next;
        }
        for(RandomListNode *p = head; p != NULL;)
        {
            if(p->random!=NULL)
            {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
		RandomListNode *New = head->next;
		RandomListNode *p = head;
		RandomListNode *q = head->next;
		while(q->next !=NULL)
		{
			p->next = p->next->next;
			q->next = q->next->next;
			p = p->next;
			q = q->next;
		}
		p->next = NULL;
        
        return New;
    }
};

#endif
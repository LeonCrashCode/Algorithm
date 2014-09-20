#ifndef LRUCACHE_H
#define LRUCACHE_H

#include "common.h"
#include <map>
using namespace std;

class LRUCache{
public:
	int Cap;
	int now;
	ListNode *H;
	map<int,int> Map;
	LRUCache(int capacity) {
		Cap = capacity;
		now = 0;
		H = new ListNode(0);
		H->next = NULL;

	}

	int get(int key) {
		ListNode *p = H;
		while(p->next!=NULL)
		{
			if((p->next)->val == key)
			{
				ListNode *tmp = p->next;
				p->next = (p->next)->next;
				tmp->next = H->next;
				H->next = tmp;
				return Map[key];
			}
			p = p->next;
		}
		return -1;
	}

	void set(int key, int value) {
		ListNode *p = H;
		while(p->next!=NULL)
		{
			if((p->next)->val == key)
			{
				ListNode *tmp = p->next;
				p->next = (p->next)->next;
				tmp->next = H->next;
				H->next = tmp;
				Map[key] = value;
				return ;
			}
			p = p->next;
		}
		ListNode *tmp = new ListNode(key);
		tmp->next = H->next;
		H->next = tmp;
		now += 1;
		Map[key] = value;

		if(now>Cap)
		{
			ListNode *p = H;
			ListNode *q = H->next;
			while(q->next!=NULL)
			{
				p = p->next;
				q = q->next;
			}
			p->next = NULL;
			now -= 1;
		}
	}
};
#endif
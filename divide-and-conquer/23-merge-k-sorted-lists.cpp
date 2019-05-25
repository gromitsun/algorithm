/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // merge two lists -- iterative implementation
    inline ListNode* merge2_iterative(ListNode* l1, ListNode* l2)
    {
        // edge cases -- one of the lists is empty
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }
        
        ListNode*& smaller = l1->val < l2->val ? l1 : l2;
        ListNode *head = smaller, *tail = smaller;
        smaller = smaller->next;
        
        // merge two lists
        while (l1 && l2)
        {
            ListNode*& smaller = l1->val < l2->val ? l1 : l2;
            tail = tail->next = smaller;
            smaller = smaller->next;
        }
        
        // handle remaining nodes
        tail->next = l1 ? l1 : l2;
        
        return head;
        
    }
    
    // merge two lists -- recursive implementation
    inline ListNode* merge2_recursive(ListNode* l1, ListNode* l2)
    {
        // edge cases -- one of the lists is empty
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }
        
        if (l1->val < l2->val)
        {
            l1->next = merge2_recursive(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge2_recursive(l1, l2->next);
            return l2;
        }        
    }
    
    // merge lists indexed from l to r using divide-and-conquer
    ListNode* merge(vector<ListNode*>& lists, int l, int r)
    {
        if (r - l == 1)
        {
            return lists[l];
        }
        
        if (r - l == 2)
        {
            return merge2_iterative(lists[l], lists[l+1]);
        }
        
        return merge2_iterative(merge(lists, l, (l+r)/2), merge(lists, (l+r)/2, r));
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // edge case -- lists is empty
        if (lists.empty())
        {
            return NULL;
        }
        
        return merge(lists, 0, lists.size());
    }
};


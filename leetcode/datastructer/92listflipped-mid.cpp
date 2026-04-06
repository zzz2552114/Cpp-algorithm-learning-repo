#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *start = dummy;
        for (int i = 0; i < left - 1; i++)
        {
            start = start->next;
        }
        ListNode *p0 = start;
        int cnt = right - left + 1;
        ListNode *leftnode = p0->next;
        ListNode *curr = leftnode;
        ListNode *prev = nullptr;
        while (cnt--)
        {
            ListNode *nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        p0->next = prev;
        leftnode->next = curr;
        return dummy->next;
    }
};
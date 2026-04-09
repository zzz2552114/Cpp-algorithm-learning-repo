struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *find = head;
        int cnt = 0;
        while(find){
            find = find->next;
            cnt++;
        }
        cnt = (cnt+1)/2-1;
        ListNode* curr = head;
        for(int i = 0;i<cnt;i++){
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = nullptr;
        ListNode* prev = nullptr;
        curr = temp;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        ListNode *l = head,*r = prev;
        while(r){
            ListNode *lnxt = l->next,*rnxt = r->next;
            l->next = r;
            l = lnxt;
            r->next = l;
            r = rnxt;
        }
    }
};
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *nex;
        ListNode dummy(0, head); // 这个是哨兵节点，用处是便于我们后面的输出
        ListNode *left = &dummy; // 这个是前驱节点，用来连接我们后面的每组k个节点
        while (1)
        {
            ListNode *judge = curr;
            for (int i = k; i > 0; i--)
            {
                if (!judge)
                    return dummy.next;
                judge = judge->next;
            }
            for (int t = k; t > 0; t--)
            {
                nex = curr->next; // 这里找到当前节点的下一个节点，储存起来
                curr->next = prev; // 这里是让当前节点指向上一个节点
                prev = curr; // 这里是让当前节点作为“下一轮循环的prev节点“
                curr = nex; // 这里是让下一个节点成为”下一轮循环的curr节点“
            } /* 
            退出循环后: 
            0.现在curr在下一次循环的队首，prev在本次循环的原队尾(现队首)
            1.原来开头的节点现在在这k个节点的链尾，指向一个错误的节点，后续需要调整。 
            2.原来末尾的节点现在在这k个节点的链首，没有人指向它，后续需要调整。
            */
            // 这个时候，left前驱节点就派上了用场。从第一轮循环开始看，现在left节点=哨兵节点
            ListNode *start = left->next; // left节点指向原队首，现队尾，需要存储起来，后面作为新left节点，用来连接下次循环的队首
            left->next->next = curr; // 让原队首(现队尾)指向下一轮的队首(保证如果后面不足k个能正确输出)
            left->next = prev; // 让left(这个时候就不能看第一轮了，要看后面的几轮，这个时候left节点已经变成上一次循环的队尾了)----也就是上一轮循环的队尾，指向现在的队首，连接成链表
            left = start; // 让left真的如上所说变成这次循环的队尾。

            // !!!注意前面为什么能返回dummy.next。是因为我们在ListNode* left = &dummy;之后，进行left->next = xxx;的时候，是对里面的地址进行操作的，也就是我们的确更改了dummy。然后后面left = start;又让left这个指针去接别的地址去了，但是dummy已经被改了，恰好dummy指向的是第一次循环的原队尾(现整体队首)。所以可以直接返回dummy.next
        }
    }
};
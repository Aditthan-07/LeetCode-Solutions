struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        k %= len;
        if (k == 0) return head;
        tail->next = head;
        for (int i = 0; i < len - k; ++i) {
            tail = tail->next;
        }
        ListNode* newHead = tail->next;
        tail->next = nullptr;
        return newHead;
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        if (count == k) {
            ListNode* reversedHead = reverseKGroup(curr, k);
            while (count-- > 0) {
                ListNode* temp = head->next;
                head->next = reversedHead;
                reversedHead = head;
                head = temp;
            }
            head = reversedHead;
        }
        return head;
    }
};

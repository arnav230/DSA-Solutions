class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;

        for(int i = 1; i < n; i++) {
            fast = fast->next;
        }
        if(fast->next == nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = slow->next;
        delete slow;

        return head;
    }
};

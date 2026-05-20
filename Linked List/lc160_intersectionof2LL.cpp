class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        int count1=0;
        while(temp1!=nullptr) {
            count1++;
            temp1=temp1->next;
        }
        ListNode* temp2=headB;
        int count2=0;
        while(temp2!=nullptr) {
            count2++;
            temp2=temp2->next;
        }
        ListNode* greaterhead;
        ListNode* smallerhead;
        int diff=0;
        if(count2>count1) {
            smallerhead=headA;
            greaterhead=headB;
            diff=count2-count1;
        }
        else {
            smallerhead=headB;
            greaterhead=headA;
            diff=count1-count2;
        }
        while(diff!=0) {
            diff--;
            greaterhead=greaterhead->next;
        }
        while(smallerhead!=nullptr && greaterhead!=nullptr) {
            if(smallerhead==greaterhead) return smallerhead;
            smallerhead=smallerhead->next;
            greaterhead=greaterhead->next;
        }
        return nullptr;
    }
};

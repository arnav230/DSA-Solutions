class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head=nullptr;
        ListNode* temp=head;
        while(l1!=nullptr && l2!=nullptr) {
            int sum=l1->val+l2->val+carry;
            if(sum<=9) {
                if(head==nullptr) {
                    head=new ListNode(sum);
                    temp=head;
                }
                else {
                    ListNode* t=new ListNode(sum);
                    temp->next=t;
                    temp=t;
                }
                carry=0;
            }
            else {
                if(head==nullptr) {
                    head=new ListNode(sum%10);
                    temp=head;
                }
                else {
                    ListNode* t=new ListNode(sum%10);
                    temp->next=t;
                    temp=t;
                }
                sum=sum/10;
                carry=sum;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=nullptr) {
            int sum=carry+l1->val;
ListNode* t = new ListNode(sum <= 9 ? sum : sum % 10);

if (head == nullptr) {
    head = t;
    temp = head;
} else {
    temp->next = t;
    temp = t;
}

carry = sum / 10;
            l1=l1->next;
        }
        while(l2!=nullptr) {
            int sum=carry+l2->val;
ListNode* t = new ListNode(sum <= 9 ? sum : sum % 10);

if (head == nullptr) {
    head = t;
    temp = head;
} else {
    temp->next = t;
    temp = t;
}

carry = sum / 10;
            l2=l2->next;
        }
        if(carry!=0) {
            temp->next=new ListNode(carry);
        }
        return head;
    }
};

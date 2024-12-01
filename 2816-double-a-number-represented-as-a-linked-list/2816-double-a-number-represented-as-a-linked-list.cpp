class Solution {
    ListNode* reverse(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* nh=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return nh;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);
        ListNode* temp =head;
        ListNode* p=head;
        int c=0;
        while(temp!=NULL){
            p=temp;
            c=c+temp->val*2;
            temp->val=c%10;
            c=c/10;
            temp=temp->next;
        }

        if(c!=0){
            temp=new ListNode(c,NULL);
            p->next=temp;
        }

        return reverse(head);
        
    }
};
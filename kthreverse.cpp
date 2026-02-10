ListNode* reverse(ListNode* start, ListNode* end) {
    ListNode* prev = end->next;
    ListNode* curr = start;

    while (prev != end) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return end; 
}
ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* dummy=new ListNode(0);
      dummy->next=head;
      ListNode* grpprv=dummy;
      if(!head || k==1) return head;

      while(true){
        ListNode* kth=grpprv;

        for(int i=0;i<k && kth;i++){
            kth=kth->next;
        }
        if(!kth) break;
        ListNode*st=grpprv->next;
        ListNode*end=kth;
        ListNode*endnext=end->next;
        ListNode*newnode=reverse(st,end);

        grpprv->next=newnode;
       // st->next=endnext;
        grpprv=st;

      } 
   return dummy->next;



}
//it is pure of logic question in which we have to make a helper function which will reverse all the things for us and also we need to add the dummy node to remove the headache of head also grpprv maintain previous group.
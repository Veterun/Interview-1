ListNode * reverseList(ListNode * head)
{
	if (!head || !(head -> next)) return head;
	ListNode * node = reverseList(head -> next);
	head -> next -> next = head;
	head -> next = NULL;
	return node;
}
The basic idea of this recursive solution is to reverse all the following nodes after head. 
Then we need to set head to be the final node in the reversed list. 
We simply set its next node in the original list (head -> next) to point to it and sets its next to be NULL.

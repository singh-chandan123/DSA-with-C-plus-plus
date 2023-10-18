/*
 Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Input 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 

*/
//main code

/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node* merge(Node*left,Node*right){
	if(left==NULL){
		return right;
	}
	if(right==NULL){
		return left;
	}
Node*ans=new Node(-1);
Node*temp=ans;
while(left!=NULL&&right!=NULL){

if(left->data<right->data){
temp->next=left;
temp=left;
left=left->next;
}
else{
temp->next=right;
temp=right;
right=right->next;
}

}
//here left  is not null and right is null
while(left!=NULL){
	temp->next=left;
temp=left;
left=left->next;
}
//lets right list is  not null and left is null
while(right!=NULL){
	temp->next=right;
temp=right;
right=right->next;
}
ans=ans->next;
return ans;
}

//function of finding mid
Node* findmid(Node*head){
Node*slow=head;
Node*fast=head->next;
while(fast!=NULL&&fast->next!=NULL){
slow=slow->next;
fast=fast->next->next;
}
return slow;
}


Node *mergeSort(Node *head)
{
	//Write your code here
if(head==NULL){
	return head;
}
if(head->next==NULL){
	return head;
}
Node*mid=findmid(head);
Node*left=head;
Node*right=mid->next;
mid->next=NULL;
left=mergeSort(left);
right=mergeSort(right);
Node* result=merge(left,right);
return result;

}

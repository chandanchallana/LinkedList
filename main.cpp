/* Program Description:
  Write a Program to get Nth node in a linked list.
*/
#include <iostream>
#include <stdlib.h>
#include<assert.h>

using namespace std;

/* Link List Node */
struct node {
int data;
struct node* next;
};

/* Given a reference(pointer to pointer) to the head
of a list and an int, push a new node on front of the list.
*/

void push(struct node** head_ref,int new_data)
{

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    //put in the data
    new_node->data = new_data;
    //link the old list off the new node
    new_node->next = (*head_ref);
    //move the head to point to the new node
    (*head_ref) = new_node;

}
/*Takes head pointer of the linked list and index as arguments and return
 data at index*/

 int getNth(struct node* head,int index)
 {
     struct node* current = head;//linked list iterator
     int count  = 0;//index of the node we would be looking at
     while(current != NULL)
     {

         if(count == index)
            return(current->data);
         count++;
         current = current->next;
     }
     /* if we get to this line the caller was asking for a non existent
        so we assert fail*/
        assert(0);
 }


int main()
{
    cout << "Hello world!" << endl;
    struct node* head = NULL;
    /*Use push to construct below list*/
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    int n = getNth(head,3);
    cout<<"The nth element is "<<n;
    return 0;
}

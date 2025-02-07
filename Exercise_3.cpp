#include <bits/stdc++.h> 
using namespace std; 
  
// A linked list node (changes)

class Node  
{  
    public: 
    int data;  
    Node *next;  
};  
  
/* Given a reference (pointer to pointer) 
to the head of a list and an int, inserts 
a new node on the front of the list. */

// Time Complexity of push : O(1)
// Space Complexity of push : O(1)

void push(Node** head_ref, int new_data)  
{  
    /* 1. allocate node */ 
    Node* temp = new Node();

    /* 2. put in the data */  
    temp->data = new_data;
    temp->next = NULL;

    /* 3. Make next of new node as head */
    temp->next = (*head_ref);

    /* 4. move the head to point to the new node */
    *head_ref = temp;
    return;
} 


/* Given a node prev_node, insert a new node after the given  
prev_node */

// Time Complexity of insertAfter : O(1)
// Space Complexity of insertAfter : O(1)

void insertAfter(Node* prev_node, int new_data)  
{  
    /*1. check if the given prev_node is NULL */ 
    if (prev_node == NULL)  
    {  
        cout << "Invalid\n";  
        return;  
    } 
  
    /* 2. allocate new node */
    Node *temp = new Node(); 
  
    /* 3. put in the data */
    temp->data = new_data;
    temp->next = NULL;
  
    /* 4. Make next of new node as next of prev_node */
    temp->next = prev_node->next;
  
    /* 5. move the next of prev_node as new_node */
    prev_node->next = temp; 
    return;
}  
  
/* Given a reference (pointer to pointer) to the head  
of a list and an int, appends a new node at the end */

// Time Complexity of append : O(n)
// Space Complexity of append : O(1)

void append(Node** head_ref, int new_data)  
{  
    /* 1. allocate node */
    Node *temp = new Node(); 
  
    /* 2. put in the data */
    temp->data = new_data; 
  
    /* 3. This new node is going to be  
    the last node, so make next of  
    it as NULL*/
    temp->next = NULL;  
  
    /* 4. If the Linked List is empty, 
    then make the new node as head */
    if((*head_ref) == NULL)
    {
        (*head_ref) = temp;
        return;
    }
  
    /* 5. Else traverse till the last node */
    Node *temp2 = (*head_ref);
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
  
    /* 6. Change the next of last node */
    temp2->next = temp;
    return;
}  
  
// This function prints contents of 
// linked list starting from head

// Time Complexity of printList : O(n)
// Space Complexity of printList : O(1)

void printList(Node *node)  
{  
    //Your code here
    if (node == NULL) {
        cout << "Linked List is empty.\n";
        return;
    }
    Node *temp = node;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}  
  
/* Driver code*/
int main()  
{  
    Node* head = NULL;   
    append(&head, 6);  
    push(&head, 7);  
    push(&head, 1);    
    append(&head, 4);    
    insertAfter(head->next, 8);  
    cout<<"Created Linked list is: ";  
    printList(head);  
    return 0;  
}  
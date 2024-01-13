#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int info;
    struct node *link;
};
struct node *createList();
struct node *add_beg(struct node *start, int data);
struct node *add_end(struct node *start, int data);
struct node *beforeAnode(struct node *start,int data, int item);
struct node *afterAnode(struct node *start,int data, int item);
struct node *atAposition(struct node *start,int data, int position);
void display(struct node *start);
struct node *del_beg(struct node *start, int data);
struct node *del_end(struct node *start, int data);
struct node *DelbeforeAnode(struct node *start,int data, int item);
struct node *DelafterAnode(struct node *start,int data, int item);
struct node *DelatAposition(struct node *start,int data, int position);
//function to create a linked list 
struct node *createList() 
{
    struct node *start = NULL;
    struct node *temp, *newNode;
    int size, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid size.\n");
        return NULL;
    }
    printf("Enter the elements: \n");
    for (i = 0; i < size; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) 
		{
            printf("Memory allocation failed.\n");
            return NULL;
        }
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        newNode->info = data;
        newNode->link = NULL;
        if (start == NULL) {
            start = newNode;
        } else {
            temp = start;
            while (temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = newNode;
        }
    }
    return start;
}
//function to display the created linked list 
void display(struct node *start) 
{
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = start;
    printf("Elements in the linked list are: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}
//function to add a node at the begining of the list
struct node *add_beg(struct node *start, int data) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return start;
    }
    newNode->info = data;
    newNode->link = start;
    start = newNode;
    printf("Node inserted at the beginning successfully.\n");
    return start;
}
//function to add a node at the end of the list
struct node *add_end(struct node *start, int data) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return start;
    }
    newNode->info = data;
    newNode->link = NULL;
    if (start == NULL) {
        start = newNode; 
    } else {
        struct node *temp = start;
        while (temp->link != NULL) {
            temp = temp->link; 
        }
        temp->link = newNode; 
    }
    printf("Node inserted at the end successfully.\n");
    return start; 
}
//function to add at a given position 
struct node *atAposition(struct node *start, int data, int position) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return start;
    }
    newNode->info = data;
    newNode->link = NULL;
    if (position == 1) {
        newNode->link = start;
        start = newNode;
    } 
	else 
	{
        struct node *temp = start;
        int count = 1;
        while (count < position - 1 && temp != NULL) {
            temp = temp->link;
            count++;
        }
        if (temp == NULL) {
            printf("Position is out of range.\n");
            free(newNode);
            return start;
        }
        newNode->link = temp->link;
        temp->link = newNode;
    }
    printf("Node inserted at position %d successfully.\n", position);
    return start;
}
//function to add a node before a given node
struct node *beforeAnode(struct node *start, int data, int key) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return start;
    }
    newNode->info = data;
    newNode->link = NULL;
    if (start == NULL) {
        printf("List is empty.\n");
        free(newNode);
        return start;
    }
    if (start->info == key) {
        newNode->link = start;
        start = newNode;
        printf("Node inserted before the first node successfully.\n");
        return start;
    }
    struct node *temp = start;
    while (temp->link != NULL && temp->link->info != key) {
        temp = temp->link;
    }
    if (temp->link == NULL) {
        printf("Node with key %d not found.\n", key);
        free(newNode);
        return start;
    }
    newNode->link = temp->link;
    temp->link = newNode;
    printf("Node inserted before %d successfully.\n", key);
    return start;
}
//function to add node after a given node
struct node *afterAnode(struct node *start, int data, int key) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return start;
    }
    newNode->info = data;
    newNode->link = NULL;
    if (start == NULL) {
        printf("List is empty.\n");
        free(newNode);
        return start;
    }
    struct node *temp = start;
    while (temp != NULL && temp->info != key) 
	{
        temp = temp->link;
    }
    if (temp == NULL) {
        printf("Node with key %d not found.\n", key);
        free(newNode);
        return start;
    }
    newNode->link = temp->link;
    temp->link = newNode;
    printf("Node inserted after %d successfully.\n", key);
    return start;
}




int main() 
{
    int choice, choice1, choice2, data,item,position;
    struct node *list = NULL;
    int exitFlag = 0;

    while(!exitFlag) 
	{
        printf("MAIN MENU\n");
        printf("1. Create a linked list \n2. Insert \n3. Display the Linked List\n4. Delete \n5. Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                list = createList();
                display(list);
                break;
            case 2:
                printf("INSERT\n");
                printf("1. At the beginning\n2. At the end\n3. In the middle of the list\n");
                printf("Enter your choice\n");
                scanf("%d", &choice1);
                switch (choice1) 
				{
                    case 1:
                        printf("Enter data to be inserted at the beginning : ");
                        scanf("%d", &data);
                        list = add_beg(list, data);
                        display(list);
                        break;
                    case 2 :
                    	printf("Enter data to be inserted at the end : ");
                    	scanf("%d",&data);
                    	list = add_end(list,data);
                    	display(list);
                    	break ;
                    case 3 :
                    	printf("INSERT IN THE MIDDLE OF THE LIST\n");
                    	printf("1. Before a node \n 2. After a node \n 3. At a given positon \n");
						printf("Enter your choice\n");
						scanf("%d",&choice2);
						switch(choice2)
						{
							case 1 :
								printf("Enter the data to be inserted : ");
								scanf("%d",&data);
								printf("Enter the element before which to insert : ");
								scanf("%d",&item);
								list = beforeAnode(list,data,item);
								display(list);
								break;
							case 2 :
								printf("Enter the data to be inserted : ");
								scanf("%d",&data);
								printf("Enter the element after which to insert : ");
								scanf("%d",&item);
								list = afterAnode(list,data,item);
								display(list);
								break;
							case 3 : 
								printf("Enter the data to be inserted : ");
								scanf("%d",&data);
								printf("Enter the elements between which to insert : ");
								scanf("%d",&position);
								list = atAposition(list,data,position);
								display(list);
								break;
							default :
								printf("Invalid option entered \n");
							}	
                    default:
                        printf("Invalid option entered \n");
                }
                break;
            case 3:
                display(list);
                break;
            case 4:
                printf("DELETE A NODE\n");
                printf("1. Delete at the beginning\n2. Delete at the end\n3. Delete in the middle of the list\n");
                printf("Enter your choice\n");
                scanf("%d", &choice1);
                switch (choice1) 
				{
                    case 1:
                    	printf("Enter data to be deleted at the beginning : ");
                        scanf("%d", &data);
                        list = del_beg(list, data);
                        display(list);
                        break;
                    case 2:
                    	printf("Enter data to be deleted at the end : ");
                        scanf("%d", &data);
                        list = del_end(list, data);
                        display(list);
                        break;
                    case 3:
                    	printf("Delete in the middle of the list \n");
                    	printf("1. Delete before a node\n2. Delete after a node\n3. Delete at a position\n");
                    	printf("Enter your choice : ");
                    	scanf("%d",&choice);
                    	switch(choice)
                    	{
	                    	case 1:
		                        printf("Enter the item before which the node has to be deleted: ");
		                        scanf("%d", &item);
		                        list = DelbeforeAnode(list, data, item);
		                        break;
	                    	case 2:
		                        printf("Enter the item after which the node has to be deleted: ");
		                        scanf("%d", &item);
		                        list = DelafterAnode(list, data, item);
		                        break;
	                    	case 3:
		                        printf("Enter the position of the node to be deleted: ");
		                        scanf("%d", &position);
		                        list = DelatAposition(list, data, position);
		                        break;
		                    default :
		                    	printf("Invalid choice \n");
		            	}
                    default:
                        printf("Invalid choice for deletion.\n");
                        break;
                }
                break;
            case 5:
                exitFlag = 1; 
                break;
            default:
                printf("Invalid option entered\n");
        }
    }
    printf("Exiting the program...\nThank you!\n");
    return 0;
}

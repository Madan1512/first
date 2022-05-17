#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head,*current;
void insert_at_end()
{
    struct node*newnode;
    int value;
    printf("Enter value for the node:" );
    scanf("%d",&value);
    newnode=(struct node*)malloc(sizeof(struct node*));
    if(head==NULL)
    {
        newnode->data=value;
        newnode->link=NULL;
        head=newnode;
        current=newnode;
    }
    else
    {
     newnode->data=value;
     newnode->link=NULL;
     current->link=newnode;
    //  head=newnode;
     current=newnode;
    }
}
void insert_beg()
{
    struct node *newnode;
    int value;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("Enter the node value : " );
    scanf("%d",&value);

    if(head==NULL)
    {
        newnode->data=value;
        newnode->link=NULL;
        head=newnode;
        current=newnode;
    }
    else{
        newnode->data=value;
        newnode->link=head;
        current=newnode;
        head=newnode;
    }
}

void insert_middle(int nodeIndex)
{
  current=head;
  int pos=0;

  while(nodeIndex-1>pos)
  {
      current=current->link;
      pos++;
  }

  struct node *temp=current->link;
  struct node *newnode;

  int value=0;
  newnode=(struct node*)malloc(sizeof(struct node*));
  printf("Enter the node value : " );
  scanf("%d",&value);
  newnode->data=value;

  current->link=newnode;
  newnode->link=temp;
}

void display()
{
    current=head;
    while(current!=NULL)
    {
        printf("Node  value: %d\n ",current->data);
        current=current->link;
    }
}
int main()
{
    int n;
    printf("How many nodes want to create?: ");
    scanf("%d",&n);

    do
    {
        insert_at_end();
        //printf("To insert more values press 0\n");
        n--;
    }while(n!=0);

    //printf("Inserting node at begining" );
    //insert_beg();

    printf("OUTPUT\n");
    display();

    printf("Where do you want to insert the node : " );
    int nodeIndex=0;
    scanf("%d", &nodeIndex);
    // insert_middle(nodeIndex);

    display();
}



typedef int LinkedType;
typedef struct node
{
    LinkedType element;
    struct node * next;
    struct node * prev;
}Node;
typedef struct linkedlist
{
    Node* head;
    int size;
}Linkedlist;
void CreateList(Linkedlist * lq);
int IsFull(Linkedlist * lq);
int IsEmpty(Linkedlist * lq);
void Insert(Linkedlist * lq ,LinkedType e , int pos);
void Retrieve(Linkedlist * lq ,LinkedType *e , int pos );
int Getindex(Linkedlist * lq  , int pos );
int ListSize(Linkedlist * lq);
void TraverseList(Linkedlist * lq , void (*pf)(LinkedType ));
void ClearList(Linkedlist * lq);
void ReverseTraverseList (Linkedlist * lq , void (*pf)(LinkedType));

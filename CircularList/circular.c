

#include <stdio.h>
#include <stdlib.h>
#include "cicular.h"
void CreateList(Linkedlist * lq)
{
    lq->head=NULL;
    lq->size=0;
}
int IsFull(Linkedlist * lq)
{
    return 0;
}
int IsEmpty(Linkedlist * lq)
{
    return lq->size==0;
}
void Insert(Linkedlist * lq ,LinkedType e , int pos)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->element=e;
    temp->next=NULL;
    temp->prev=NULL;
    if(pos==0)//first element
    {
        if(!lq->head)//& only element
        {
            lq->head=temp;
            lq->head->next=temp;
            lq->head->prev=temp;
        }
        else//not only
        {
            temp->next=lq->head;
            temp->prev=lq->head->prev;
            lq->head->prev->next=temp;
            lq->head->prev=temp;
            lq->head=temp;
        }
    }
    else//not first
    {
        Node *q=lq->head ;
        for(int i =0; i<pos-1 ; i++ , q=q->next);
        temp->prev=q;
        q->next=temp;
        if(pos==lq->size)//last position
            {//make 1's node pointer to it and vise vesre
                temp->next=lq->head;
                lq->head->prev=temp;
            }
        else//between --normal case--
            {
                q->next->next->prev=temp;
                temp->next=q->next->next;
            }
    }
    lq->size++;
}
void Retrieve(Linkedlist * lq ,LinkedType *e , int pos )
{
    Node *q, *temp;

    if(pos==0)// at first
    {
        *e=lq->head->element;
        q=lq->head;
        if(lq->size==1)//only one element
        {
            q=lq->head;
            lq->head=NULL;
        }
        else// not only must make last node pointer to the 2's node cuz first was deleted
        {
            lq->head->next->prev=lq->head->prev;
            lq->head->prev->next=lq->head->next;
            lq->head=lq->head->next;
        }
      free(q);
    }
    else
    {
        q=lq->head;
        for(int i =0 ; i<pos-1 ; i++ , q=q->next);
            *e=q->next->element;
        temp=q->next;
        if(pos==lq->size)//make 1's node pointer to it and vise vesre
           {
               q->next=lq->head;
               lq->head->prev=q;
           }
        else
           {
                temp->next->prev=q;
                q->next=q->next->next;
           }
        free(temp);
    }
    lq->size--;
}

int Getindex(Linkedlist * lq  , int pos )
{
    if(pos>lq->size)
        return -1;
    Node *q, *temp;
    if(pos==0)
    {
        return lq->head->element;
    }
    else
    {
        q=lq->head ;
        for(int i =0 ; i<pos-1 ; i++ , q=q->next);
        return q->next->element;
    }
}
int ListSize(Linkedlist * lq)
{
    return lq->size;
}
void TraverseList(Linkedlist * lq , void (*pf)(LinkedType))
{
    Node *q=lq->head;
    int i=lq->size;
    while(i--)
    {
        (*pf)(q->element);
        q=q->next;
    }
}
void ReverseTraverseList(Linkedlist * lq , void (*pf)(LinkedType ))
{
    Node *q = lq->head->prev;//nice step to access from last
    int i=lq->size;
    while(i--)
    {
        (*pf)(q->element);
        q=q->prev;
    }
}
void ClearList(Linkedlist * lq)
{
    Node *q=lq->head ;
    int i=lq->size;
    while(i--)
    {
        lq->head=q->next;
        free(q);
        q=lq->head;
    }
    lq->size=0;
}

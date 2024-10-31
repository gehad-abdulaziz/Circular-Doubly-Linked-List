/*

وما توفيقي إلا بالله العلي العظيم

@Gehad Abdulaziz
*/
#include <stdio.h>
#include "cicular.h"
void print(LinkedType e)
{
    printf("%d " , e);
}
int main()
{
    Linkedlist lq;
    CreateList(&lq);
    int q=0;
    for(int i =0 ;i<10; i++)
    Insert(&lq , i, q++);
    int y;
    TraverseList(&lq , &print);
    printf("\n ---DELETE FIRST ELEMENT---\n");
    Retrieve(&lq , &y , 0);
    printf("\n---%d---\n" , y);
    printf("\nprint queue with function i made in implementation level : \n");
    TraverseList(&lq , &print);
    printf("\nprint revesre queue with function i made in implementation level : \n");
    ReverseTraverseList(&lq, &print);
    printf("\n---------------------------------------\n");
    TraverseList(&lq , &print);
    printf("\n ---DELETE LAST ELEMENT---\n");
    Retrieve(&lq , &y , ListSize(&lq)-1);
    printf("\n---%d---\n" , y);
    printf("\nprint queue with function i made in implementation level : \n");
    TraverseList(&lq , &print);
    printf("\nprint revesre queue with function i made in implementation level : \n");
    ReverseTraverseList(&lq, &print);
    printf("\n--------------------\n");
    printf("\nuse getindex function of index 0 : %d " , Getindex(&lq ,0));
    printf("\nuse getindex function of index 3 : %d " , Getindex(&lq ,3));
    printf("\nuse getindex function of index 6 : %d " , Getindex(&lq ,6));
    printf("\nuse getindex function of index in the end : %d " , Getindex(&lq ,ListSize(&lq)-1));

}

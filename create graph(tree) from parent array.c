#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
struct graph{
    struct node* list[200001];
    int mark[200001];
    long long int ll[200001];
    long long int ul[200001];
};
struct node{
    int key;
    struct node* next;
};
struct node* create(int k)
{
    struct node* ptr=(struct node*)malloc(1*sizeof(struct node));
    ptr->key=k;
    ptr->next=NULL;
    return ptr;
}
void insert_dir(struct graph* g,int x,int y) // x to y
{
    struct node* ptry=create(y);
    ptry->next=g->list[x];
    g->list[x]=ptry;
    
}
void read_and_insert_dir(struct graph* g,int n)
{
    int j=0;
    while(j<n)
    {
        int x,y;
        scanf("%d %d ",&x,&y);
        insert_dir(g,x,y);
        j++;
        
    }
}
void initialize_graph(struct graph* g)
{
    int j=0;
    while(j<200001)
    {
        g->list[j]=NULL;
        g->mark[j]=0;
        j++;
    }
}
void print_graph(struct graph* g,int n)
{
    int j=1;
    while(j<n+1)
    {
        printf("%d  ",j);
        struct node* cur=g->list[j];
        while(cur!=NULL)
        {
            printf("%d ",cur->key);
            cur=cur->next;
        }
        printf("\n");
        j++;
    }
}
int main()
{
    int q;
    scanf("%d ",&q);
    while(q--)
    {
       int n;
       struct graph g;
       initialize_graph(&g);
       scanf("%d ",&n);
       int j=2;
       while(j<=n)
       {
           int x;
           scanf("%d ",&x);
           insert_dir(&g,x,j);
           j++;
       }
       print_graph(&g,n);
    }
}

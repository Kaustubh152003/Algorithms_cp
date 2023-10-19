void print_array(int* arr,int n)
{
    int j=0;
    while(j<n)
    {
        printf("%d ",arr[j]+1);
        j++;
    }
}
void initialize_array(int* arr,int n,int k)
{
    int j=0;
    while(j<n)
    {
        arr[j]=k;
        j++;
    }
}
void diagonal_of_xy_in_row_p(int x,int y,int r,int* ans1,int* ans2)
{
    int diff=r-x;
    *ans1=y+diff;
    *ans2=y-diff;
}
void copy_arr(int* a,int* b,int n)
{
    int j=0;
    while(j<n)
    {
        a[j]=b[j];
        j++;
    }
}
void func(int* arr,int p,int n)
{
    if(p==n)
    {
        print_array(arr,n);
        printf("\n");
    }
    else
    {
        int place[n];
        initialize_array(place,n,1);
        int j=0;
        while(j<p)
        {
            place[arr[j]]=0;
            int x1,x2;
            diagonal_of_xy_in_row_p(j,arr[j],p,&x1,&x2);
            if(x1>=0 && x1<n)
            place[x1]=0;
            if(x2>=0 && x2<n)
            place[x2]=0;
            j++;
        }
        j=0;
        while(j<n)
        {
            if(place[j]==1)
            {
                int* newarr=(int*)malloc(sizeof(int)*(p+1));
                copy_arr(newarr,arr,p);
                newarr[p]=j;
                func(newarr,p+1,n);
            }
            j++;
        }
        
    }
}

int compare(long long x1,long long y1,long long x2,long long y2) //return 1 if a<b , 0 if equal, -1 for a>b for ur comparating operation
{
    if(x1*y2<y1*x2)
    return 1;
    else
    {
        if(x1*y2==y1*x2)
        return 0;
        else
        return -1;
    }
}
void merge(int arr[],int brr[],int l, int m, int r)
{
    int p=l;
    int q=m+1;
    int res[r-l+1];
    int resb[r-l+1];
    int j=0;
    while(p<=m && q<=r)
    {
        if(compare(arr[p],brr[p],arr[q],brr[q])==1)
        {
            res[j]=arr[p];
            resb[j]=brr[p];
            p++;
            j++;
        }
        else
        {
            res[j]=arr[q];
            resb[j]=brr[q];
            q++;
            j++;
        }
    }
    while(p<=m)
    {
        res[j]=arr[p];
        resb[j]=brr[p];
        p++;
        j++;
    }
    while(q<=r)
    {
        res[j]=arr[q];
        resb[j]=brr[q];
        q++;
        j++;
    }
    int k=l;
    j=0;
    while(k<=r)
    {
        arr[k]=res[j];
        brr[k]=resb[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int brr[],int l, int r) //merge sort for fractions in 2 diff arrays
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(arr,brr,l,m);
        mergeSort(arr,brr,m+1,r);
        merge(arr,brr,l,m,r);
    }
    
}
int bs(int* arr,int* brr,int l,int r,int num,int den)
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(compare(arr[m],brr[m],num,den)==0)
        return m;
        else
        {
            if(compare(arr[m],brr[m],num,den)==1)
            return bs(arr,brr,m+1,r,num,den);
            else
            return bs(arr,brr,l,m-1,num,den);
        }
    }
    else
    return -1;
}
int bsl(int* arr,int* brr,int l,int r,int num,int den)
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(compare(arr[m],brr[m],num,den)==0)
        {
            int p=bsl(arr,brr,l,m-1,num,den);
            if(p==-1)
            return m;
            else
            return p;
        }
        else
        {
            if(compare(arr[m],brr[m],num,den)==1)
            return bsl(arr,brr,m+1,r,num,den);
            else
            return bsl(arr,brr,l,m-1,num,den);
        }
    }
    else
    return -1;
}
int bsr(int* arr,int* brr,int l,int r,int num,int den)
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(compare(arr[m],brr[m],num,den)==0)
        {
            int p=bsr(arr,brr,m+1,r,num,den);
            if(p==-1)
            return m;
            else
            return p;
        }
        else
        {
            if(compare(arr[m],brr[m],num,den)==1)
            return bsr(arr,brr,m+1,r,num,den);
            else
            return bsr(arr,brr,l,m-1,num,den);
        }
    }
    else
    return -1;
}
void print_array(int* arr,int n)
{
    int j=0;
    while(j<n)
    {
        printf("%d ",arr[j]);
        j++;
    }
}
int countFractions(int n, int num[], int den[])
{
    int count=0;
    mergeSort(num,den,0,n-1);
    // print_array(num,n);
    // printf("\n");
    // print_array(den,n);
    // printf("\n");
    int j=0;
    while(j<n)
    {
        int x=den[j]-num[j];
        int y=den[j];
        if(bs(num,den,0,n-1,x,y)!=-1)
        {
            int l=bsl(num,den,0,n-1,x,y);
            int r=bsr(num,den,0,n-1,x,y);
            count=count+(r-l+1);
            if(l<=j && j<=r)
            count--;
            // printf("for j: %d, count is %d from %d to %d\n",j,r-l+1,l,r);
        }
        j++;
    }
    return count/2;;
    
}

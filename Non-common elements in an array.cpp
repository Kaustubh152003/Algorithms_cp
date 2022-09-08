void choose(int* arr,int* brr,int n,int* fia,int* fib,int* r) //arr and brr are the main arrays, fia and bia contain the non common elements after the function excecutes
{
    
    sort(arr,arr+n);
    sort(brr,brr+n);
    int x,y;
    x=y=0;
    int p,q;
    p=q=0;
    while(p<n && q<n)
    {
        if(arr[p]==brr[q])
        {
            p++;
            q++;
        }
        else
        {
            
            if(arr[p]<brr[q])
            {
                fia[x]=arr[p];
                x++;
                p++;
            }
            else
            {
                fib[y]=brr[q];
                y++;
                q++;
            }
        }
    }
    while(p<n)
    {
        fia[x]=arr[p];
        x++;
        p++;
    }
    while(q<n)
    {
        fib[y]=brr[q];
        y++;
        q++;
    }
    if(x!=y)
    printf("error\n");
    *r=x;
}

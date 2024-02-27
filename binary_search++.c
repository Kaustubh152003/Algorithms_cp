int* binary_search(int* arr, int n,int k) // returns the adress where the element is found. If not found, returns NULL
{
    if(n==0)
    return 0;
    else
    {
        if(arr[n/2]==k)
        return arr+n/2;
        else
        {
            if(k<arr[n/2])
            return binary_search(arr,n/2,k);
            else
            return binary_search(arr+n/2+1,n-n/2-1,k);
        }
    }
}
int bs(int* arr,int l,int r,int k) 
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(k==arr[m])
        return m;
        else
        {
            if(k<arr[m])
            return bs(arr,l,m-1,k);
            else
            return bs(arr,m+1,r,k);
        }
    }
    else
    return -1;
}
int bsl(int* arr,int l,int r,int k) //binary search which returns the left most occurence of element k
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(k==arr[m])
        {
            int p=bsl(arr,l,m-1,k);
            if(p==-1)
            return m;
            else
            return p;
        }
        else
        {
            if(k<arr[m])
            return bsl(arr,l,m-1,k);
            else
            return bsl(arr,m+1,r,k);
        }
    }
    else
    return -1;
}
int bsr(int* arr,int l,int r,int k) //binary search which returns the right most occurence of element k
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(k==arr[m])
        {
            int p=bsr(arr,m+1,r,k);
            if(p==-1)
            return m;
            else
            return p;
        }
        else
        {
            if(k<arr[m])
            return bsr(arr,l,m-1,k);
            else
            return bsr(arr,m+1,r,k);
        }
    }
    else
    return -1;
}
int bsn(int* arr,int l,int r,int k)
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(arr[m]==k)
        return m;
        else
        {
            if(k<arr[m])
            return bsn(arr,l,m-1,k);
            else
            return bsn(arr,m+1,r,k);
          }
    }
    else
    return r;
}

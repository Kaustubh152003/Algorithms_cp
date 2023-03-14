int* bs(int* arr,int n,int k) //returns position of element if found, else return position of element where it needs to be inserted
{
    if(n==0)
        return arr;
    else
    {
        if(arr[n/2]==k)
            return arr+n/2;
        else
        {
            if(k<arr[n/2])
            return bs(arr,n/2,k);
            else
            return bs(arr+n/2+1,n-n/2-1,k);
        }
    }
}

int bsl(int* arr,int l,int r,int k) //returns the index of the element if present , else returns the element just lesse than it
{
    if(l<=r)
    {
        int m=(l+r)/2;
        if(k==arr[m])
        return m;
        else
        {
            if(k<arr[m])
            return bsl(arr,l,m-1,k);
            else
            return bsl(arr,m+1,r,k);
        }
    }
    else
    return r;
}

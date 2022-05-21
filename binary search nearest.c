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

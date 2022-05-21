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

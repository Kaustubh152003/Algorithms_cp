int* primegen(int n) //generates all primes less than n. end of array has -1. returns that array
{
    int j=2;
    int* arr=(int*)malloc(4*n);
    int mark[n+1];
    j=0;
    while(j<n+1)
    {
        mark[j]=0;
        j++;
    }
    int p=0;
    j=2;
    while(j<n+1)
    {
        if(mark[j]==0)
        {
            arr[p]=j;
            p++;
            int k=2;
            while(j*k<n+1)
            {
                mark[j*k]=1;
                k++;
            }
        }
        j++;
    }
    arr[p]=-1;
    return arr;
}

// u can include this code in main instead. prime[p]=1 if p is prime
int prime[100000];
    int k=0;
    while(k<100000)
    {
        prime[k]=1;
        k++;
    }
    k=2;
    while(k<100000)
    {
        if(prime[k]==1)
        {
            int l=2;
            while(k*l<100000)
            {
                prime[k*l]=0;
                l++;
            }
        }
        k++;
    }

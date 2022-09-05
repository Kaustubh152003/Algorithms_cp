long long power(long long x,long long a)
{
    if(a==0)
    return 1;
    else
    {
        long long p=power(x,a/2);
        p=p*p;
        p=p%1000000007;
        if(a%2==1)
        p=p*x;
        p=p%1000000007;
        return p;
    }
}

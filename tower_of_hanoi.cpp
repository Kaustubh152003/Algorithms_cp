long long toh(int n, int from, int to, int aux) //prints the steps and returns the number of steps
{
    if(n==1)
    {
        printf("move disk %d from rod %d to rod %d\n",n,from,to);
        return 1;
    }
    else
    {
        long long a=toh(n-1,from,aux,to);
        printf("move disk %d from rod %d to rod %d\n",n,from,to);
        long long b=toh(n-1,aux,to,from);
        return a+b+1;
    }
}

long long int meq1(long long int x,long long miv) //gives output of an equation (lets say eq1)
{
    long long ans=x*x-((x-miv)*(x-miv+1))/2;
    return ans;
}
long long int meq2(long long int x,long long miv,long long mav)  //gives output of an equation (lets say eq2)
{
    long long ans=x*x-((x-miv)*(x-miv+1))/2-((x-mav)*(x-mav+1))/2;
    return ans;
}
int bse(long long int target,int l,int r,int miv,int mav) //miv and mav are extra variables, that the equation has
{
    if(l<=r)
    {
        int m=(l+r)/2;
        long long int p;
        p=meq2(m,miv,mav); //get the value of your equation when m is substituted in x
        if(p==maxsum)
        return m;
        else
        {
            if(p<target)
            return bse(target,m+1,r,miv,mav);
            else
            return bse(target,l,m-1,miv,mav);
        }
    }
    else
    return r;
    
}

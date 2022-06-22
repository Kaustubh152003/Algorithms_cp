#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int gcd(int a, int b) 
{ 
	    if(b==0)
	    return a;
	    else
	    {
	        if(a<b)
	        return gcd(b,a);
	        else
	        return gcd(a%b,b);
	    }
	      
} 
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

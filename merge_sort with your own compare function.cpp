int compare(int a,int b) //return 1 if a<b else 0 for ur comparating operation
    {
        if(a<b)
        return 1;
        else
        return 0;
    }
    void merge(int arr[], int l, int m, int r)
    {
        int p=l;
        int q=m+1;
        int res[r-l+1];
        int j=0;
        while(p<=m && q<=r)
        {
            if(compare(arr[p],arr[q]))
            {
                res[j]=arr[p];
                p++;
                j++;
            }
            else
            {
                res[j]=arr[q];
                q++;
                j++;
            }
        }
        while(p<=m)
        {
            res[j]=arr[p];
            p++;
            j++;
        }
        while(q<=r)
        {
            res[j]=arr[q];
            q++;
            j++;
        }
        int k=l;
        j=0;
        while(k<=r)
        {
            arr[k]=res[j];
            j++;
            k++;
        }
    }
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r)
        {
            int m=(l+r)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
        }
        
    }

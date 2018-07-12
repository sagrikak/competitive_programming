    #include <iostream>
    #include <string.h>
    #include <inttypes.h>
    using namespace std;
     
    void quicksort(int64_t a[], int64_t beg, int64_t end)
    {
        int64_t pivot, x, i, temp;
        if(beg>=end)
        return;
        
        temp=a[(beg+end)/2];
        a[(beg+end)/2]=a[end];
        a[end]=temp;
        
        pivot=a[end];
        x=beg;
        
        for(i=beg; i<end; i++)
        {
            if(a[i]<=pivot)
            {
                temp=a[x];
                a[x]=a[i];
                a[i]=temp;
                x++;
            }
        }
        temp=a[end];
        a[end]=a[x];
        a[x]=temp;
        quicksort(a, beg, x-1);
        quicksort(a, x+1, end);
    }
     
    int main()
    {
        int64_t test;
        cin>>test;
        for(int64_t i=0; i<test; i++)
        {
            int64_t n, x;
            cin>>n;
            int64_t mat[n][4];
            int64_t y, min, z, sum=0, minsum;
            for(int64_t j=0; j<n; j++)
            {
                cin>>mat[j][0]>>mat[j][1]>>mat[j][2]>>mat[j][3];
                sum=mat[j][0]+mat[j][1]+mat[j][2]+mat[j][3];
                if(j==0)
                {
                    minsum=sum;
                }
                else if(minsum>sum)
                {
                    minsum=sum;
                }
            }
            for(int64_t j=0; j<n; j++)
            {
                y=mat[j][0]+mat[j][1]*2+mat[j][2]*4+mat[j][3]*8;
                if(j==0)
                {
                    min=y;
                    x=j;
                }
                else if(y<min)
                {
                    min=y;
                    x=j;
                }
            }
            int64_t q;
            cin>>q;
            for(int64_t j=0; j<q; j++)
            {
                int64_t t;
                cin>>t;
                if(t==1)
                    cout<<minsum<<endl;
                else
                {
                    z = mat[x][0] + mat[x][1]*t + mat[x][2]*t*t + mat[x][3]*t*t*t;
                    cout<<z<<endl;
                }
            }
        }
    } 
    #include <iostream>
    #include <math.h>
    using namespace std;
     
    int main()
    {
    	int t;
    	cin>>t;
    	for(int i=0; i<t; i++)
    	{
    		long long int y, a, b;
    		unsigned long long int x=0;
    		cin>>y;
    		//unsigned long long int mat[100000][700];
    		for(b=1; b<=700; b++)
    		{
    			for(a=(int)sqrt(y); a>=1; a--)
    			{
    				if(a*a+b<=y)
    				{
                        //cout<<a<<" "<<b<<endl;
    					x+=a;
                        break;
    				}
    			}
    		}
    		cout<<x<<endl;
    	}
    } 
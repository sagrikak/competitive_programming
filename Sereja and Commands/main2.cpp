    #include <iostream>
    #include <stdlib.h>
    using namespace std;
     
    int com[100000][3];
     
    void first(int arr[], int i, int j)
    {
    	for(int k=i; k<=j; k++)
    		arr[k]=arr[k]%1000000007 + 1;
    }
     
    void second(int arr[], int i, int j)
    {
    	for(int k=i; k<=j; k++)
    	{
    		if(com[k][0]==1)
    			first(arr, com[k][1]-1, com[k][2]-1);
    		else
    			second(arr, com[k][1]-1, com[k][2]-1);
    	}
    	return;
    }
     
    int main()
    {
    	int t;
    	cin>>t;
    	for(int i=0; i<t; i++)
    	{
    		int n, m;
    		cin>>n>>m;
    		int* arr;
    		arr=(int*)calloc(n, sizeof(int));
    		for(int j=0; j<m; j++)
    		{
    			cin>>com[j][0]>>com[j][1]>>com[j][2];
    			if(com[j][0] == 1)
    				first(arr, com[j][1]-1, com[j][2]-1);
    			else
    			{
    				second(arr, com[j][1]-1, com[j][2]-1);
    			}
                /*for(int j=0; j<n; j++)
                    cout<<arr[j]<<" ";
                cout<<endl;*/
    		}
    		for(int j=0; j<n; j++)
    			cout<<arr[j]<<" ";
    		cout<<endl;
    	}
    } 
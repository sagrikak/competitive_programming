#include<iostream>
using namespace std;

void quicksort(int a[][2], int beg, int end, int k)
{
    int pivot, x, i, temp;
    if(beg>=end)
    return;
    
    temp=a[(beg+end)/2][0];
    a[(beg+end)/2][0]=a[end][0];
    a[end][0]=temp;

    temp=a[(beg+end)/2][1];
    a[(beg+end)/2][1]=a[end][1];
    a[end][1]=temp;
    
    pivot=a[end][k];
    x=beg;
    
    for(i=beg; i<end; i++)
    {
        if(a[i][k]<=pivot)
        {
            temp=a[x][0];
            a[x][0]=a[i][0];
            a[i][0]=temp;

            temp=a[x][1];
            a[x][1]=a[i][1];
            a[i][1]=temp;
            x++;
        }
    }
    temp=a[end][0];
    a[end][0]=a[x][0];
    a[x][0]=temp;

    temp=a[end][1];
    a[end][1]=a[x][1];
    a[x][1]=temp;
    quicksort(a, beg, x-1, k);
    quicksort(a, x+1, end, k);
}

int main(){
	int n, t;
	cin>>t;
	for(int a=0; a<t; a++){
		cin>>n;
		//n=100000;
		int arr[n][2], ans=1, temp, temp1;
		for(int i=0; i<n; i++){
			cin>>arr[i][0];
			arr[i][1]=i;
		}
		
		/*for(int i=1; i<=n; i++){
			arr[i-1][0]=i;
			arr[i-1][1]=i-1;
		}*/

		if(arr[0][0]>=arr[n-1][0])
			ans=n;
		else{

			for(int i=0; i<n; i++){
				//cout<<"aa"<<endl;
				quicksort(arr, 0, n-1, 0);
				temp = arr[i][1];
				temp1 = arr[i][0];
				/*for(int j=0; j<n; j++){
					cout<<arr[j][0]<<" "<<arr[j][1]<<endl;
				}*/
				//cout<<"xx"<<endl;
				quicksort(arr, i, n-1, 1);
				/*for(int j=0; j<n; j++){
					cout<<arr[j][0]<<" "<<arr[j][1]<<endl;
				}*/
				if(arr[i][1]<=temp && ans<temp-arr[i][1]+1){
					//cout<<arr[i][0]<<" "<<temp1<<endl;
					ans=temp-arr[i][1]+1;
				}
			}
		}

		cout<<ans<<endl;
	}
}
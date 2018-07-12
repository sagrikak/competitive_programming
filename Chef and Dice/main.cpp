#include <iostream>
#include <string.h>
using namespace std;

int mat[6][6];
int xyz[6][6];

int remove(int x, int y, int matrix[6][6], int l)
{
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
		{
			xyz[i][j] = matrix[i][j];
		}
	}
	for(int i=0; i<6; i++)
	{
		if(i!=y)
			xyz[x][i] = 0;
	}
	for(int i=0; i<6; i++)
	{
		if(i!=x)
			xyz[y][i] = 0;
	}
	for(int i=0; i<6; i++)
	{
		if(i!=x && i!=y)
		{
			xyz[i][x] = 0;
			xyz[i][y] = 0;
		}
	}
	for(int i=0; i<6; i++)
	{
		int count=0;
		for(int j=0; j<6; j++)
		{
			if(xyz[i][j] == 0)
				count++;
			if(count == 6)
				return 0;
		}
	}
	if(l==1)
	{
		for(int i=0; i<6; i++)
		{
			for(int j=0; j<6; j++)
			{
				matrix[i][j] = xyz[i][j];
			}
		}
	}
	return 1;
}

void calc(int x)
{
	for(int i=0; i<=x; i++)
	{
		for(int j=0; j<6; j++)
		{
			if(mat[i][j] == 1 && i!=j && remove(i, j, mat, 0) != 0)
			{
				remove(i, j, mat, 1);
				break;
			}
		}
	}
}

int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		for(int i=0; i<6; i++)
		{
			for(int j=0; j<6; j++)
			{
				if(i!=j)
					mat[i][j]=1;
				else mat[i][j] = 0;
			}
		}
		int n, x=1;
		cin>>n;
		int arr[n];
		
		for(int j=0; j<n; j++)
		{
			cin>>arr[j];
			if(j>=1)
			{
				if(arr[j] == arr[j-1])
					x=0;
			}
		}
		for(int j=1; j<n; j++)
		{
			mat[arr[j]-1][arr[j-1]-1] = 0;
			mat[arr[j-1]-1][arr[j]-1] = 0;
		}

		calc(0);
		calc(1);
		calc(2);
		calc(3);
		calc(4);
		calc(5);

		/*for(int i=0; i<6; i++)
		{
			for(int j=0; j<6; j++)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;*/

		for(int i=0; i<6; i++)
		{
			int count=0;
			for(int j=0; j<6; j++)
			{
				if(xyz[i][j] == 0)
					count++;
				if(count == 6)
				{
					x=0;
					break;
				}
			}
		}

		if(x==0)
			cout<<"-1"<<endl;
		else
		{
			for(int j=0; j<6; j++)
			{
				for(int k=0; k<6; k++)
				{
					if(mat[j][k] == 1)
						cout<<k+1<<" ";
				}
			}
			cout<<endl;
		}
	}
}
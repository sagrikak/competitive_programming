#include <stdio.h>
#include <string.h>

int main()
{
	int n, k, i, j;
	scanf("%d%d", &n, &k);
	int parent[n+1], visited[n+1];
	int col[n+1], a[n-1], b[n-1];
	memset(parent, -1, sizeof(parent));
	for(i=1; i<=n; i++)
		scanf("%d", &col[i]);
	parent[1]=0;
	visited[1]=1;
	for(i=0; i<n-1; i++)
		scanf("%d%d", &a[i], &b[i]);
	int l=0;
	i=0;
	while(l<n-1)
	{
		if(visited[a[i]] == 1 && visited[b[i]] != 1)
		{
			parent[b[i]] = a[i];
			visited[b[i]] = 1;
			l++;
		}
		else if(visited[b[i]] == 1 && visited[a[i]] != 1)
		{
			parent[a[i]] = b[i];
			visited[a[i]] = 1;
			l++;
		}
		i=(i+1)%(n-1);
	}
	//for(i=1; i<=n; i++)
	//	printf("%d ", parent[i]);
	//printf("\n");

	int ans[n+1];
	ans[1] = -1;
	for(i=2; i<=n; i++)
	{
		int count=0, temp=i;
		while(temp != 1)
		{
			temp=parent[temp];
			//printf("temp=%d i=%d\n", temp, i);
			if(col[temp] == col[i])
				count++;
			if(count==k)
				break;
		}
		if(count<k)
			ans[i]=-1;
		else ans[i]=temp;
		//printf("count=%d\n", count);
	}
	for(i=1; i<=n; i++)
		printf("%d ", ans[i]);
}
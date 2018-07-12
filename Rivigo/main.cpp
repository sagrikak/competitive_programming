#include <iostream>

using namespace std;

int main()
{
    int t,s,ow;
    cin>>t>>s>>ow;
    char pit1,pit2;
    int dist1,dist2;
    cin>>pit1>>pit2>>dist1;
    cin>>pit2>>pit1>>dist2;
    int id, time;
    char start, dest;
    int onetotwo[s][3],twotoone[s][3];
    for(int i=0;i<s;i++)
    {
        cin>>id>>start>>time>>dest;
        if(start==pit1)
        {
            onetotwo[id][0]=id;
            onetotwo[id][1]=time;
            onetotwo[id][2]=time+dist1;
            twotoone[id][0]=-1;
            twotoone[id][1]=-1;
            twotoone[id][2]=-1;
        }
        else
        {
            twotoone[id][0]=id;
            twotoone[id][1]=time;
            twotoone[id][2]=time+dist2;
            onetotwo[id][0]=-1;
            onetotwo[id][1]=-1;
            onetotwo[id][2]=-1;
        }
    }

    /*for(int i=0;i<s;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<onetotwo[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<s;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<twotoone[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/

    int matrix[s][s];
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {
            if(onetotwo[i][0]!=-1 && twotoone[j][0]!=-1)
            {
                matrix[i][j]=twotoone[j][1]-onetotwo[i][2];
                if(matrix[i][j]>10)
                {
                    matrix[i][j]=(matrix[i][j]-10)*2+10;
                }
                if(matrix[i][j]<0)
                    matrix[i][j]=-1;
            }
            else if(onetotwo[j][0]!=-1 && twotoone[i][0]!=-1)
            {
                matrix[i][j]=onetotwo[j][1]-twotoone[i][2];
                if(matrix[i][j]>10)
                {
                    matrix[i][j]=(matrix[i][j]-10)*2+10;
                }
                if(matrix[i][j]<0)
                    matrix[i][j]=-1;
            }
            else
            {
                matrix[i][j]=-1;
            }
        }
    }

    int unmatched[s];
    for(int i=0;i<s;i++)
    {
        if(onetotwo[i][0]!=-1)
        {
            unmatched[i]=ow-onetotwo[i][2];
            if(unmatched[i]<0)
                unmatched[i]=0;
            else if(unmatched[i]>10)
            {
                unmatched[i]=(unmatched[i]-10)*2+10;
            }
        }
        else if(twotoone[i][0]!=-1)
        {
            unmatched[i]=ow-twotoone[i][2];
            if(unmatched[i]<0)
                unmatched[i]=0;
            else if(unmatched[i]>10)
            {
                unmatched[i]=(unmatched[i]-10)*2+10;
            }
        }
    }

    for(int v=0;v<s;v++)
    {
        for(int j=0;j<s;j++)
        {
            cout<<matrix[v][j]<<" ";
        }
        cout<<endl;
    }

    int matched[s][2],totalcost=0,mini=-2,l=0,var=0,finalmatched[s][2],leastcost=-1,m,n, finalvar=0;
    for(int i=0;i<s;i++)
    {
        l=i;
        int used[s]={0};
        var=0;
        for(int j=0;j<s;j++)
        {
            //cout<<"l="<<l<<endl;
            mini=-2;
            for(int k=0;k<s;k++)
            {
                if(used[l]!=1 && used[k]!=1)
                {
                    //cout<<"check "<<l<<" "<<k<<endl;
                    //cout<<matrix[l][k]<<" "<<mini<<endl;
                   if(matrix[l][k]>=0)
                   {
                       if(mini==-2 || (matrix[l][k]<mini))
                       {
                           mini=matrix[l][k];
                           m=l;
                           n=k;
                       }
                   }
                }
            }
            if(mini!=-2)
            {
                used[m]=1;
                used[n]=1;
                matched[var][0]=m;
                matched[var][1]=n;
                var++;

                /*cout<<"used"<<endl;
                for(int v=0; v<s; v++)
                    cout<<used[v]<<" ";
                cout<<endl;*/
                
                totalcost=totalcost+matrix[m][n];
            }

            l=(l+1)%s;
        }
        
        for(int x=0;x<s;x++)
        {
            if(used[x]==0)
            {
               totalcost=totalcost+unmatched[x];
               matched[var][0]=x;
               matched[var][1]=-1;
               var++;
            }
        }

        cout<<"matched"<<endl;
        for(int v=0; v<var; v++)
            cout<<matched[v][0]<<" "<<matched[v][1]<<endl;

        if(totalcost<leastcost || leastcost==-1)
        {
            leastcost=totalcost;
            finalvar=var;
            for(int v=0; v<var; v++)
            {
                finalmatched[v][0]=matched[v][0];
                finalmatched[v][1]=matched[v][1];
            }
        }
    }

    //printing output
    cout<<finalvar<<endl;
    for(int i=0; i<finalvar; i++)
    {
        if(onetotwo[matched[i][0]][0]!=-1)
        {
            cout<<pit1<<" "<<pit2<<" "<<matched[i][0]<<" "<<matched[i][1]<<" ";
            if(matched[i][1]==-1)
            {
                cout<<"-1"<<endl;
            }
            else cout<<pit2<<endl;
        }
        else
        {
            cout<<pit2<<" "<<pit1<<" "<<matched[i][0]<<" "<<matched[i][1]<<" ";
            if(matched[i][1]==-1)
            {
                cout<<"-1"<<endl;
            }
            else cout<<pit1<<endl;
        }
    }
    cout<<leastcost;
}
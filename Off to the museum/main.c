#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, num=0, price, l;
    int total=0;
    int sum=0;
    int notes[6];
    int tick[1000]={0};
    for(i=0; i<6; i++)
        scanf("%d", &notes[i]);
    scanf("%d", &price);
    total=notes[0]*10+notes[1]*50+notes[2]*100+notes[3]*500+notes[4]*1000+notes[5]*5000;
    j=0;
    for(i=0; i<6; i++)
        num=notes[i]+num;

    for(i=0; i<6; i++)
    {
        if(notes[i]>0 && num>1)
        {
            notes[i]=notes[i]-1;
            sum=notes[0]*10+notes[1]*50+notes[2]*100+notes[3]*500+notes[4]*1000+notes[5]*5000;

            while(sum<=total)
            {
                sum=sum+price;
                 tick[j]=sum/price;
                 j++;

            }
            break;
        }
        else if(notes[i]>0 && num==1)
        {
            j=1;
            tick[0]=total/price;
        }
    }
    printf("%d\n", j);
    for(i=0; i<j; i++)
        printf("%d ", tick[i]);
    return 0;
}

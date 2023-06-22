/*sjf*/
#include<stdio.h>
#define N 10
/*
4
1 0 7
2 2 4
3 4 1
4 5 4

wt
0 2 7 7
ct
7 8 12 16
tat
7 6 8 11

awt=4
act= 10.75
atat = 8
*/
int  at[N], ct[N], tat[N], wt[N];
float act,awt,atat;
int main()
{
    int temp,i,j,n,p[N], bt[N];

    printf("Shortest job first...... enter no of process:");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        printf("P ");
        scanf("%d", &p[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
    }

    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(at[j]<at[i]){
                temp = p[i];
                p[i]=p[j];
                p[j]=temp;

                temp = bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp = at[i];
                at[i]=at[j];
                at[j]=temp;
            }
        }
    }

    /*printf("\n p\t at\t bt\n");

    for(i=1;i<=n;i++){
        printf("%d\t%d\t%d\n",p[i],at[i],bt[i]);
    }*/

    ct[1]= bt[1]+at[1];
    //printf("%d\n",ct[1]);

    for(i=1;i<=n;i++)
    {
        int min = i;
        for(j=i;j<=n;j++)
        {
            if(at[j] <= ct[i-1] && bt[j] <= bt[min])
            {
                min = j;
            }
        }
        int temp = p[i];
        p[i] = p[min];
        p[min] = temp;

        temp = bt[i];
        bt[i] = bt[min];
        bt[min] = temp;

        temp = at[i];
        at[i] = at[min];
        at[min] = temp;

        ct[i] = ct[i-1] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

    }

    printf("p\tat\tbt\tct\ttat\twt\n");

    for(i=1;i<=n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
        act += ct[i];
        awt += wt[i];
        atat += tat[i];
    }
    act = act/n;
    awt = awt/n;
    atat = atat/n;
    printf("\n Average completion time = %f", act);
    printf("\n Average waiting time = %f", awt);
    printf("\n Average turnaround time = %f", atat);

    return 0;
}
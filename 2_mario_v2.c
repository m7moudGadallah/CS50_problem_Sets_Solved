#include<stdio.h>

int main()
{
    int n;
    do
    {
        printf("Height: ");
        scanf("%d",&n);
    } while (n<1 || n>8);

    for(int i=1;i<=n;i++)
    {
        for(int k=0;k<n-i;k++)
            printf(" ");
        int r=2*i+1;
        for(int j=0;j<r;j++)
        {
            if(j==r/2) 
            {
                printf("  ");
                continue;
            }
            printf("#");
        }
        printf("\n");
    }
    
    return 0;
}
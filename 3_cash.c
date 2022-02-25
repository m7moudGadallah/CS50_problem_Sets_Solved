#include<stdio.h>


int main()
{
    double n;
    do
    {
        printf("Change owed: ");
        scanf("%lf",&n);
    } while (n<=0);

    n*=100;
    int val=n,ans=0;
    ans+=val/25;
    val%=25;
    ans+=val/10;
    val%=10;
    ans+=val/5;
    val%=5;
    ans+=val;
    printf("%d",ans);
    
    return 0;
}
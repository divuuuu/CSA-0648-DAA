#include <stdio.h>
int main()
{
int n,f=1,i;
printf("Enter a positive integer: ");
scanf("%d", &n);
for(i=1;i<=n;i++)
{
f=f*i;
}
printf("Factorial of %d = %d",n, f) ;
}

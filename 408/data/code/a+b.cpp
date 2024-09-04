#include <stdio.h>
int main()
{
	int n;
	//	scanf("%d %d",&a,&b);
	//	printf("%d",a+b);

	scanf("%d", &n);
	//	int m=0,i,j;
	//	for(i=1;i<=n;i++)
	//	{
	//		for(j=1;j<=i*2;j++)
	//		{
	//			m++;
	//	printf("%d--%d--%d\n",i,j,m);
	//		}
	//	 }
	int x = 2;
	while (x < n / 2)
	{
		x = 2 * x;
		printf("%d\n", x);
	}
}

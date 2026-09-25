#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a=1;
    int b=2;
    printf("%p\n",&a);
    printf("%p\n",&b);
    int *p=&a;
    printf("%p\n",p);
    printf("%d\n",*p);
    *p=10;
    printf("%d\n",a);
    p=&b;
    printf("%d\n",*p);
    int x[3]={1,2,3};
    *x=2;
    printf("x[0]=%d\n",*x);
    int n;
    scanf("%d",&n);
    int *p1;
    p1=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p1[i]);
        printf("p1[%d]=%d\n",i,p1[i]);
    }

    free(p1);
    return 0;
}
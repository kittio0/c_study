#include<stdio.h>
const int z=100;
int main()
{
    
    int a=1;
    int b=2;
    printf("%d + %d = %d\n",a,b,a+b);
    printf("%d - %d = %d\n",a,b,a-b);
    printf("%d * %d = %d\n",a,b,a*b);
    printf("%d / %d = %d\n",a,b,a/b);
    int c;
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        printf("数字为%d\n",c);
        break;
    case 2:
        printf("数字为%d\n",c);
        break;
    default:
        printf("无\n");
        break;
    }

    printf("sizeof(int)=%d\n",sizeof(int));

    //数组
    int x;
    scanf("%d",&x);
    int a1[x];
    for (int i = 0; i < x; i++)
    {
        a1[i]=i+1;
        printf("%d\n",a1[i]);
    }
    int count=sizeof(a1)/sizeof(a1[0]);
    printf("count=%d\n",count);
    
    return 0;
};
   



#include <stdio.h>
#include <math.h>
int main()
{
    // 水仙花数：一个**n 位整数**，它每个位上数字的立方之和等于它本身,输出所有的水仙花数。
    /*
    int n;
    scanf("%d", &n);
    for (int i = pow(10, n - 1); i < pow(10, n); i++)
    {
        int temp = i;
        int x=0;
        while (temp>0)
        {
            x += pow(temp % 10, 3);
            temp /= 10;
        }
        if (x == i)
        {
            printf("%d\n", i);
        }
        
    }
        */

        //两数最大公约数
   int a, b;
    scanf("%d %d", &a, &b);

    int c = (a < b) ? a : b;   
    int count = 1;            

    for (int i = 1; i <= c; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            count = i;
        }
    }

    printf("最大公约数为: %d\n", count);

    
//     输入两个整数 m,n（\(1<=m <n <=1000\)），统计区间 `[m,n]` 内素数的个数，并求这些素数的和。
// 素数定义：大于 1，只能被 1 和自身整除的整数。

    int m, n;
    scanf("%d %d", &m, &n);
    int count = 0;
    int sum = 0;
    for (int i = m; i <= n; i++)  
    {
        int x=0;
        if (i < 2)
        {
            continue;
        }
        for(int j=2; j<=sqrt(i); j++)
        {
            if (i % j == 0)
            {
                x = 1;
                break;
            }
        }
        if (x == 0)
        {
            count++;
            sum += i;
        }
    }
    printf("素数个数：%d\n", count);
    printf("素数和：%d\n", sum);
    return 0;
}
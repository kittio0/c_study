// 5-0.求序列前N项和(15)
// 本题要求编写程序,计算序列2/1+3/2+5/3+8/5+ …. 的前N项之和。注意该序列从第2项起,每一项的分子是前一项分子与分母的和,分母
// 是前一项的分子。

// 输入格式:
// 输入在一行中给出一个正整数N。

// 输出格式:
// 在一行中输出部分和的值,精确到小数点后2位。题目保证计算结果不超过双精度范围。

// 输入样例:
// 20
// 输出样例:
// 32.66
#include <stdio.h>
#include <math.h>
int is_prime(int i);
int main()
{
    // int n;
    // scanf("%d", &n);
    // double sum = 0.0;
    // double a = 2.0;
    // double b = 1.0;
    // for (int i = 0; i < n; i++)
    // {
    //     double x=a/b;
    //     sum+=x;
    //     double temp = a;
    //     a = a + b;
    //     b = temp;
    // }
    // printf("%.2lf\n", sum);
    

    // 输入一个正整数 n，找出 **2 ~ n 之间所有素数，保存到数组中，最后遍历数组打印全部素数**。

    int n;
    scanf("%d", &n);
    int primes[n];
    int count=0;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime(i))
        {
            
            primes[count] = i;
            count++;
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d ", primes[i]);
    }
    return 0;
}


int is_prime(int i)
{
    int a=1;
    if (i < 2)
    {
        a=0;  
    }
    for(int j=2;j<=sqrt(i);j++)
    {
        if (i%j==0)
        {
            a=0;
            break;
        }
    }
    return a;
}
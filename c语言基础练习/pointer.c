#include<stdio.h>
#include<stdlib.h>
void moveZeroes(int* nums, int numsSize);
void reverseArr(int *arr, int n);
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
    // int n;
    // scanf("%d",&n);
    // int *p1;
    // p1=(int*)malloc(n*sizeof(int));
    // for(int i=0;i<n;i++)
    // {
    //     scanf("%d",&p1[i]);
    //     printf("p1[%d]=%d\n",i,p1[i]);
    // }

    // free(p1);



//     给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。

// 示例 1:

// 输入: nums = [0,1,0,3,12]
// 输出: [1,3,12,0,0]
// 示例 2:

// 输入: nums = [0]
// 输出: [0]
 
// 提示:
// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1


    int nums[] = {0,1,0,3,12};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    moveZeroes(nums, numsSize);
    for(int i=0; i<numsSize; i++)
    {
        
        printf("%d ", nums[i]);
    }
    printf("\n");
    reverseArr(nums, numsSize);
    

    return 0;

}


void moveZeroes(int* nums, int numsSize) {
    int* p = nums;
    int* q = nums;
    while(p < nums + numsSize)
    {
        if(*p != 0)
        {
            *q = *p;
            q++;
        }
        p++;
    }
    while(q < nums + numsSize)
    {
        *q = 0;
        q++;
    }
}



// 写一个函数 `void reverseArr(int *arr, int n)`

// - 参数 1：`int *arr` 数组首地址（指针）
// - 参数 2：`int n` 数组元素个数
// - 功能：**原地反转数组**，不能新建数组，只用指针操作，不使用数组下标`[]`
// - main 函数里测试，打印反转前后结果

// > 
// > 考察知识点：
// > 指针传参、指针移动、解引用、函数内修改原数组（重点：数组传参本质传指针）

// ### 示例

// 输入数组：`{1,2,3,4,5}`
// 反转后：`{5,4,3,2,1}`

void reverseArr(int *arr, int n)
{
    int *left=arr;
    int *right=arr+n-1;
    while(left<right)
    {
        int temp=*left;
        *left=*right;
        *right=temp;
        left++;
        right--;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}
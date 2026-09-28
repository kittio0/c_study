/*实现一个 C 语言通讯录，底层使用**单向链表**存储联系人。
每个联系人包含：姓名（最多 19 字符）、电话号码（最多 14 字符）。
功能要求：

1. 添加联系人（尾插法新增节点）
2. 删除联系人：按姓名删除第一个匹配的联系人
3. 修改联系人：根据旧姓名，修改手机号
4. 查找联系人：输入姓名，查询联系人信息
5. 显示全部联系人
6. 保存到文件：将链表数据持久化存入`contact.dat`二进制文件

>
> ⚠️重点：链表节点包含`next`指针，**不能直接保存指针地址**。需要单独定义无指针的存储结构体，用 memcpy 拷贝业务数据再写入文件；读取文件时，重新 malloc 节点，重建链表。

7. 程序退出时自动保存；程序启动自动加载文件内联系人
8. 程序结束释放全部链表内存，防止内存泄漏*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILENAME "contact.dat"

struct Contact
{
    char name[20];
    char phone[15];
    struct Contact *next;
};
struct Contact1
{
    char name[20];
    char phone[15];
};

// 菜单
int start(void);
// 添加联系人
void addContact(struct Contact **head);
//删除联系人
void deleteContact(struct Contact **head);
//修改联系人
void modifyContact(struct Contact **head,const char name[],const char phone[]);
//查找联系人
struct Contact *findContact(struct Contact *head,const char name[]);
//显示所有联系人
void showContact(struct Contact *head);
//保存文件
void saveFile(struct Contact *head,const char *filename);
//读取文件
void readFile(struct Contact **head,const char *filename);
//释放整条链表
void freeContact(struct Contact **head);

int main(void)
{
    struct Contact *head = NULL;
    readFile(&head,FILENAME);
    while(1)
    {
        int choice = start();
        switch (choice)
        {
        case 0:
            saveFile(head,FILENAME);
            freeContact(&head);
            printf("已保存，程序退出\n");
            return 0;
        case 1:
            addContact(&head);
            break;
        case 2:
            deleteContact(&head);
            break;
        case 3:
        {
            char name[20];
            char phone[15];
            printf("请输入联系人姓名：");
            scanf("%19s",name);
            printf("请输入联系人电话：");
            scanf("%14s",phone);
            printf("------------------\n");
            modifyContact(&head,name,phone);
            break;
        }
        case 4:
        {
            char name[20];
            printf("请输入联系人姓名：");
            scanf("%19s",name);
            struct Contact *p = findContact(head,name);
            if(p != NULL)
            {
                printf("姓名：%s\n",p->name);
                printf("电话：%s\n",p->phone);
                printf("-------------------\n");
            }else
            {
                printf("没有该联系人\n");
            }
            break;
        }
        case 5:
            showContact(head);
            break;
        case 6:
            saveFile(head,FILENAME);
            break;
        default:
            printf("无效选项，请重新输入\n");
            break;
        }
    }
}

// 菜单
int start(void)
{
    int a;
    printf("*****************\n");
    printf("1.添加联系人\n");
    printf("2.删除联系人\n");
    printf("3.修改联系人\n");
    printf("4.查找联系人\n");
    printf("5.显示全部联系人\n");
    printf("6.保存文件\n");
    printf("0.退出\n");
    printf("*****************\n");
    printf("请选择：");
    if(scanf("%d",&a) != 1)
    {
        int ch;
        if(feof(stdin))
        {
            return 0;
        }
        while((ch = getchar()) != '\n' && ch != EOF)
        {
            ;
        }
        return -1;
    }
    return a;
}

// 添加联系人
void addContact(struct Contact **head)
{
     struct Contact *newNode = (struct Contact *)malloc(sizeof(struct Contact));
     if(newNode == NULL)
     {
         printf("内存分配失败\n");
         return;
     }
     printf("请输入联系人姓名：");
     scanf("%19s",newNode->name);
     printf("请输入联系人电话：");
     scanf("%14s",newNode->phone);
     newNode->next = NULL;

     if(*head == NULL)
     {
          *head = newNode;
     }else
     {
         struct Contact *p = *head;
         while(p->next != NULL)
         {
             p = p->next;
         }
         p->next = newNode;
     }
     printf("添加成功\n");
}
//删除联系人
void deleteContact(struct Contact **head)
{
    if(*head == NULL)
    {
        printf("链表为空\n");
        return;
    }
    printf("请输入联系人姓名：");
    char name[20];
    scanf("%19s",name);
    if(strcmp((*head)->name,name) == 0)
    {
        struct Contact *q = *head;
        *head = (*head)->next;
        free(q);
        printf("删除成功\n");
        return;
    }
    struct Contact *p = *head;
    while(p->next != NULL)
    {
        if(strcmp(p->next->name,name) == 0)
        {
            struct Contact *q = p->next;
            p->next = q->next;
            free(q);
            printf("删除成功\n");
            return;
        }
        p = p->next;
    }
    printf("没有该联系人\n");

}
//修改联系人
void modifyContact(struct Contact **head,const char name[],const char phone[])
{
    if(*head == NULL)
    {
        printf("链表为空\n");
        return;
    }
    struct Contact *p = *head;
    while(p != NULL)
    {
        if(strcmp(p->name,name) == 0)
        {
            strcpy(p->phone,phone);
            printf("修改成功\n");
            return;
        }
        p = p->next;
    }
    printf("修改失败\n");

}
//查找联系人
struct Contact *findContact(struct Contact *head,const char name[])
{
    struct Contact *p = head;
    while(p != NULL)
    {
        if(strcmp(p->name,name) == 0)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
//显示所有联系人
void showContact(struct Contact *head)
{
    if(head == NULL)
    {
        printf("链表为空\n");
        return;
    }
    struct Contact *p = head;
    while(p != NULL)
    {
        printf("姓名：%s\n",p->name);
        printf("电话：%s\n",p->phone);
        printf("-------------------\n");
        p = p->next;
    }
}
//保存文件
void saveFile(struct Contact *head,const char *filename)
{
    FILE *fp = fopen(filename,"wb");
    if(fp == NULL)
    {
        printf("文件打开失败\n");
        return;
    }
    struct Contact *p = head;
    struct Contact1 c;
    int count = 0;
    while(p != NULL)
    {
        strcpy(c.name,p->name);
        strcpy(c.phone,p->phone);
        fwrite(&c,sizeof(struct Contact1),1,fp);
        count++;
        p = p->next;
    }
    fclose(fp);
    printf("保存了%d条数据\n",count);
}
//读取文件
void readFile(struct Contact **head,const char *filename)
{
    FILE *fp = fopen(filename,"rb");
    if(fp == NULL)
    {
        return;
    }
    struct Contact1 c;
    struct Contact *tail = NULL;
    while(fread(&c,sizeof(struct Contact1),1,fp) == 1)
    {
       struct Contact *newNode = (struct Contact *)malloc(sizeof(struct Contact));
       if(newNode == NULL)
       {
           printf("加载内存分配失败\n");
           fclose(fp);
           return;
       }
       strcpy(newNode->name,c.name);
       strcpy(newNode->phone,c.phone);
       newNode->next = NULL;

       if(*head == NULL)
       {
           *head = newNode;
       }else
       {
           tail->next = newNode;
       }
       tail = newNode;
    }
    fclose(fp);
}
//释放整条链表
void freeContact(struct Contact **head)
{
    struct Contact *p = *head;
    struct Contact *q = NULL;
    while(p!=NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    *head = NULL;
}

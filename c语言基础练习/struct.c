#include<stdio.h>
#include<stdlib.h>
struct a{
    int x;
    struct a *next;

};

//打印链表
void print(struct a* node);
//添加节点
struct a* add(struct a** node, int x);
//查找链表
struct a* find(struct a* node, int x);
//删除节点
struct a* delete(struct a** node, int x);
//消除链表
void clear(struct a** node);
//修改链表
void change(struct a** node,int index,int value);
int main()
{
    /*struct student s1;
    printf("enter name and age:");
    scanf("%s %d",s1.name,&s1.age);
    printf("name:%s\nage:%d",s1.name,s1.age);
    */
    
//     实现一个整数单链表，完成下面 4 个功能：

// 1. **增加**：头插法，在链表头部插入新节点
// 2. **删除**：删除链表中**第一个值等于 target**的节点
// 3. **修改**：把链表第一个等于 oldVal 的节点，值改成 newVal
// 4. **查找**：查找 target，找到返回该节点指针；找不到返回 NULL
    
     struct a* head=NULL;
     add(&head, 1);
     add(&head, 2);
     add(&head, 3);
    print(head);
     struct a*p=find(head, 2);
     if(p)
     {
         printf("找到节点%d\n",p->x);
     }
     else
     {
         printf("没有找到节点\n");
     }
    delete(&head, 2);
    print(head);
    change(&head, 1, 5);
    print(head);
    clear(&head);

    return 0;
}

//输出链表
void print(struct a* node)
{ 
    while(node != NULL)
    {
        printf("%d ", node->x);
        node = node->next;
    }
    printf("\n");
}
//添加节点
struct a* add(struct a** node, int x)
{ 
    struct a* newnode=(struct a*)malloc(sizeof(struct a));
    newnode->x=x;
    newnode->next=NULL;
    if(*node==NULL) 
    {
        *node=newnode;
        return *node;
    }
    struct a* p=*node;
    while(p->next!=NULL) 
    {
        p=p->next;
    }
    p->next=newnode;
    
    return newnode;

}

//查找链表
struct a* find(struct a* node, int x)
{ 
    if(node==NULL) return NULL;
    struct a* p=node;
    while(p!=NULL)
    {
        if(p->x==x)
        {
           return p;
        }
        p=p->next;
    }
    return NULL;
}

//删除链表
struct a* delete(struct a** node, int x)
{ 
    if(*node==NULL) return NULL;
    struct a* p=*node;
    if((*node)->x==x)
{
    struct a* temp = *node;  
    *node = (*node)->next;    
    free(temp);              
    return *node;
}

    while (p->next!=NULL)
    {
        if(p->next->x==x)
        {
            struct a* temp=p->next;
            p->next=p->next->next;
            free(temp);
            return *node;
        }
        p=p->next;
       
    }
    return *node;

}

//消除链表
void clear(struct a** node)
{
    struct a* p=*node;
    struct a* temp;
    while (p!=NULL)
    {
        temp=p;
        p=p->next;
        free(temp);
    }
    *node=NULL;
}
//修改链表
void change(struct a** node,int index,int value)
{
    struct a* p=*node;
    int i=0;
    while (p!=NULL)
    {
        if (i==index)
        {
            p->x=value;
            return;
        }
        p=p->next;
        i++;
    }
}
#include<stdio.h>
#include<string.h>
struct student
{
	char name[20];
	int age;
};
const char *conf_file = "student.txt";
//保存内存到文件
int save_file(struct student *p);
//从文件中读取数据
int read_file(struct student *p);
int main()
{
	struct student s1;
    strcpy(s1.name,"zhangsan");
    s1.age = 18;
    save_file(&s1);
    struct student s2;
    read_file(&s2);
    printf("name:%s age:%d\n",s2.name,s2.age);
    FILE *fp= fopen(conf_file,"rb");
    if(fp == NULL)
	{
		printf("open file error\n");
		return -1;
	}
    fseek(fp,0,SEEK_SET);
    struct student s3;
    fread(&s3,sizeof(struct student),1,fp);
    printf("name:%s age:%d\n",s3.name,s3.age);
    fseek(fp,-10,SEEK_END);
    fread(&s3,5,1,fp);
    printf("name:%s age:%d\n",s3.name,s3.age);
    fseek(fp,0,SEEK_END);
    int a=ftell(fp);
    printf("file size:%d\n",a);
    fclose(fp);

    
	return 0;
}
//保存内存到文件
int save_file(struct student *p)
{
	FILE *fp= fopen(conf_file,"wb");
		if(fp == NULL)
	{
		printf("open file error\n");
		return -1;
	}
    fwrite(p,sizeof(struct student),1,fp);
	fclose(fp);
    return 0;
}

//从文件中读取数据
int read_file(struct student *p)
{
	FILE *fp= fopen(conf_file,"rb");
		if(fp == NULL)
	{
		printf("open file error\n");
		return -1;
	}
    fread(p,sizeof(struct student),1,fp);
    fflush(fp);

	fclose(fp);
    return 0;
}
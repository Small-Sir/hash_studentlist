#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stulist.h"

//初始化链表
void init_list(Stu** L)//创建头结点
{
	//Stu* L = (Stu*)malloc(sizeof(Stu));
	(*L)->age = 0;
	(*L)->id = 0;
	strcpy_s((*L)->name,20,"");
	(*L)->next = NULL;
}

int check_id(int id, Stu* L)
{
	while (1)
	{
		printf("请输入id:\n");
		scanf_s("%d", &id);
		while (getchar() != '\n');
		if (id <= 0)
		{
			printf("你所输入的id有误(id应该是一个大于0的整数).\n");
		}
		else//判断id是否重复
		{
			while (L != NULL)
			{
				if (L->id == id)
				{
					printf("所输入的id已经存在\n");
					break;
				}
				L = L->next;
			}
			if (L == NULL)
				return id;
		}
	}
}

int check_age(int age)
{
	while (1)
	{
		printf("请输入age:\n");
		scanf_s("%d", &age);
		while (getchar() != '\n');
		if (age <= 0||age>200)
		{
			printf("你所输入的age有误(age应该是一个大于0的整数小于200的整数).\n");
		}
		else
		{
			return age;
		}
	}
}

char* check_name(char *name)
{
	while (1)
	{
		printf("请输入name:\n");
		scanf_s("%s", name, 20);
		while (getchar() != '\n');
		if (strlen(name) > 19)
		{
			printf("你所输入的name过长(name只能是一个长度为19个字符的字符串).\n");
		}
		else
			return name;
	}
}
void check_val(Stu**pnew, int id,int age,char *name,Stu* L)
{
	//检测id是否合法
	id=check_id(id, L);
	age=check_age(age);
	strcpy_s(name,20,check_name(name));
	(*pnew)->id = id;
	(*pnew)->age = age;
	strcpy_s((*pnew)->name, 20, name);
	(*pnew)->next = NULL;
}


//创建新的节点
Stu* creat_node(Stu* L)
{
	Stu* pnew =(Stu*)malloc(sizeof(Stu));
	int id = 0,age=0;
	char name[20] = "";
	check_val(&pnew,id,age,name,L);
	return pnew;
}

//增加学生信息
void insert_stulist(Stu** L)
{
	Stu* pnew = creat_node(*L);
	//头插法
	pnew->next = (*L)->next;
	(*L)->next = pnew;
}

//查找节点
Stu* find_node(Stu* L, int id)
{
	L = L->next;
	while (L != NULL)
	{
		if (L->id == id)
		{
			//printf("id:%-5d name:%-10s age:%-5d\n", L->id, L->name, L->age);
			//break;
			return L;
		}
		L = L->next;
	}
	return NULL;
}

//找temp 的前一个节点
Stu* find_pri(Stu* L, Stu* temp)
{
	Stu* node = L;
	while (node != NULL)
	{
		if (node->next == temp)
			return node;
		node = node->next;
	}
	return NULL;
}


//摘除所要删除的节点
Stu* take_off(Stu* L, Stu* temp)
{
	Stu* pri = find_pri(L, temp);//找到他的前一个节点
	if (temp==L->next)//所要删除的节点是头节点的下一个节点
	{
		L->next= temp->next;
	}
	else
	{
		pri->next = temp->next;
	}
	temp->next = NULL;
	return temp;
}


//删除一个学生信息
void del_stu_list(Stu** L)
{
	printf("请输入你要删除的id:");
	int id;
	scanf_s("%d", &id);
	while (getchar() != '\n');
	Stu* temp = find_node(*L, id);
	if (temp == NULL)
	{
		printf("查无此人\n");
		return;
	}
	else
	{
		Stu* node = take_off(*L,temp);
		free(node);
		printf("删除成功\n");
		return;
	}
}

//修改一个学生信息
void modify_stu(Stu** L)
{
	printf("请输入你要修改的id:");
	int id=0;
	int age = 0;
	char name[20] = "";
	scanf_s("%d", &id);
	while (getchar() != '\n');
	Stu* node = (Stu*)malloc(sizeof(Stu));
	node = *L;
	while (node != NULL)
	{
		if (node->id == id)
		{
			id = check_id(id, *L);
			age = check_age(age);
			strcpy_s(name, 20, check_name(name));
			node->age = age;
			node->id = id;
			strcpy_s(node->name,20,name);
			printf("修改成功\n");
			return;
		}
		node = node->next;
	}
	if (node == NULL)
	{
		printf("查无此人\n");
	}
}

//查找一个学生信息
void  serach_stu(Stu* L)
{
	printf("请输入你要查找的id:");
	int id;
	scanf_s("%d", &id);
	while (getchar() != '\n');
	Stu* node = find_node(L, id);
	if (node == NULL)
		printf("查无此人\n");
	else
	{
		printf("id:%-5d name:%-10s age:%-5d\n", node->id, node->name, node->age);
		printf("查找成功\n");
	}
}

//显示所有学生信息
void  print_list(Stu* L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("[id:%d|name:%s|age:%d|%p]->",L->id,L->name,L->age,L->next);
		L = L->next;
	}
	printf("NULL\n");
}

//释放链表
void free_list(Stu** L)
{
	if (*L == NULL)
		return;
	free((*L)->next);
	free(*L);
}

void stulist_menu()
{
	char sel;
	Stu* L = (Stu*)malloc(sizeof(Stu));
	init_list(&L);
	for (;;)
	{
		printf(STULIST);
		scanf_s("%c", &sel,1);
		while (getchar() != '\n');
		switch (sel)
		{
		case '1':
			//增加学生信息
			insert_stulist(&L);
			break;
		case '2':
			//删除一个学生信息
			del_stu_list(&L);
			break;
		case '3':
			//修改一个学生信息
			modify_stu(&L);
			break;
		case '4':
			//查找一个学生信息
			serach_stu(L);
			break;
		case '5':
			//显示所有学生信息
			print_list(L);
			break;
		case '6':
			//释放链表
			free_list(&L);
			break;
		case '7':
			printf("谢谢你的使用\n");
			exit(0);
		default:
			printf("你的输入有误\n");
			break;
		}

	}
}
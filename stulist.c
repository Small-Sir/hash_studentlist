#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stulist.h"

//��ʼ������
void init_list(Stu** L)//����ͷ���
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
		printf("������id:\n");
		scanf_s("%d", &id);
		while (getchar() != '\n');
		if (id <= 0)
		{
			printf("���������id����(idӦ����һ������0������).\n");
		}
		else//�ж�id�Ƿ��ظ�
		{
			while (L != NULL)
			{
				if (L->id == id)
				{
					printf("�������id�Ѿ�����\n");
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
		printf("������age:\n");
		scanf_s("%d", &age);
		while (getchar() != '\n');
		if (age <= 0||age>200)
		{
			printf("���������age����(ageӦ����һ������0������С��200������).\n");
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
		printf("������name:\n");
		scanf_s("%s", name, 20);
		while (getchar() != '\n');
		if (strlen(name) > 19)
		{
			printf("���������name����(nameֻ����һ������Ϊ19���ַ����ַ���).\n");
		}
		else
			return name;
	}
}
void check_val(Stu**pnew, int id,int age,char *name,Stu* L)
{
	//���id�Ƿ�Ϸ�
	id=check_id(id, L);
	age=check_age(age);
	strcpy_s(name,20,check_name(name));
	(*pnew)->id = id;
	(*pnew)->age = age;
	strcpy_s((*pnew)->name, 20, name);
	(*pnew)->next = NULL;
}


//�����µĽڵ�
Stu* creat_node(Stu* L)
{
	Stu* pnew =(Stu*)malloc(sizeof(Stu));
	int id = 0,age=0;
	char name[20] = "";
	check_val(&pnew,id,age,name,L);
	return pnew;
}

//����ѧ����Ϣ
void insert_stulist(Stu** L)
{
	Stu* pnew = creat_node(*L);
	//ͷ�巨
	pnew->next = (*L)->next;
	(*L)->next = pnew;
}

//���ҽڵ�
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

//��temp ��ǰһ���ڵ�
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


//ժ����Ҫɾ���Ľڵ�
Stu* take_off(Stu* L, Stu* temp)
{
	Stu* pri = find_pri(L, temp);//�ҵ�����ǰһ���ڵ�
	if (temp==L->next)//��Ҫɾ���Ľڵ���ͷ�ڵ����һ���ڵ�
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


//ɾ��һ��ѧ����Ϣ
void del_stu_list(Stu** L)
{
	printf("��������Ҫɾ����id:");
	int id;
	scanf_s("%d", &id);
	while (getchar() != '\n');
	Stu* temp = find_node(*L, id);
	if (temp == NULL)
	{
		printf("���޴���\n");
		return;
	}
	else
	{
		Stu* node = take_off(*L,temp);
		free(node);
		printf("ɾ���ɹ�\n");
		return;
	}
}

//�޸�һ��ѧ����Ϣ
void modify_stu(Stu** L)
{
	printf("��������Ҫ�޸ĵ�id:");
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
			printf("�޸ĳɹ�\n");
			return;
		}
		node = node->next;
	}
	if (node == NULL)
	{
		printf("���޴���\n");
	}
}

//����һ��ѧ����Ϣ
void  serach_stu(Stu* L)
{
	printf("��������Ҫ���ҵ�id:");
	int id;
	scanf_s("%d", &id);
	while (getchar() != '\n');
	Stu* node = find_node(L, id);
	if (node == NULL)
		printf("���޴���\n");
	else
	{
		printf("id:%-5d name:%-10s age:%-5d\n", node->id, node->name, node->age);
		printf("���ҳɹ�\n");
	}
}

//��ʾ����ѧ����Ϣ
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

//�ͷ�����
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
			//����ѧ����Ϣ
			insert_stulist(&L);
			break;
		case '2':
			//ɾ��һ��ѧ����Ϣ
			del_stu_list(&L);
			break;
		case '3':
			//�޸�һ��ѧ����Ϣ
			modify_stu(&L);
			break;
		case '4':
			//����һ��ѧ����Ϣ
			serach_stu(L);
			break;
		case '5':
			//��ʾ����ѧ����Ϣ
			print_list(L);
			break;
		case '6':
			//�ͷ�����
			free_list(&L);
			break;
		case '7':
			printf("лл���ʹ��\n");
			exit(0);
		default:
			printf("�����������\n");
			break;
		}

	}
}
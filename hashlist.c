//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//#include "hashlist.h"
//
////�ж���������Ƿ�Ϸ�
//void check_vlat(int id, char* name, int age, Stu** pnew, Hash* hash_stu)
//{
//    while (1)///id
//    {
//        printf("please input id:");
//        scanf_s("%d", &id);
//        while (getchar() != '\n');
//        int flag = 0;
//        if (id <= 0)
//        {
//            printf("���������ѧ�Ŵ���,����������\n");
//            continue;
//        }
//        else
//        {
//            int hash = id % 11;
//            if (hash_stu[hash].len > 0)
//            {
//                Stu* node = hash_stu[hash].head;
//                while (node != NULL)
//                {
//                    if (id == node->id)
//                    {
//                        printf("���������id�ظ�\n");
//                        flag = 1;
//                        break;
//                    }
//                    node = node->next;
//                }
//            }
//        }
//        if (flag == 0)
//            break;
//    }
//
//    while (1)///name
//    {
//        printf("please input name:");
//        scanf_s("%s", name,20);
//        while (getchar() != '\n');
//        if (strlen(name) > 19)
//        {
//            printf("������������ֹ���,����������\n");
//            continue;
//        }
//        else
//            break;
//    }
//
//
//    while (1)///age
//    {
//        printf("please input age:");
//        scanf_s("%d", &age);
//        while (getchar() != '\n');
//        if (age <= 0 || age >= 200)
//        {
//            printf("����������䲻���ϳ���,����������\n");
//            continue;
//        }
//        else
//            break;
//    }
//    (*pnew)->age = age;
//    (*pnew)->id = id;
//    strcpy_s((*pnew)->name, 20,name);
//    //(*pnew)->next = NULL;
//}
//
////�ж����޸ĵ��Ƿ�Ϸ�
//void check_vlat1(char* name, int age, Stu** pnew, Hash* hash_stu)
//{
//    while (1)///name
//    {
//        printf("please input name:");
//        scanf_s("%s", name, 20);
//        while (getchar() != '\n');
//        if (strlen(name) > 19)
//        {
//            printf("������������ֹ���,����������\n");
//            continue;
//        }
//        else
//            break;
//    }
//
//
//    while (1)///age
//    {
//        printf("please input age:");
//        scanf_s("%d", &age);
//        while (getchar() != '\n');
//        if (age <= 0 || age >= 200)
//        {
//            printf("����������䲻���ϳ���,����������\n");
//            continue;
//        }
//        else
//            break;
//    }
//    (*pnew)->age = age;
//    strcpy_s((*pnew)->name, 20, name);
//}
////�����µĽڵ�
//Stu* creat_node(Hash* hash_stu)
//{
//	Stu* pnew = (Stu*)malloc(sizeof(Stu));
//	int age=0;
//	int id=0;
//	char name[20]="";
//	check_vlat(id, name, age, &pnew, hash_stu);//���͸�ֵ
//	return pnew;
//}
//
//
////����ѧ����Ϣ
//void insert_stulist(Hash* hash_stu)
//{
//    Stu* pnew = creat_node(hash_stu);
//    int hash = (pnew->id) % 11;
//    if (hash_stu[hash].len == 0)
//    {
//        hash_stu[hash].head = pnew;
//        hash_stu[hash].tail = pnew;
//        pnew->next = NULL;
//    }
//    else
//    {
//                hash_stu[hash].tail->next = pnew;
//                hash_stu[hash].tail = pnew;
//                pnew->next = NULL;
//    }
//    hash_stu[hash].len++;
//}
//
////����һ���ڵ��λ��
//Stu* find_node(Stu* head, int id)
//{
//
//    while (head != NULL)
//    {
//        if (head->id == id)
//            return head;
//        head = head->next;
//    }
//    return NULL;
//}
//
//Stu* take_off_node(Stu** tail, Stu* temp,Stu** head)
//{
//    
//    Stu* node = *head;
//    if (temp == *head)//ͷ���
//    {
//        *head = temp->next;
//    }
//    else
//    {
//        Stu* pri = NULL;
//        while (node != NULL)//�����ҳ�Ŀ��ڵ��ǰһ���ڵ�
//        {
//            if (node->next == temp)
//            {
//                pri=node;
//                break;
//            }  
//            node = node->next;
//        }
//        if (temp == *tail && pri != NULL)//β�ڵ�
//        {
//            *tail = pri;
//            pri->next = NULL;
//        }
//        else if (pri!= NULL)//�м�ڵ�
//        {
//            pri->next = temp->next;
//        }
//    }
//    temp->next = NULL;
//    return temp;
//}
//
//
////ɾ��һ��ѧ����Ϣ
//void del_stu_list(Hash* hash_stu)
//{
//    printf("input you want to delete id:");
//    int id = 0;
//    scanf_s("%d", &id);
//    while (getchar() != '\n');
//    int hash = id % 11;
//    Stu* node = find_node(hash_stu[hash].head, id);
//    Stu* temp = take_off_node(&hash_stu[hash].tail, node ,& hash_stu[hash].head);
//    free(temp);
//    hash_stu[hash].len--;
//    printf("ɾ���ɹ�\n");
//}
//
////�޸�һ��ѧ����Ϣ
//void modify_stu(Hash* hash_stu)
//{
//    printf("input you want to change id:");
//    int id = 0;
//    scanf_s("%d", &id);
//    while (getchar() != '\n');
//    int hash = id % 11;
//    Stu* node= find_node(hash_stu[hash].head, id);
//    if (node != NULL)
//    {
//        int age = 0;
//        char name[20] = "";
//        check_vlat1(name, age, &node, hash_stu);//���͸�ֵ
//    }
//    else
//    {
//        printf("���޴���\n");
//        return;
//    }
//}
//
//
////����һ��ѧ����Ϣ
//void  serach_stu(Hash* hash_stu)
//{
//    printf("input you want to find id:");
//    int id=0;
//    scanf_s("%d", &id);
//    while (getchar() != '\n');
//    int hash = id % 11;
//    Stu* node = find_node(hash_stu[hash].head,id);
//    if (node != NULL)
//    {
//        printf("hash_stu[%d]:", id%11);
//        printf("id:%-5dname:%-5sage:%-5d\n", node->id, node->name, node->age);
//    }
//    else
//    {
//        printf("���޴���\n");
//        return;
//    }
//        
//}
//
////ѧ����Ϣ������ʾ
//void print_hash(Stu* head)
//{
//    while (head != NULL)
//    {
//        printf("[id:%d|name:%s|age:%d]-->", head->id, head->name, head->age);
//        head = head->next;
//    }
//    printf("NULL\n");
//}
//
////��ʾ����ѧ����Ϣ
//void  print_list(Hash* hash_stu)
//{
//    for (int i = 0; i < 11; i++)
//    {
//        if (hash_stu[i].len != 0)
//        {
//            printf("hash_stu[%d]:\n", i);
//            printf("len:%d\t", hash_stu[i].len);
//            print_hash(hash_stu[i].head);
//        } 
//    }
//}
//
////�ͷ�����
//void free_list(Hash* hash_stu)
//{
//
//}
//
//
////ѧ������˵�
//void menu()
//{
//	/*Hash* tail = NULL;
//	Hash* head = NULL;*/
//    Hash hash_stu[11];
//    //memset(hash_stu,0x00,sizeof(hash_stu));
//    for (int i = 0; i < 11; i++)
//    {
//        hash_stu[i].head = NULL;
//        hash_stu[i].tail = NULL;
//        hash_stu[i].len = 0;
//    }
//	Stu* pnew = NULL;
//	char sel;
//	for (;;)
//	{
//		printf(HASHLIST);
//		scanf_s("%c", &sel, 1);
//		//while (getchar() != '\n');
//		switch (sel)
//		{
//		case '1':
//			//����ѧ����Ϣ
//			insert_stulist(hash_stu);
//            //while (getchar() != '\n');
//			break;
//		case '2':
//			//ɾ��һ��ѧ����Ϣ
//			del_stu_list(hash_stu);
//           // while (getchar() != '\n');
//			break;
//		case '3':
//			//�޸�һ��ѧ����Ϣ
//			modify_stu(hash_stu);
//            //while (getchar() != '\n');
//			break;
//		case '4':
//			//����һ��ѧ����Ϣ
//			serach_stu(hash_stu);
//            //while (getchar() != '\n');
//			break;
//		case '5':
//			//��ʾ����ѧ����Ϣ
//			print_list(hash_stu);
//            while (getchar() != '\n');
//			break;
//		case '6':
//			//�ͷ�����
//			//free_list(hash_stu);
//            //while (getchar() != '\n');
//			break;
//		case '7':
//			printf("лл���ʹ��\n");
//			exit(0);
//		default:
//			printf("�����������\n");
//			break;
//		}
//	}
//}
//
//
//
//

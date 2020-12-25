//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//#include "hashlist.h"
//
////判断所输入的是否合法
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
//            printf("你所输入的学号错误,请重新输入\n");
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
//                        printf("你所输入的id重复\n");
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
//            printf("你所输入的名字过长,请重新输入\n");
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
//            printf("你输入的年龄不符合常理,请重新输入\n");
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
////判断所修改的是否合法
//void check_vlat1(char* name, int age, Stu** pnew, Hash* hash_stu)
//{
//    while (1)///name
//    {
//        printf("please input name:");
//        scanf_s("%s", name, 20);
//        while (getchar() != '\n');
//        if (strlen(name) > 19)
//        {
//            printf("你所输入的名字过长,请重新输入\n");
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
//            printf("你输入的年龄不符合常理,请重新输入\n");
//            continue;
//        }
//        else
//            break;
//    }
//    (*pnew)->age = age;
//    strcpy_s((*pnew)->name, 20, name);
//}
////创建新的节点
//Stu* creat_node(Hash* hash_stu)
//{
//	Stu* pnew = (Stu*)malloc(sizeof(Stu));
//	int age=0;
//	int id=0;
//	char name[20]="";
//	check_vlat(id, name, age, &pnew, hash_stu);//检查和赋值
//	return pnew;
//}
//
//
////增加学生信息
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
////查找一个节点的位置
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
//    if (temp == *head)//头结点
//    {
//        *head = temp->next;
//    }
//    else
//    {
//        Stu* pri = NULL;
//        while (node != NULL)//遍历找出目标节点的前一个节点
//        {
//            if (node->next == temp)
//            {
//                pri=node;
//                break;
//            }  
//            node = node->next;
//        }
//        if (temp == *tail && pri != NULL)//尾节点
//        {
//            *tail = pri;
//            pri->next = NULL;
//        }
//        else if (pri!= NULL)//中间节点
//        {
//            pri->next = temp->next;
//        }
//    }
//    temp->next = NULL;
//    return temp;
//}
//
//
////删除一个学生信息
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
//    printf("删除成功\n");
//}
//
////修改一个学生信息
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
//        check_vlat1(name, age, &node, hash_stu);//检查和赋值
//    }
//    else
//    {
//        printf("查无此人\n");
//        return;
//    }
//}
//
//
////查找一个学生信息
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
//        printf("查无此人\n");
//        return;
//    }
//        
//}
//
////学生信息链表显示
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
////显示所有学生信息
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
////释放链表
//void free_list(Hash* hash_stu)
//{
//
//}
//
//
////学生链表菜单
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
//			//增加学生信息
//			insert_stulist(hash_stu);
//            //while (getchar() != '\n');
//			break;
//		case '2':
//			//删除一个学生信息
//			del_stu_list(hash_stu);
//           // while (getchar() != '\n');
//			break;
//		case '3':
//			//修改一个学生信息
//			modify_stu(hash_stu);
//            //while (getchar() != '\n');
//			break;
//		case '4':
//			//查找一个学生信息
//			serach_stu(hash_stu);
//            //while (getchar() != '\n');
//			break;
//		case '5':
//			//显示所有学生信息
//			print_list(hash_stu);
//            while (getchar() != '\n');
//			break;
//		case '6':
//			//释放链表
//			//free_list(hash_stu);
//            //while (getchar() != '\n');
//			break;
//		case '7':
//			printf("谢谢你的使用\n");
//			exit(0);
//		default:
//			printf("你的输入有误\n");
//			break;
//		}
//	}
//}
//
//
//
//

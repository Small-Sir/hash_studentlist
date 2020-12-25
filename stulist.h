#ifndef _STULIST_H_
#define _STULIST_H_

#define STULIST "\t\t\t1.增加学生信息\n"\
                    "\t\t\t2.删除一个学生信息\n"\
                     "\t\t\t3.修改一个学生信息\n"\
                      "\t\t\t4.查找一个学生信息\n"\
                       "\t\t\t5.显示所有学生信息\n"\
                         "\t\t\t6.释放\n"\
                          "\t\t\t7.退出\n"\
                            "\t\t\t请输入你的选项："




typedef struct Stu
{
    int id;
    char name[20];
    int age;
    struct Stu* next;
}Stu;

void stulist_menu();
//创建新的节点
Stu* creat_node(Stu* L);

//初始化链表
void init_list(Stu** L);

//增加学生信息
void insert_stulist(Stu** L);

//删除一个学生信息
void del_stu_list(Stu** L);

//修改一个学生信息
void modify_stu(Stu** L);

//查找一个学生信息
void  serach_stu(Stu* L);

//显示所有学生信息
void  print_list(Stu* L);

//释放链表
void free_list(Stu** L);

#endif
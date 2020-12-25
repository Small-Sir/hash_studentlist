#ifndef _STULIST_H_
#define _STULIST_H_

#define STULIST "\t\t\t1.����ѧ����Ϣ\n"\
                    "\t\t\t2.ɾ��һ��ѧ����Ϣ\n"\
                     "\t\t\t3.�޸�һ��ѧ����Ϣ\n"\
                      "\t\t\t4.����һ��ѧ����Ϣ\n"\
                       "\t\t\t5.��ʾ����ѧ����Ϣ\n"\
                         "\t\t\t6.�ͷ�\n"\
                          "\t\t\t7.�˳�\n"\
                            "\t\t\t���������ѡ�"




typedef struct Stu
{
    int id;
    char name[20];
    int age;
    struct Stu* next;
}Stu;

void stulist_menu();
//�����µĽڵ�
Stu* creat_node(Stu* L);

//��ʼ������
void init_list(Stu** L);

//����ѧ����Ϣ
void insert_stulist(Stu** L);

//ɾ��һ��ѧ����Ϣ
void del_stu_list(Stu** L);

//�޸�һ��ѧ����Ϣ
void modify_stu(Stu** L);

//����һ��ѧ����Ϣ
void  serach_stu(Stu* L);

//��ʾ����ѧ����Ϣ
void  print_list(Stu* L);

//�ͷ�����
void free_list(Stu** L);

#endif
//#ifndef _HASHLIST_H_
//#define _HASHLIST_H_
//
//#define HASHLIST "\t\t\t1.增加学生信息\n"\
//                    "\t\t\t2.删除一个学生信息\n"\
//                     "\t\t\t3.修改一个学生信息\n"\
//                      "\t\t\t4.查找一个学生信息\n"\
//                       "\t\t\t5.显示所有学生信息\n"\
//                         "\t\t\t6.释放\n"\
//                          "\t\t\t7.退出\n"\
//                            "\t\t\t请输入你的选项："
//                            
//
//
//
//typedef struct Stu
//{
//    int id;
//    char name[20];
//    int age;
//    struct Stu* next;
//}Stu;
//typedef struct Hash
//{
//    Stu* head;
//    Stu* tail;
//    int len;//记录哈希表所存储学生信息的个数的
//}Hash;//定义一个哈希结构体
//
//void menu();
////创建新的节点
//Stu* creat_node(Hash* hash_stu);
//
////增加学生信息
//void insert_stulist(Hash* hash_stu);
//
////删除一个学生信息
//void del_stu_list(Hash* hash_stu);
//
////修改一个学生信息
//void modify_stu(Hash* hash_stu);
//
////查找一个学生信息
//void  serach_stu(Hash* hash_stu);
//
////显示所有学生信息
//void  print_list(Hash* hash_stu);
//
////释放链表
//void free_list(Hash* hash_stu);
//
//#endif
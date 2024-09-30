#include<stdio.h>

typedef struct book {
    char bunm[10];      //图书编号
    char bname[30];     //书名
    char bauthor[20];   //作者
    char bclassfy[10];  //类别编号
    float bprice;       //价格

    struct book *next;  //链表指针
}BookInfo;

BookInfo *CreateBookList();         //创建书单
void InsertBook(BookInfo *head);    //录入图书信息
void DeleteBook(BookInfo *head);    //删除图书信息
void SearchBook(BookInfo *head);    //查找图书信息
void UpdateBook(BookInfo *head);    //修改图书信息
void PrintBook(BookInfo *head);     //浏览图书信息
void SaveBook(BookInfo *head);      //保存图书信息
int bmenu();                        //图书菜单
#include "BookManager.h"

#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;

//创建书单
BookInfo *CreateBookList()
{
    BookInfo *head;
    head = (BookInfo *)malloc(sizeof(BookInfo));        //为头结点分配空间
    head->next = NULL;                                      //初始化头指针
    return head;
}
//录入图书信息
void InsertBook(BookInfo *head)
{
    BookInfo *b, *p;
    char flag = 'Y';
    p = head;
    while (p->next != NULL)
        p = p->next;
    while (flag == 'Y' || flag == 'y')
    {
        b = (BookInfo *)malloc(sizeof(BookInfo));       //开辟新空间
        cout << "请输入图书编号：" ;                           //获取图书信息
        cin >> b->bunm;
        cout << "请输入书名：" ;
        cin >> b->bname;
        cout << "请输入作者：" ;
        cin >> b->bauthor;
        cout << "请输入类别编号：" ;
        cin >> b->bclassfy;
        cout << "请输入价格：" ;
        cin >> b->bprice;
        p->next = b;
        p = b;
        b->next = NULL;
        cout << "是否继续录入？（Y/N）" ;
        cin >> flag;
        if (flag == 'N' || flag == 'n') break;
        else if (flag != 'Y' || flag != 'y') continue;
    }
    return;
}
//删除图书信息
void DeleteBook(BookInfo *head)
{
    BookInfo *b, *p;
    char tmp[30];
    int flag = 0;       //用于判断是否找到了要删除的图书
    b = head;
    p = head;
    cout << "请输入要删除的图书名：" ;
    fflush(stdin);
    cin >> tmp;
    //遍历链表
    while (p != NULL)
    {
        if (strcmp(p->bname, tmp) == 0)
        {
            flag = 1;
            break;
        }
        p = p->next;
    }
    if (flag == 1)
    {
        for(; b->next != p;)
            b = b->next;
        b->next = p->next;
        free(p);
        cout << "删除成功！" << endl;
    }
    else
        cout << "该书不存在！" << endl;
    return;
}
//浏览图书信息
void PrintBook(BookInfo *head)
{
    BookInfo *p;
    if (head == NULL || head->next == NULL)     //判断链表是否为空
    {
        cout << "无记录！" << endl;
        return;
    }
    p = head;
    cout << "|------|---------------------|-----------|----------------|--------------|" <<endl;
    cout << "| 编号  |        书名         |    作者     |   类别编号      |      价格    |" <<endl;
    cout << "|------|---------------------|-----------|----------------|--------------|" <<endl;
    //遍历链表，输出图书信息
    while (p->next != NULL)
    {
        p = p->next;
        cout << "|" << setw(5) << p->bunm << "|" << setw(20) << p->bname << "|" << setw(10) << p->bauthor << "|"
        << setw(15) << p->bclassfy << "|" << setw(10) << p->bprice << "|" << endl;
        cout << "|------|---------------------|-----------|----------------|--------------|" <<endl;
    }
}
//查询图书信息
void SearchBook(BookInfo *head)
{
    BookInfo *p;
    char tmp[30];
    int flag = 0;
    p = head;
    if (head == NULL || head->next == NULL)
        cout << "清单为空！" << endl;
    else {
        cout << "请输入要查询的图书名：" ;
        fflush(stdin);
        cin >> tmp;
        while  (p != NULL)
        {
            p = p->next;
            if (strcmp(p->bname, tmp) == 0)
            {
                flag = 1;       //图书已找到
                cout << "编号：" << p->bunm << endl;
                cout << "书名：" << "《" << p->bname << "》" << endl;
                cout << "作者：" << p->bauthor << endl;
                cout << "类别编号：" << p->bclassfy << endl;
                cout << "价格：" << p->bprice << endl;
                return;
            }
            if (p->next == NULL)
                cout << endl << "查询完毕！";
        }
        if (flag == 0)
            cout << "没有找到《" << tmp << "》！"<< endl;
    }
    return;
}
//修改图书信息
void UpdateBook(BookInfo *head)
{
    BookInfo *p;
    char tmp[30];
    int flag = 0;
    p = head;
    cout << "请输入要修改的图书名：" ;
    fflush(stdin);
    cin >> tmp;
    while  (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->bname, tmp) == 0) {
            flag = 1;
            cout << "请输入编号：" ;
            fflush(stdin);
            cin >> p->bunm;
            cout << "请输入书名：" ;
            fflush(stdin);
            cin >> p->bname;
            cout << "请输入作者：" ;
            fflush(stdin);
            cin >> p->bauthor;
            cout << "请输入类别编号：" ;
            fflush(stdin);
            cin >> p->bclassfy;
            cout << "请输入价格：" ;
            fflush(stdin);
            cin >> p->bprice;
        }
    }
    if (flag == 0)
        cout << "没有找到《" << tmp << "》！"<< endl;
    return;
}
//保存图书信息
void SaveBook(BookInfo *head)
{
    BookInfo *p;
    FILE *fp;
    p = head;
    //以只写的方式打开文件
    fp = fopen("Library-Management-System/booklist.txt", "w");
    fprintf(fp, "|------|---------------------|-----------|----------------|--------------|\n");
    fprintf(fp, "|编号  |        书名         |    作者     |   类别编号      |      价格    |\n");
    fprintf(fp, "|------|---------------------|-----------|----------------|--------------|\n");
    while (p->next != NULL)
    {
        p = p->next;
        fprintf(fp, "|%s|%s|%s|%s|%.2lf|\n", p->bunm, p->bname, p->bauthor, p->bclassfy, p->bprice);
        fprintf(fp, "|------|---------------------|-----------|----------------|--------------|\n");
    }
    fclose(fp);
    cout << "保存成功！" << endl;
    cout << "数据已成功保存到booklist.txt" << endl;
}
//菜单
int bmenu()
{
    int sec;
    cout << "         图书管理系统           " << endl;
    cout << "------------------------------" << endl;
    cout << "      1. 录入图书信息           " << endl;
    cout << "      2. 浏览图书信息           " << endl;
    cout << "      3. 查询图书信息           " << endl;
    cout << "      4. 修改图书信息           " << endl;
    cout << "      5. 删除图书信息           " << endl;
    cout << "      6. 保存图书信息           " << endl;
    cout << "      7. 退出系统              " << endl;
    cout << "------------------------------" << endl;
    cout << "请输入你的选择：";
    fflush(stdin);
    cin >> sec;
    while (sec < 0 || sec > 7)
    {
        cout << "输入有误!\n请重新输入：";
        fflush(stdin);
        cin >> sec;
    }
    return sec;
}

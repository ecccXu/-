#include "BookManager.h"

#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;

//�����鵥
BookInfo *CreateBookList()
{
    BookInfo *head;
    head = (BookInfo *)malloc(sizeof(BookInfo));        //Ϊͷ������ռ�
    head->next = NULL;                                      //��ʼ��ͷָ��
    return head;
}
//¼��ͼ����Ϣ
void InsertBook(BookInfo *head)
{
    BookInfo *b, *p;
    char flag = 'Y';
    p = head;
    while (p->next != NULL)
        p = p->next;
    while (flag == 'Y' || flag == 'y')
    {
        b = (BookInfo *)malloc(sizeof(BookInfo));       //�����¿ռ�
        cout << "������ͼ���ţ�" ;                           //��ȡͼ����Ϣ
        cin >> b->bunm;
        cout << "������������" ;
        cin >> b->bname;
        cout << "���������ߣ�" ;
        cin >> b->bauthor;
        cout << "����������ţ�" ;
        cin >> b->bclassfy;
        cout << "������۸�" ;
        cin >> b->bprice;
        p->next = b;
        p = b;
        b->next = NULL;
        cout << "�Ƿ����¼�룿��Y/N��" ;
        cin >> flag;
        if (flag == 'N' || flag == 'n') break;
        else if (flag != 'Y' || flag != 'y') continue;
    }
    return;
}
//ɾ��ͼ����Ϣ
void DeleteBook(BookInfo *head)
{
    BookInfo *b, *p;
    char tmp[30];
    int flag = 0;       //�����ж��Ƿ��ҵ���Ҫɾ����ͼ��
    b = head;
    p = head;
    cout << "������Ҫɾ����ͼ������" ;
    fflush(stdin);
    cin >> tmp;
    //��������
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
        cout << "ɾ���ɹ���" << endl;
    }
    else
        cout << "���鲻���ڣ�" << endl;
    return;
}
//���ͼ����Ϣ
void PrintBook(BookInfo *head)
{
    BookInfo *p;
    if (head == NULL || head->next == NULL)     //�ж������Ƿ�Ϊ��
    {
        cout << "�޼�¼��" << endl;
        return;
    }
    p = head;
    cout << "|------|---------------------|-----------|----------------|--------------|" <<endl;
    cout << "| ���  |        ����         |    ����     |   �����      |      �۸�    |" <<endl;
    cout << "|------|---------------------|-----------|----------------|--------------|" <<endl;
    //�����������ͼ����Ϣ
    while (p->next != NULL)
    {
        p = p->next;
        cout << "|" << setw(5) << p->bunm << "|" << setw(20) << p->bname << "|" << setw(10) << p->bauthor << "|"
        << setw(15) << p->bclassfy << "|" << setw(10) << p->bprice << "|" << endl;
        cout << "|------|---------------------|-----------|----------------|--------------|" <<endl;
    }
}
//��ѯͼ����Ϣ
void SearchBook(BookInfo *head)
{
    BookInfo *p;
    char tmp[30];
    int flag = 0;
    p = head;
    if (head == NULL || head->next == NULL)
        cout << "�嵥Ϊ�գ�" << endl;
    else {
        cout << "������Ҫ��ѯ��ͼ������" ;
        fflush(stdin);
        cin >> tmp;
        while  (p != NULL)
        {
            p = p->next;
            if (strcmp(p->bname, tmp) == 0)
            {
                flag = 1;       //ͼ�����ҵ�
                cout << "��ţ�" << p->bunm << endl;
                cout << "������" << "��" << p->bname << "��" << endl;
                cout << "���ߣ�" << p->bauthor << endl;
                cout << "����ţ�" << p->bclassfy << endl;
                cout << "�۸�" << p->bprice << endl;
                return;
            }
            if (p->next == NULL)
                cout << endl << "��ѯ��ϣ�";
        }
        if (flag == 0)
            cout << "û���ҵ���" << tmp << "����"<< endl;
    }
    return;
}
//�޸�ͼ����Ϣ
void UpdateBook(BookInfo *head)
{
    BookInfo *p;
    char tmp[30];
    int flag = 0;
    p = head;
    cout << "������Ҫ�޸ĵ�ͼ������" ;
    fflush(stdin);
    cin >> tmp;
    while  (p->next != NULL)
    {
        p = p->next;
        if (strcmp(p->bname, tmp) == 0) {
            flag = 1;
            cout << "�������ţ�" ;
            fflush(stdin);
            cin >> p->bunm;
            cout << "������������" ;
            fflush(stdin);
            cin >> p->bname;
            cout << "���������ߣ�" ;
            fflush(stdin);
            cin >> p->bauthor;
            cout << "����������ţ�" ;
            fflush(stdin);
            cin >> p->bclassfy;
            cout << "������۸�" ;
            fflush(stdin);
            cin >> p->bprice;
        }
    }
    if (flag == 0)
        cout << "û���ҵ���" << tmp << "����"<< endl;
    return;
}
//����ͼ����Ϣ
void SaveBook(BookInfo *head)
{
    BookInfo *p;
    FILE *fp;
    p = head;
    //��ֻд�ķ�ʽ���ļ�
    fp = fopen("Library-Management-System/booklist.txt", "w");
    fprintf(fp, "|------|---------------------|-----------|----------------|--------------|\n");
    fprintf(fp, "|���  |        ����         |    ����     |   �����      |      �۸�    |\n");
    fprintf(fp, "|------|---------------------|-----------|----------------|--------------|\n");
    while (p->next != NULL)
    {
        p = p->next;
        fprintf(fp, "|%s|%s|%s|%s|%.2lf|\n", p->bunm, p->bname, p->bauthor, p->bclassfy, p->bprice);
        fprintf(fp, "|------|---------------------|-----------|----------------|--------------|\n");
    }
    fclose(fp);
    cout << "����ɹ���" << endl;
    cout << "�����ѳɹ����浽booklist.txt" << endl;
}
//�˵�
int bmenu()
{
    int sec;
    cout << "         ͼ�����ϵͳ           " << endl;
    cout << "------------------------------" << endl;
    cout << "      1. ¼��ͼ����Ϣ           " << endl;
    cout << "      2. ���ͼ����Ϣ           " << endl;
    cout << "      3. ��ѯͼ����Ϣ           " << endl;
    cout << "      4. �޸�ͼ����Ϣ           " << endl;
    cout << "      5. ɾ��ͼ����Ϣ           " << endl;
    cout << "      6. ����ͼ����Ϣ           " << endl;
    cout << "      7. �˳�ϵͳ              " << endl;
    cout << "------------------------------" << endl;
    cout << "���������ѡ��";
    fflush(stdin);
    cin >> sec;
    while (sec < 0 || sec > 7)
    {
        cout << "��������!\n���������룺";
        fflush(stdin);
        cin >> sec;
    }
    return sec;
}

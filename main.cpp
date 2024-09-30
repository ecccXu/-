#include "BookManager.h"
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    BookInfo *head;
    int sel;
    head = NULL;
    for(;;) {
        sel = bmenu();      //输出菜单，并获取选择的编号
        switch(sel) {
            case 1:
                if(head == NULL)
                    head = CreateBookList();
                    InsertBook(head);
                break;
            case 2:PrintBook(head);break;
            case 3:SearchBook(head);break;
            case 4:UpdateBook(head);break;
            case 5:DeleteBook(head);break;
            case 6:SaveBook(head);break;
            case 7:exit(0);break;
            default:cout<<"输入错误，请重新输入！"<<endl;
        }
    }
    return 0;
}

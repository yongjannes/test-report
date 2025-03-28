#ifndef MENU_H
#define MENU_H
#include <vector>
#include "Member.h"
class Menu
{
public:
    void displayTeacherMenu(); // 显示教师菜单
    void displayStudentMenu(); // 显示学生菜单

    void addContact(); // 添加联系人
    void deleteContact(); // 删除联系人
    void searchContact(); // 搜索联系人
    void displayAllContacts(); // 显示所有联系人
    void modify(); // 修改联系人信息

    void viewOwnInfo(); // 查看个人信息

     void sortById();
private:
    string newName; // 新姓名
    string newGender; // 新性别
    string newAge; // 新年龄
    string newPhone; // 新电话号码
    string newAddress; // 新地址
};

#endif // MENU_H

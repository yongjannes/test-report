#include "Login.h"
#include "User.h"
#include "Menu.h"
#include <iostream>
#include <limits>
using namespace std;
// 构造函数，初始化失败尝试次数为0
Login::Login() : failedAttempts(0){}
// login()函数，用于验证用户输入的用户名和密码是否正确
void Login::login(const User& user)
{

    string username;
    string password;

    cout << "请输入用户名: ";
    cin>>username;

    cout << "请输入密码: ";
    cin>>password;


    if (username == user.username && password == user.password)
    {
       // 登录成功，显示对应用户的菜单
        displayMenu(user);
    }
    else
    {
        // 登录失败，增加失败次数，并检查是否超过三次
        failedAttempts++;
        if (failedAttempts >= 3)
        {
            cout << "登录失败次数超过三次，系统退出"<<endl;
            exit(0);
            // 退出系统
        }
        else
        {
            cout  << "用户名或密码不正确，请重新输入"<<endl;
            cout << "请选择操作（1.重新登录 2.退出系统）：";
            int choice;
            cin >> choice;
            // 重新登录
            if (choice == 1)
            {
                login(user);
            }
            else if (choice == 2)
            {
                exit(0);
            }
        }
    }
}
void Login::displayMenu(const User& user)
{
    // 根据用户类别显示对应菜单
    Menu a;
    if (typeid(user) == typeid(TeacherUser))
    {
        cout<<endl;
        cout << "教师登录成功" << endl;
        cout<<endl;
        cout << "欢迎教师" <<user.username<< endl;
        a.displayTeacherMenu();
    }
    else if (typeid(user) == typeid(StudentUser))
    {
        cout<<endl;
        cout << "学生登录成功" << endl;
        cout<<endl;
        cout << "欢迎学生"<<user.username << endl;
        a.displayStudentMenu();
    }

}

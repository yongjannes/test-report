#include <iostream>
#include "Member.h"
#include "ContactBook.h"
#include "Menu.h"
#include "Login.h"
#include <User.h>
#include <vector>
#include <string>
using namespace std;

int main()
{

    // 创建登录模块实例
    Login loginModule;

// 创建教师用户和学生用户实例
    TeacherUser teacherUser("admin", "123");
    StudentUser studentUser("jy", "123");

    int userType;
    cout << "请输入用户类型（1.教师 2.学生 3.退出）：";
    cin >> userType;

// 根据用户类型执行相应的登录操作
    if (userType == 1)
    {
        // 如果是教师用户，调用登录模块的login方法进行登录
        loginModule.login(teacherUser);
    }
    else if (userType == 2)
    {
        // 如果是学生用户，调用登录模块的login方法进行登录
        loginModule.login(studentUser);
    }
    else if (userType == 3)
    {
        // 如果用户选择退出，直接返回0结束程序
        return 0;
    }
    else
    {
        // 如果用户输入无效的用户类型，输出错误提示信息
        cout << "无效的用户类型！" << endl;
    }




    return 0;
}

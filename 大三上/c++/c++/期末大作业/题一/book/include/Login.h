#ifndef LOGIN_H
#define LOGIN_H
#include "User.h"
class Login
{
public:

    // 构造函数
    Login();
    // 用户登录函数
    void login(const User& user);
    // 显示菜单函数
    void displayMenu(const User& user);
private:
    // 记录失败尝试次数的变量
    int failedAttempts;
};

#endif // LOGIN_H

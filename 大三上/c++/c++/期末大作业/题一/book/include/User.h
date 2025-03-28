#ifndef USER _H
#define USER _H
#include <string>
using namespace std;
class User
{
public:
    // 构造函数，接受用户名和密码作为参数
    User(const string& username,const string& password);
    // 虚析构函数，确保派生类的析构函数被正确调用
    virtual ~User() {};
     // 纯虚函数，用于判断用户是否有效
    virtual bool isValid() const = 0;
   // 成员变量，存储用户名和密码
    string username;
    string password;
};
class TeacherUser : public User
{
public:
    // 构造函数，接受用户名和密码作为参数
    TeacherUser(const string& username, const string& password);
    // 重写基类的isValid函数，判断教师用户是否有效
    bool isValid() const override
    {
        return (username == "admin" && password == "123");
    }
};
class StudentUser : public User
{
public:
     // 构造函数，接受用户名和密码作为参数
    StudentUser(const string& username, const string& password);
    // 重写基类的isValid函数，判断学生用户是否有效
    bool isValid() const override
    {
        return (username == "jy" && password == "123");
    }
};
#endif // USER _H

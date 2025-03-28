#ifndef MEMBER_H
#define MEMBER_H
#include <string>
using namespace std;

class Member
{
public:
   Member(string id, string name, string gender, string getAge, string phone, string getAddress);
    // 构造函数，用于初始化对象的成员变量

    string getId() const; // 获取成员变量id的值的常量成员函数
    string getName() const; // 获取成员变量name的值的常量成员函数
    string getGender() const; // 获取成员变量gender的值的常量成员函数
    string getAge() const; // 获取成员变量age的值的常量成员函数
    string getPhone() const; // 获取成员变量phone的值的常量成员函数
    string getAddress() const; // 获取成员变量address的值的常量成员函数

    void setName(const string& newName); // 设置成员变量name的值的非常量成员函数
    void setGender(const string& newGender); // 设置成员变量gender的值的非常量成员函数
    void setAge(const string& newAge); // 设置成员变量age的值的非常量成员函数
    void setPhone(const string& newPhone); // 设置成员变量phone的值的非常量成员函数
    void setAddress(const string& newAddress); // 设置成员变量address的值的非常量成员函数

    string id;//学号
    string name;//姓名
    string gender;//性别
    string age;//年龄
    string phone;//电话
    string address;//地址
};

#endif // MEMBER_H

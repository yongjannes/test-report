#include "Member.h"
#include <iostream>
using namespace std;
// 构造函数，用于初始化对象的成员变量
Member::Member(string id, string name, string gender, string age,string phone,string address)
    : id(id), name(name), gender(gender), age(age),phone(phone),address(address) {}
string Member::getId() const   // 获取成员变量 id 的值
{
    return id;
}
string Member::getName() const   // 获取成员变量 name 的值
{
    return name;
}
string Member::getGender() const    // 获取成员变量 gender 的值
{
    return gender;
}
string Member::getAge() const     // 获取成员变量 age 的值
{
    return age;
}
string Member::getPhone() const  // 获取成员变量 phone 的值
{
    return phone;
}
string Member::getAddress() const   // 获取成员变量 address 的值
{
    return address;
}

void Member::setName(const string& newName)  // 设置成员变量 name 的值
{
    name = newName;
}
void Member::setGender(const string& newGender)   // 设置成员变量 gender 的值
{
    gender = newGender;
}
void Member::setAge(const string& newAge)    // 设置成员变量 age 的值
{
    age = newAge;
}
void Member::setPhone(const string& newPhone)   // 设置成员变量 phone 的值
{
    phone = newPhone;
}
void Member::setAddress(const string& newAddress)  // 设置成员变量 address 的值
{
    address = newAddress;
}

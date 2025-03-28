#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H
#include <vector>
#include "Member.h"
class ContactBook
{
public:
    // 构造函数，用于初始化ContactBook对象
    ContactBook();
     // 添加一个成员到联系人列表中
    vector<Member> addMember(const Member& member);
     // 显示所有成员的信息
    void displayMembers() const;
    // 获取所有成员的列表
    vector<Member> getAllMembers() const;
    // 存储所有成员的列表
    vector<Member> members;


    // 根据ID删除数据
    bool deleteMemberByIdAndField(const string& id, const string& field);
    // 根据姓名搜索成员
    vector<Member> searchMembers(const string& keyword);
    // 根据ID查找成员
    Member* findMemberById(const string& id);
    // 检查ID是否唯一
    bool checkIdUnique(const string& id);
      // 检查年龄是否有效
    bool isValidAge(const string& age);
     // 检查性别是否有效
    bool isValidGender(const string& gender);
      // 检查电话号码是否有效
    bool isValidPhoneNumber(const string& phoneNumber);

    void sortById();
};

#endif // CONTACTBOOK_H

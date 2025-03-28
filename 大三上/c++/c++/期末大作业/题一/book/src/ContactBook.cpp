#include "ContactBook.h"
#include <iostream>
#include <regex>
// 添加一个成员到联系人列表中
vector<Member> ContactBook::addMember(const Member& member)
{
    members.push_back(member);// 将传入的成员对象添加到成员列表中
    return members;// 返回更新后的成员列表
}
// 构造函数，初始化联系人簿并添加默认成员
ContactBook::ContactBook()
{
    Member member1("16", "姜勇", "男", "22", "18309491407", "陇南");
    Member member2("37", "魏晋勇", "女", "22", "987654321", "皋兰");
    Member member3("003", "王五", "男", "30", "456123789", "广州");
    Member member4("27", "孙立洋", "女", "22", "11011011011", "白银");

    addMember(member1); // 添加第一个成员
    addMember(member2); // 添加第二个成员
    addMember(member3); // 添加第三个成员
    addMember(member4); // 添加第四个成员
}
// 显示所有联系人的信息
void ContactBook::displayMembers() const
{

    cout << "学号\t姓名\t性别\t年龄\t电话号码\t地址" << endl;
    for (const auto& member : members)  // 遍历成员列表
    {
        cout  <<member.getId() << "\t" << member.getName() << "\t" << member.getGender() << "\t"<< member.getAge() << "\t" << member.getPhone()<< "\t" << member.getAddress()  << endl;
    }// 输出每个成员的信息
}
// 获取所有联系人的列表
vector<Member> ContactBook::getAllMembers() const
{
    return members;// 返回成员列表
}
// 根据学号删除联系人信息
bool ContactBook::deleteMemberByIdAndField(const string& id, const string& field)
{
     for (size_t i = 0; i < members.size(); ++i)   // 遍历成员列表
    {
        if (members[i].id == id)   // 如果找到匹配的学号
        {
            // 删除对应的姓名、性别等信息
            if (field == "name")
                members[i].name = "";
            else if (field == "gender")
                members[i].gender = "";
            else if (field == "age")
                members[i].age = "";
            else if (field == "phone")
                members[i].phone = "";
            else if (field == "address")
                members[i].address = "";

            return true; // 删除成功，返回true
        }
    }
    return false; // 未找到匹配的学号，返回false
}
// 根据姓名搜索联系人
vector<Member> ContactBook::searchMembers(const string& keyword)
{
    vector<Member> foundMembers; // 存储搜索结果的列表

for (const auto& member : members)   // 遍历成员列表
{
    if (member.getName() == keyword)
    {
        foundMembers.push_back(member); // 将该成员添加到搜索结果列表中
    }
}

    return foundMembers; // 返回搜索结果列表
}
// 根据学号查找联系人
Member* ContactBook::findMemberById(const string& id)
{
    for (auto& member : members)   // 遍历成员列表
    {
        if (member.getId() == id)   // 如果找到匹配的学号
        {
            return &member; // 返回该成员的指针
        }
    }
    return nullptr; // 未找到匹配的学号，返回null指针
}

// 检查学号是否唯一
bool ContactBook::checkIdUnique(const string& id)
{
    for (const auto& member : members)   // 遍历成员列表
    {
        if (member.getId() == id)   // 如果找到匹配的学号
        {
            return false; // 学号已存在，返回false
        }
    }
    return true; // 学号唯一，返回true
}
// 检查年龄是否合法
bool ContactBook::isValidAge(const string& age)
{
    for (char c : age)   // 遍历年龄字符串中的每个字符
    {
        if (!isdigit(c))   // 如果字符不是数字
        {
            return false; // 年龄不合法，返回false
        }
    }
    // 如果循环结束都没有发现非数字字符，则认为是合法的年龄
    int ageValue = stoi(age); // 将年龄字符串转换为整数
    // 假设合法的年龄范围是 1 到 25 岁
    if (ageValue < 18 || ageValue > 25)
    {
        return false; // 年龄超出合法范围，返回false
    }
    return true; // 年龄合法，返回true
}


// 检查性别是否合法
bool ContactBook::isValidGender(const string& gender)
{
    return (gender == "男" || gender == "女"); // 如果性别是"男"或"女"，则认为是合法的，返回true；否则返回false
}
// 检查电话号码格式是否合法
bool ContactBook::isValidPhoneNumber(const string& phoneNumber)
{
    // 用正则表达式来验证电话号码格式
    // 这里使用了简单的正则表达式来匹配11位数字的手机号码
    regex pattern("1[3-9]\\d{9}");
    // 使用regex_match函数进行匹配
    if (regex_match(phoneNumber, pattern))   // 如果匹配成功，说明电话号码格式正确，返回true
    {
        return true;
    }
    else     // 如果匹配失败，说明电话号码格式不正确，返回false
    {
        return false;
    }
}
void ContactBook::sortById()
{
    sort(members.begin(), members.end(), [](const Member &a, const Member &b)
    {
        return a.id < b.id;
    });
}

#include "Menu.h"
#include <iostream>
#include "Member.h"
#include "ContactBook.h"
using namespace std;
// 创建一个全局的通讯录对象，用于存储和管理联系人信息
ContactBook contactBook;
void Menu::displayTeacherMenu()
{
    cout<<endl;
    int choice = 0;// 初始化选项变量
    // 使用while循环保持菜单显示，直到用户选择退出（选项6）
    while (choice != 7)
    {
        // 显示菜单选项
        cout << "======== 教师通讯录菜单 ========" << endl;
        cout << "1. 添加联系人" << endl;
        cout << "2. 删除联系人" << endl;
        cout << "3. 查找联系人" << endl;
        cout << "4. 显示所有联系人" << endl;
        cout << "5. 修改信息" << endl;
        cout << "6. 按学号排序" << endl;
        cout << "7. 退出" << endl;
        cout<<endl;
        // 提示用户输入选项，并读取输入
        cout << "请输入选项：";
        cin >> choice;
        // 使用switch语句处理用户的选择
        switch (choice)
        {
        case 1:// 添加联系人
            addContact();// 调用添加联系人的函数
            break;
        case 2:// 删除联系人
            deleteContact();
            break;
        case 3: // 查找联系人
            searchContact();
            break;
        case 4:// 显示所有联系人
            cout << "======== 通讯录名单 ========" << endl;
            displayAllContacts();

            break;
        case 5:// 修改信息
            modify();
            break;
        case 6:// 用户可以按照学号对数据进行排序。
            contactBook.sortById();
            cout << "======== 按学号排序后的通讯录名单 ========" << endl;
            displayAllContacts();
            break;
        case 7: // 退出菜单
            cout << "已退出教师菜单。" << endl;
            return;// 结束函数执行，退出菜单
            break;
        default:
            cout << "无效选项，请重新选择" << endl;
            break;
        }
        cout<<endl;
    }
}
void Menu::displayStudentMenu()
{
    cout<<endl;
     // 初始化一个整数变量choice为0，用于存储用户的选择
    int choice = 0;
  // 使用while循环来保持菜单的显示，直到用户选择退出（选项4）
    while (choice != 5)
    {
            // 输出菜单选项
        cout << "======== 学生通讯录菜单 ========" << endl;
        cout << "1. 查看自己的信息" << endl;
        cout << "2. 查找联系人" << endl;
        cout << "3. 显示所有联系人" << endl;
        cout << "4. 按学号排序" << endl;
        cout << "5. 退出" << endl;
        cout << "请选择操作：";
        // 从用户处接收输入并存储在choice变量中
        cin >> choice;
         // 使用switch语句根据用户的选择执行相应的操作
        switch(choice)
        {
        case 1:
        {
            viewOwnInfo();
            break;
        }
        case 2:
        {
            searchContact();
            break;
        }
        case 3:
        {
            cout << "======== 通讯录名单 ========" << endl;
            displayAllContacts();
            break;
        }
        case 4:
        {
            contactBook.sortById();
            cout << "======== 按学号排序后的通讯录名单 ========" << endl;
            displayAllContacts();
            break;
        }
        case 5:
        {
            cout << "已退出学生菜单。" << endl;
            return;
        }
        default:
            cout << "无效的选择，请重新选择。" << endl;
            break;
        }
    }
}
void Menu::addContact()
{
    // 添加联系人的实现
    cout << "======== 添加联系人 ========" << endl;
    string id;
       // 使用do-while循环，确保输入的学号是唯一的
    do
    {
        cout << "请输入学号：";
        cin >> id;
            // 检查输入的学号是否已经存在于联系人列表中
        if (!contactBook.checkIdUnique(id))
        {
               // 如果学号已存在，向用户显示错误消息，并提示他们输入一个新的学号
            cout << "学号已经存在，请输入一个新的学号" << endl;
        }
    }
    while (!contactBook.checkIdUnique(id));// 继续循环直到学号是唯一的

    string name;
    cout << "请输入姓名：";
    cin >> name;
    string gender;
    do
    {
        cout << "请输入性别：";
        cin >> gender;

        if (!contactBook.isValidGender(gender))
        {
            cout << "性别输入不合法，请重新输入" << endl;
        }
    }
    while (!contactBook.isValidGender(gender));
    string age;
    do
    {
        cout << "请输入年龄：";
        cin >> age;

        if (!contactBook.isValidAge(age))
        {
            cout << "年龄范围不正确，请重新输入" << endl;
        }
    }
    while (!contactBook.isValidAge(age));
    string phone;
    do
    {
        cout << "请输入电话：";
        cin >> phone;

        if (!contactBook.isValidPhoneNumber(phone))
        {
            cout << "电话号码格式不正确，请重新输入" << endl;
        }
    }
    while (!contactBook.isValidPhoneNumber(phone));
    string address;
    cout << "请输入地址：";
    cin >> address;
    cout<<endl;
    Member member(id, name, gender,age,phone, address);

    vector<Member> updatedMembers = contactBook.addMember(member);

}

void Menu::deleteContact()
{
    // 删除联系人的实现
    cout << "======== 删除联系人 ========" << endl;
    string id, field;
    cout << "请输入要删除的学号：";
    cin >> id;
    cout << "请输入要删除的字段（name、gender、age、phone、adress）：";
    cin >> field;

    bool success = contactBook.deleteMemberByIdAndField(id, field);

    if (success)
    {
        cout << "成功删除学号为 " << id << " 的联系人的 " << field << " 字段" << endl;
    }
    else
    {
        cout << "未找到学号为 " << id << " 的联系人或该字段不存在" << endl;
    }
}

void Menu::searchContact()
{
    // 查找联系人的实现
    cout << "======== 查找联系人 ========" << endl;
    string keyword;
    cout << "请输入要查找的姓名：";
    cin >> keyword;
    cout<<endl;

    vector<Member> foundMembers = contactBook.searchMembers(keyword);

    if (foundMembers.empty())
    {
        cout << "未找到符合条件的联系人" << endl;
    }
    else
    {
        cout << "找到以下符合条件的联系人：" << endl;
        cout << "学号\t姓名\t性别\t年龄\t电话号码\t地址" << endl;
        for (const auto& member : foundMembers)
        {
            cout << member.getId() << "\t" << member.getName() << "\t" << member.getGender() << "\t" << member.getAge() << "\t" << member.getPhone() << "\t" << member.getAddress() << endl;
        }
    }
}

void Menu::displayAllContacts()
{
    // 显示所有联系人的实现
    vector<Member> members = contactBook.getAllMembers();


    cout << "学号\t姓名\t性别\t年龄\t电话号码\t地址" << endl;
    for (const auto& member : members)
    {
        cout << member.getId() << "\t" << member.getName() << "\t" << member.getGender() << "\t"<< member.getAge() << "\t" << member.getPhone()<< "\t" << member.getAddress()  << endl;
        cout << endl;
    }
}

void Menu::modify()
{
    // 修改联系人的实现
    cout << "======== 修改联系人信息 ========" << endl;
    string id;
    cout << "请输入要修改的学号：";
    cin >> id;

    Member* member = contactBook.findMemberById(id);
    if (member != nullptr)
    {
        cout << "请选择要修改的项：" << endl;
        cout << "1. 姓名" << endl;
        cout << "2. 性别" << endl;
        cout << "3. 年龄" << endl;
        cout << "4. 电话号码" << endl;
        cout << "5. 地址" << endl;

        int choice;
        cout << "请输入选择的序号：";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "请输入新的姓名：";
            cin >> newName;
            member->setName(newName);
            break;
        case 2:
            do
            {
                cout << "请输入新的性别（男/女）：";
                cin >> newGender;

                if (!contactBook.isValidGender(newGender))
                {
                    cout << "性别输入不合法，请重新输入" << endl;
                }
            }
            while (!contactBook.isValidGender(newGender));

            member->setGender(newGender);
            break;
        case 3:
            do
            {
                cout << "请输入新的年龄：";
                cin >> newAge;

                if (!contactBook.isValidAge(newAge))
                {
                    cout << "年龄范围不正确，请重新输入" << endl;
                }
            }
            while (!contactBook.isValidAge(newAge));
            member->setAge(newAge);
            break;
        case 4:
            do
            {
                cout << "请输入新的电话：";
                cin >> newPhone;

                if (!contactBook.isValidPhoneNumber(newPhone))
                {
                    cout << "电话号码格式不正确，请重新输入" << endl;
                }
            }
            while (!contactBook.isValidPhoneNumber(newPhone));
            member->setPhone(newPhone);
            break;
        case 5:
            cout << "请输入新的地址：";
            cin >> newAddress;
            member->setAddress(newAddress);
            break;
        default:
            cout << "无效选择" << endl;
            break;
        }

        cout << "联系人信息修改成功！" << endl;
    }
    else
    {
        cout << "未找到学号为 " << id << " 的联系人" << endl;
    }
}
void Menu::viewOwnInfo()
{
// 查看自己的信息的实现
    cout << "======== 自己的信息 ========" << endl;
    string id;
    cout << "请输入学号：";
    cin >> id;

    Member* member = contactBook.findMemberById(id);
    if (member != nullptr)
    {
        cout << "学号：" << member->getId() << endl;
        cout << "姓名：" << member->getName() << endl;
        cout << "性别：" << member->getGender() << endl;
        cout << "年龄：" << member->getAge() << endl;
        cout << "电话号码：" << member->getPhone() << endl;
        cout << "地址：" << member->getAddress() << endl;
    }
    else
    {
        cout << "未找到学号为 " << id << " 的联系人" << endl;
    }
}

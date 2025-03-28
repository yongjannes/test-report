#ifndef USER _H
#define USER _H
#include <string>
using namespace std;
class User
{
    public:
         User(const string& username,const string& password);

    virtual ~User() {}

    virtual bool isValid() const = 0;


        string username;
        string password;
};
class TeacherUser : public User {
public:
    TeacherUser(const string& username, const string& password);

    bool isValid() const override {
        return (username == "admin" && password == "admin123");
    }
};
class StudentUser : public User {
public:
    StudentUser(const string& username, const string& password);

    bool isValid() const override {
        return (username == "user" && password == "user123");
    }
};
#endif // USER _H

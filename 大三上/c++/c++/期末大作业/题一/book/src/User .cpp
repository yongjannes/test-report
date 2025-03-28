#include "User .h"
User::User(const string& username, const string& password)
        : username(username), password(password){}


TeacherUser::TeacherUser(const string& username, const string& password)
        : User(username, password) {}
StudentUser::StudentUser(const string& username, const string& password)
        : User(username, password) {}

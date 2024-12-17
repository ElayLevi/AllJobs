//
// Created by איליי on 14/12/2024.
//


#ifndef USER_H
#define USER_H
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

class User {
protected:
    string first_name;
    string last_name;
    string id;
    string password;
    string email;
public:
    User( string first_name, string last_name,string id, string password, string email);
    bool login(const string &input_id, const string &input_password) const;
    string getId() const { return id; }
    string getPassword() const { return password; }
    string getEmail() const { return email; }
    string getFirstName() const { return first_name; }
    string getLastName() const { return last_name; }
    void setId(const string& new_id) { id = new_id; }
    void setPassword(const string& new_password) { password = new_password; }
    void setEmail(const string& new_email) { email = new_email; }
    void setFirstName(const string& new_first_name) { first_name = new_first_name; }
    void setLastName(const string& new_last_name) { last_name = new_last_name; }

};

#endif //ALLOJBSV2_USER_H

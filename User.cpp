//
// Created by איליי on 14/12/2024.
//

#include "User.h"
#ifndef USER_H
#define USER_H
#endif // USER_H
#include <iostream>

User::User(string  first_name, string last_name,string id, string password, string email){
    this->first_name=first_name;
    this->last_name=last_name;
    this->id=id;
    this->password=password;
    this->email=email;

}


bool User::login(const string &input_id, const string &input_password) const {
    return (id == input_id && password == input_password);
}


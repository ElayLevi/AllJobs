
#ifndef ALLOJBSV2_EMPLOYER_H
#define ALLOJBSV2_EMPLOYER_H

#include "User.h"
#include "Jobs.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class Employer : public User {
private:
    vector<Jobs> posted_jobs;

public:
    Employer(string first_name, string last_name, string id, string password, string email);

    // Save and Load
    void savetofile(const string &filename) const;
    static vector<Employer> loadfromfile(const string &filename);

    // Job Management
    void add_job(Jobs job, const string &filename);
    void delete_job(const string &jobUID, const string &filename);
    void display_jobs() const;
    void update_job(const string &jobUID, const Jobs &updated_job, const string &filename);

    // Display Details
    void display_details() const;
};

#endif
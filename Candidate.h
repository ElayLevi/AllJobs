
#ifndef ALLOJBSV2_CANDIDATE_H
#define ALLOJBSV2_CANDIDATE_H

#include "User.h"
#include "Jobs.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class Candidate : public User {
private:
    string resume;
    string phone_number;
    string job_type;
    vector<Jobs> favorites;
    vector<string> submissions;

public:
    Candidate(string first_name, string last_name, string id, string password, string email,
              string resume, string phone_number, string job_type);

    // Save and Load
    void savetofile(const string &filename) const;
    static vector<Candidate> loadfromfile(const string &filename);

    // Favorites
    void add_to_favorites(const Jobs &job);
    void display_favorites() const;

    // Submission History
    void add_submission(const string &job_title);
    void display_submission_history() const;
    void remove_submission(const string &job_title);

    // Account Management
    void remove_account(const string &filename, const string &user_id);

    // Getters
    string getResume() const { return resume; }
    string getPhoneNumber() const { return phone_number; }
    string getJobType() const { return job_type; }

    // Display Details
    void display_details() const;
};

#endif

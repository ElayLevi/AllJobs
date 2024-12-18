#include "Candidate.h"
#include "Jobs.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Candidate::Candidate(string first_name, string last_name, string id, string password, string email,
                     string resume, string phone_number, string job_type)
        : User(first_name, last_name, id, password, email), resume(resume), phone_number(phone_number), job_type(job_type) {}

// Save to file
void Candidate::savetofile(const string &filename) const {
    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        cerr << "Error: Could not open file for writing.\n";
        return;
    }
    outfile << first_name << "," << last_name << "," << id << "," << password << ","
            << email << "," << resume << "," << phone_number << "," << job_type << "\n";
    outfile.close();
}

// Load from file
vector<Candidate> Candidate::loadfromfile(const string &filename) {
    vector<Candidate> candidates;
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error: Could not open file for reading.\n";
        return candidates;
    }
    string line, first_name, last_name, id, password, email, resume, phone_number, job_type;
    while (getline(infile, line)) {
        stringstream ss(line);
        getline(ss, first_name, ',');
        getline(ss, last_name, ',');
        getline(ss, id, ',');
        getline(ss, password, ',');
        getline(ss, email, ',');
        getline(ss, resume, ',');
        getline(ss, phone_number, ',');
        getline(ss, job_type, ',');
        candidates.emplace_back(first_name, last_name, id, password, email, resume, phone_number, job_type);
    }
    infile.close();
    return candidates;
}

// Add to favorites
void Candidate::add_to_favorites(const Jobs &job) {
    favorites.push_back(job);
    cout << "Job added to favorites.\n";
}

// Display favorites
void Candidate::display_favorites() const {
    if (favorites.empty()) {
        cout << "No favorite jobs found.\n";
        return;
    }
    cout << "Favorite Jobs:\n";
    for (const auto &job : favorites) {
        job.display_details();
    }
}

void Candidate::add_submission(const string &job_title) {
    submissions.push_back(job_title);
    cout << "Submission added for job: " << job_title << "\n";
}

// Display submission history
void Candidate::display_submission_history() const {
    if (submissions.empty()) {
        cout << "No submissions found.\n";
        return;
    }
    cout << "Submission History:\n";
    for (const auto &submission : submissions) {
        cout << "- " << submission << "\n";
    }
}

// Remove submission manually
void Candidate::remove_submission(const string &job_title) {
    bool found = false;
    vector<string> updated_submissions;
    for (const auto &submission : submissions) {
        if (submission == job_title) {
            found = true;
        } else {
            updated_submissions.push_back(submission);
        }
    }
    if (found) {
        submissions = updated_submissions;
        cout << "Submission for job '" << job_title << "' has been removed.\n";
    } else {
        cout << "Job submission not found.\n";
    }
}
void Candidate::remove_account(const string &filename, const string &user_id) {
    vector<Candidate> candidates = loadfromfile(filename);
    ofstream outfile(filename, ios::trunc);
    if (!outfile.is_open()) {
        cerr << "Error: Could not open file for writing.\n";
        return;
    }
    for (const auto &candidate : candidates) {
        if (candidate.getId() != user_id) {
            candidate.savetofile(filename);
        }
    }
    outfile.close();
    cout << "Account with ID '" << user_id << "' has been removed.\n";
}

// Display candidate details
void Candidate::display_details() const {
    cout << "Candidate Details:\n";
    cout << "Name: " << first_name << " " << last_name << "\n"
         << "ID: " << id << "\n"
         << "Email: " << email << "\n"
         << "Phone Number: " << phone_number << "\n"
         << "Resume: " << resume << "\n"
         << "Job Type: " << job_type << "\n";
}

// edit profile
void Candidate::edit_profile(Candidate &candidate) {
    int choice;
    bool run = true;
    while (run) {
        cout << "Manage profile menu:" << endl;
        cout << "1. Change my first name:" << endl;
        cout << "2. Change my last name:" << endl;
        cout << "3. Change my email address:" << endl;
        cout << "4. Change my phone number:" << endl;
        cout << "5. Display my profile's details:" << endl;
        cout << "6.Exit." << endl;
        cout << "Please choose an option:" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter the new first name :";
                string new_first_name;
                cin >> new_first_name;
                candidate.setFirstName(new_first_name);
                cout << "First name updated successfully!";
                break;
            }
            case 2: {
                cout << "Enter the new last name : ";
                string new_last_name;
                cin >> new_last_name;
                candidate.setLastName(new_last_name);
                cout << "Last name updated successfully!";
                break;
            }
            case 3: {
                cout << "Enter the new email:";
                string new_email;
                cin >> new_email;
                candidate.setEmail(new_email);
                cout << "Email updated successfully!";
                break;
            }
            case 4: {
                cout << "Enter the new phone number:";
                string new_phone_number;
                cin >> new_phone_number;
                candidate.setPhoneNumber(new_phone_number);
                cout << "Phone number updated successfully!";
                break;
            }
            case 5: {
                candidate.display_details();
                break;
            }
            case 6:
                cout << "Goodbye!" << endl;
                run = false;
                break;
            default:
                cout << "invalid option , please try again.";
        }
    }
}


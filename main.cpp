#include <iostream>
#include "Candidate.h"
#include "Employer.h"
#include "Jobs.h"
#include <vector>
#include <limits>

#define CANDIDATE_FILE "candidates.txt"
#define EMPLOYER_FILE "employers.txt"
#define JOB_FILE "jobs.txt"

using namespace std;
// Function Declarations
void candidate_menu(vector<Candidate> &candidates, vector<Jobs> &jobs);

void employer_menu(vector<Employer> &employers, vector<Jobs> &jobs);

void display_main_menu();

// Main Program
int main() {
    vector<Candidate> candidates = Candidate::loadfromfile(CANDIDATE_FILE);
    vector<Employer> employers = Employer::loadfromfile(EMPLOYER_FILE);
    vector<Jobs> jobs = Jobs::loadfromfile(JOB_FILE);

    int choice;
    do {
        display_main_menu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
            case 1:
                candidate_menu(candidates, jobs);
                break;
            case 2:
                employer_menu(employers, jobs);
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

// Display Main Menu
void display_main_menu() {
    cout << "\n======== Job Management System ========\n";
    cout << "1. Candidate Menu\n";
    cout << "2. Employer Menu\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

// Candidate Menu
void candidate_menu(vector<Candidate> &candidates, vector<Jobs> &jobs) {
    int choice;
    string id, password, job_title;

    cout << "\n--- Candidate Menu ---\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Search Jobs\n";
    cout << "4. Exit to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string first_name, last_name, email, resume, phone, job_type;
        cout << "Enter First Name: ";
        getline(cin, first_name);
        cout << "Enter Last Name: ";
        getline(cin, last_name);
        cout << "Enter ID: ";
        getline(cin, id);
        cout << "Enter Password: ";
        getline(cin, password);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Resume: ";
        getline(cin, resume);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Job Type: ";
        getline(cin, job_type);

        Candidate new_candidate(first_name, last_name, id, password, email, resume, phone, job_type);
        candidates.push_back(new_candidate);
        new_candidate.savetofile(CANDIDATE_FILE);
        cout << "Registration successful!\n";
    } else if (choice == 2) {
        cout << "Enter ID: ";
        getline(cin, id);
        cout << "Enter Password: ";
        getline(cin, password);

        for (auto &candidate: candidates) {
            if (candidate.login(id, password)) {
                cout << "Welcome, " << candidate.getFirstName() << "!\n";
                int sub_choice;
                do {
                    cout << "1. Search Jobs\n2. Add Favorite\n3. View Submissions\n4. Logout\nEnter your choice: ";
                    cin >> sub_choice;
                    cin.ignore();
                    if (sub_choice == 1) {
                        for (const auto &job: jobs) job.display_details();
                    } else if (sub_choice == 2) {
                        cout << "Enter Job Title to Favorite: ";
                        getline(cin, job_title);
                        candidate.add_submission(job_title);
                        cout << "Job favorited!\n";
                    } else if (sub_choice == 3) {
                        candidate.display_submission_history();
                    }
                } while (sub_choice != 4);
                break;
            }
        }
        cout << "Invalid login.\n";

    } else if (choice == 3) {
        for (const auto &job: jobs) job.display_details();
    }
}

// Employer Menu
void employer_menu(vector<Employer> &employers, vector<Jobs> &jobs) {
    int choice;
    string id, password;

    cout << "\n--- Employer Menu ---\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string first_name, last_name, email;
        cout << "Enter First Name: ";
        getline(cin, first_name);
        cout << "Enter Last Name: ";
        getline(cin, last_name);
        cout << "Enter ID: ";
        getline(cin, id);
        cout << "Enter Password: ";
        getline(cin, password);
        cout << "Enter Email: ";
        getline(cin, email);

        Employer new_employer(first_name, last_name, id, password, email);
        employers.push_back(new_employer);
        new_employer.savetofile(EMPLOYER_FILE);
        cout << "Registration successful!\n";
    } else if (choice == 2) {
        cout << "Enter ID: ";
        getline(cin, id);
        cout << "Enter Password: ";
        getline(cin, password);
        for (auto &employer: employers) {
            if (employer.login(id, password)) {
                cout << "Welcome, " << employer.getFirstName() << "!\n";
                int sub_choice;
                do {
                    cout << "1. Add Job\n2. View Jobs\n3. Logout\nEnter your choice: ";
                    cin >> sub_choice;
                    cin.ignore();
                    if (sub_choice == 1) {
                        string loc, prof, type, uid;
                        int exp;
                        cout << "Enter Job Location: ";
                        getline(cin, loc);
                        cout << "Enter Profession: ";
                        getline(cin, prof);
                        cout << "Enter Job Type: ";
                        getline(cin, type);
                        cout << "Enter Job UID: ";
                        getline(cin, uid);
                        cout << "Enter Experience (years): ";
                        cin >> exp;
                        cin.ignore();
                        Jobs new_job(loc, prof, type, uid, exp);
                        jobs.push_back(new_job);
                        new_job.savetofile(JOB_FILE);
                        cout << "Job added successfully!\n";
                    } else if (sub_choice == 2) {
                        for (const auto &job: jobs) job.display_details();
                    }
                } while (sub_choice != 3);
                break;
            }
        }
        cout << "Invalid login.\n";
    }
}
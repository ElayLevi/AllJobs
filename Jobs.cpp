#include "Jobs.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Jobs::Jobs(string loc, string prof, string type, string uid, int exp)
        : location(loc), profession(prof), job_type(type), jobUID(uid), experience(exp) {}

// Save to file
void Jobs::savetofile(const string &filename)const {
    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        cerr << "Error: Could not open file for writing.\n";
        return;
    }
    outfile << location << "," << profession << "," << job_type << ","
            << jobUID << "," << experience << "\n";
    outfile.close();
    cout << "Job saved to file successfully.\n";
}

// Load from file
vector<Jobs> Jobs::loadfromfile(const string &filename) {
    vector<Jobs> jobs;
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error: Could not open file for reading.\n";
        return jobs;
    }
    string line, location, profession, job_type, jobUID;
    int experience;
    while (getline(infile, line)) {
        stringstream ss(line);
        getline(ss, location, ',');
        getline(ss, profession, ',');
        getline(ss, job_type, ',');
        getline(ss, jobUID, ',');
        ss >> experience;
        jobs.emplace_back(location, profession, job_type, jobUID, experience);
    }
    infile.close();
    return jobs;
}

// Display job details
void Jobs::display_details() const {
    cout << "Job Details:\n"
         << "Location: " << location << "\n"
         << "Profession: " << profession << "\n"
         << "Job Type: " << job_type << "\n"
         << "Job UID: " << jobUID << "\n"
         << "Required Experience: " << experience << " years\n";
}


// Update posted job function

/*
void Jobs::update_job() {
    int choice = 0;
    bool run = true;
    while (run) {
        cout << "What do tou want to update?:" << endl;
        cout << "1. Job location :" << endl;
        cout << "2. Job profession (job title):" << endl;
        cout << "3. Job type (full time / part time):" << endl;
        cout << "4. Required experience:" << endl;
        cout << "5.Exit." << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                string new_location;
                cout << "Enter the new location:" << endl;
                cin >> new_location;
                location = new_location;
                break;
            }
            case 2: {
                string new_profession;
                cout << "Enter the new profession:" << endl;
                cin >> new_profession;
                profession = new_profession;
                break;
            }
            case 3: {
                string new_job_type;
                cout << "Enter the new job-type :" << endl;
                cin >> new_job_type;
                job_type = new_job_type;
                break;
            }
            case 4: {
                int new_experience;
                cout << "Enter the new required experience:" << endl;
                cin >> new_experience;
                experience = new_experience;
                break;
            }
            case 5 : {
                run = false;
                cout << "Updated successfully completed!" << endl;
                break;
            }
            default:
                cout << "Invalid choice." << endl;

        }
    }
}
*/
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

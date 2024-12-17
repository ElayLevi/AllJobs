//
// Created by איליי on 14/12/2024.
//
using namespace std;
#include "Employer.h"
#include "Jobs.h"

Employer::Employer(string first_name, string last_name, string id, string password, string email)
        : User(first_name, last_name, id, password, email) {}

// Save to file
void Employer::savetofile(const string &filename) const {
    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        cerr << "Error: Could not open file for writing.\n";
        return;
    }
    outfile << first_name << "," << last_name << "," << id << "," << password << "," << email << "\n";
    outfile.close();
}

// Load from file
vector<Employer> Employer::loadfromfile(const string &filename) {
    vector<Employer> employers;
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error: Could not open file for reading.\n";
        return employers;
    }
    string line, first_name, last_name, id, password, email;
    while (getline(infile, line)) {
        stringstream ss(line);
        getline(ss, first_name, ',');
        getline(ss, last_name, ',');
        getline(ss, id, ',');
        getline(ss, password, ',');
        getline(ss, email, ',');
        employers.emplace_back(first_name, last_name, id, password, email);
    }
    infile.close();
    return employers;
}

// Add job
void Employer::add_job(Jobs job, const string &filename) {
    posted_jobs.push_back(job);
    job.savetofile(filename);
    cout << "Job added successfully.\n";
}

// Delete job
void Employer::delete_job(const string &jobUID, const string &filename) {
    bool found = false;
    vector<Jobs> updated_jobs;
    for (const auto &job : posted_jobs) {
        if (job.getJobUID() == jobUID) {
            found = true;
        } else {
            updated_jobs.push_back(job);
        }
    }
    if (found) {
        posted_jobs = updated_jobs;
        ofstream outfile(filename, ios::trunc);
        if (!outfile.is_open()) {
            cerr << "Error: Could not open file for writing.\n";
            return;
        }
        for (Jobs job : posted_jobs) {
            job.savetofile(filename);
        }
        cout << "Job deleted successfully.\n";
    } else {
        cout << "Job not found.\n";
    }
}
// Update job
void Employer::update_job(const string &jobUID, const Jobs &updated_job, const string &filename) {
    bool found = false;
    for (auto &job : posted_jobs) {
        if (job.getJobUID() == jobUID) {
            job = updated_job;
            found = true;
            break;
        }
    }
    if (found) {
        ofstream outfile(filename, ios::trunc);
        if (!outfile.is_open()) {
            cerr << "Error: Could not open file for writing.\n";
            return;
        }
        for (const auto &job : posted_jobs) {
            job.savetofile(filename);
        }
        cout << "Job updated successfully.\n";
    } else {
        cout << "Job not found.\n";
    }
}

// Display jobs
void Employer::display_jobs() const {
    if (posted_jobs.empty()) {
        cout << "No jobs posted.\n";
        return;
    }
    cout << "Posted Jobs:\n";
    for (const auto &job : posted_jobs) {
        job.display_details();
    }
}

// Display employer details
void Employer::display_details() const {
    cout << "Employer Details:\n";
    cout << "Name: " << first_name << " " << last_name << "\n"
         << "ID: " << id << "\n"
         << "Email: " << email << "\n";
}

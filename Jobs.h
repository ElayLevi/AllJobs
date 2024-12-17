#ifndef ALLOJBSV2_JOBS_H
#define ALLOJBSV2_JOBS_H

#include <string>
#include <vector>
using namespace std;

class Jobs {
private:
    string location;
    string profession;
    string job_type;
    string jobUID;
    int experience;

public:
    // Constructor
    Jobs(string loc = "", string prof = "", string type = "", string uid = "", int exp = 0);

    // Save and Load
    void savetofile(const string &filename)const;
    static vector<Jobs> loadfromfile(const string &filename);

    // Getters
    string getLocation() const { return location; }
    string getProfession() const { return profession; }
    string getJobType() const { return job_type; }
    string getJobUID() const { return jobUID; }
    int getExperience() const { return experience; }

    // Setters
    void setLocation(const string &loc) { location = loc; }
    void setProfession(const string &prof) { profession = prof; }
    void setJobType(const string &type) { job_type = type; }
    void setJobUID(const string &uid) { jobUID = uid; }
    void setExperience(int exp) { experience = exp; }

    // Display Details
    void display_details() const;
};

#endif // ALLOJBSV2_JOBS_H

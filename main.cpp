//
// Created by Daniel Lipszyc on 4/18/25.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


struct Patient{
    float BMI;
    float StressLevel;
    int HAO; // Heart Attack Outcome

    Patient(float BMI, int HAO){
        this->BMI = BMI;
        this->HAO = HAO;
    }
};


void extractBMIsFromFile(vector<Patient> &list) {
    ifstream file("../heart_attack_dataset.csv");
    if (!file.is_open()) {
        cerr << "Error: Could not open file 'ONE'." << endl;
        return;
    }

    string line;

    // Skip the header line
    getline(file, line);

    // Process each data line
    float max = 0.0;
    float min = 20.0;
    Patient R(0.0, 0);
    int count = 0;
    while (getline(file, line)) {
        size_t start = 0;
        size_t end = 0;
        int index = 0;
        float bmi = 0;
        int outcome = 0;

        string token;

        // Manually parse the line
        while (end != string::npos && index <= 31) {
            end = line.find(',', start);
            token = line.substr(start, end - start);

            if (index == 5) {
                bmi = stof(token);
            } else if (index == 31) {
                outcome = (token == "Heart Attack") ? 1 : 0;
                break;
            }

            start = end + 1;
            ++index;
        }

        R.BMI = bmi;
        R.HAO = outcome;
        list.push_back(R);

        ++index;
        count++;
    }
    file.close();
}


int main(){
    cout << 11;
    return 0;
}
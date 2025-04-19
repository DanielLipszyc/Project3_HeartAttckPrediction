//
// Created by Daniel Lipszyc on 4/18/25.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "MergeSort.h"


void extractBMIsFromFile(vector<Patient*> &list) {
    ifstream file("../heart_attack_dataset.csv");
    if (!file.is_open()) {
        cerr << "Error: Could not open file 'ONE'." << endl;
        return;
    }
    string line;
    getline(file, line); // skip header
    int count = 0;
    while (getline(file, line)) {
        size_t start = 0;
        size_t end = 0;
        int index = 0;
        float bmi = 0;
        int stressLevel = 0;
        int outcome = 0;
        string token;

        while (end != string::npos && index <= 31) {
            end = line.find(',', start);
            token = line.substr(start, end - start);

            if (index == 5) {
                bmi = stof(token);
            }

            else if(index == 13){
                stressLevel = stoi(token);
            }

            else if (index == 31) {
                outcome = (token == "Heart Attack") ? 1 : 0;
                break;
            }

            start = end + 1;
            ++index;
        }

        Patient* P = new Patient(bmi, outcome, stressLevel);
        list.push_back(P);

        ++index;
        count++;
    }
    file.close();
}

int main(){
    int num = 1;

    vector<Patient*> Patients = {};
    extractBMIsFromFile(Patients);
    time_t start, end;
    time(&start);

    //radixSort(Patients);
    //mergeSort(Patients, 0, Patients.size() - 1);

    time(&end);

    int input_BMI;
    cout << "Enter a number between 20 and 40: ";
    cin >> input_BMI;


    for(Patient* p : Patients){

        cout << num << ". " << "BMI: " << p->BMI << " Outcome: " << p->HAO << endl;
        num++;

    }

    cout << difftime(end, start) << endl;
}
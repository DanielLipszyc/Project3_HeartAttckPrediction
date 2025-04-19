//
// Created by Daniel Lipszyc on 4/18/25.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "MergeSort.h"
#include "RadixSort.h"


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

    radixSort(Patients);
    //mergeSort(Patients, 0, Patients.size() - 1);

    time(&end);

    int input_BMI = 23; // Ivana please get input from GUI and put it here

    //Percentage Calculation Section

    vector<Patient*> sameBMI_Patients = {};

    for(int i = 0; i < Patients.size(); i++){
        if(Patients[i]->BMI < input_BMI){
            i++;
        }
        else if(Patients[i]->BMI == input_BMI){
            sameBMI_Patients.push_back(Patients[i]);
        }
        else{
            break;
        }
    }

    int total = sameBMI_Patients.size();
    int positive = 0;
    for(Patient* p : sameBMI_Patients){
        if(p->HAO == 1){
            positive++;
        }
    }

    float average = (float)positive / total;
    cout << "Average: " << average << endl;



//    for(Patient* p : sameBMI_Patients){
//
//        cout << num << ". " << "BMI: " << p->BMI << " Outcome: " << p->HAO << endl;
//        num++;
//
//    }

    cout << difftime(end, start) << endl;
}
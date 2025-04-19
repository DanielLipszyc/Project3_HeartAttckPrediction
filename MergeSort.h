//
// Created by Daniel Lipszyc on 4/19/25.
//
#include "PatientObject.h"
using namespace std;

#ifndef PROJECT3_HEARTATTCKPREDICTION_MERGESORT_H
#define PROJECT3_HEARTATTCKPREDICTION_MERGESORT_H

void merge(vector<Patient*>& P, int left, int mid, int right);
void mergeSort(vector<Patient*>& P, int left, int right);
#endif //PROJECT3_HEARTATTCKPREDICTION_MERGESORT_H

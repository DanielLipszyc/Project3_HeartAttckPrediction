


#ifndef PROJECT3_RADIXSORT_H
#define PROJECT3_RADIXSORT_H
#include <vector>
using namespace std;
#include "PatientObject.h"

int getMax(vector<Patient*> P);
void countingSort(vector<Patient*>& P, int exp);
void radixSort(vector<Patient*>& P);

#endif //PROJECT3_RADIXSORT_H




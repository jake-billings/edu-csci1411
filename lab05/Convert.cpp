/* 
 * Copied from Lab Document
 */
#include "Convert.h"

double fahrenToCel(double fahren) {
    double result = (fahren - 32) * (5.0 / 9.0);
    return result;
}

void passByValue(int value) {
    value++;
}

void passByReference(int &ref) {
    ref++;
}

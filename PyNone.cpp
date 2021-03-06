/* 
 * File:   PyNone.cpp
 * Author: Kent D. Lee
 * (c) 2013
 * Created on February 14, 2013, 7:24 PM
 * 
 * License:
 * Please read the LICENSE file in this distribution for details regarding
 * the licensing of this code. This code is freely available for educational
 * use. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
 * 
 * Description:
 * See the associated header file for a description of the purpose of this 
 * class. Implementation details are provided here. Read below for 
 * any specific details. 
 * 
 */

#include "PyNone.h"
#include "PyType.h"
#include "PyStr.h"

PyNone::PyNone() : PyObject() {
}

PyNone::PyNone(const PyNone& orig) {
}

PyNone::~PyNone() {
}

PyType* PyNone::getType() {
    return PyTypes[PyNoneTypeId];
}

string PyNone::toString() {
    return "None";
}


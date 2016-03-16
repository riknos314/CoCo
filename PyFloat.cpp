/* 
 * File:   PyFloat.cpp
 * Author: Kent D. Lee
 * (c) 2013
 * Created on February 12, 2013, 10:13 PM
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

#include "PyFloat.h"
#include "PyStr.h"
#include "PyInt.h"
#include "PyType.h"
#include "PyBool.h"
#include "PyException.h"
// Added cstdio include to compile on cygwin per request: 2/9/2016 
#include <cstdio>
#include <sstream>
using namespace std;

PyFloat::PyFloat(double f) : PyObject() {
    val = f;
    dict["__add__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyFloat::__add__);
    dict["__sub__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyFloat::__sub__);
    dict["__mul__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyFloat::__mul__);
    dict["__truediv__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyFloat::__truediv__);
    dict["__float__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyFloat::__float__);
    dict["__int__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyFloat::__int__);
    dict["__bool__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyFloat::__bool__);
}

PyFloat::PyFloat(const PyFloat& orig) : PyFloat(orig.val) {
}

PyFloat::~PyFloat() {
}

string PyFloat::toString() {
    char buffer[50];
    sprintf(buffer,"%1.4f",val);
    stringstream ss;
    ss << buffer;
    return ss.str();
}

PyObject* PyFloat::__add__(vector<PyObject*>* args) {
    ostringstream msg;

    if (args->size() != 1) {
        msg << "TypeError: expected 1 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,msg.str());  
    }
    
    //make sure that passing in an int as a parameter works properly
    PyObject* arg2 = (PyObject*) (*args)[0];
    PyFloat* argVal;
    if (arg2->getType()==PyTypes[PyIntTypeId]) {
        PyInt* newInt = (PyInt*) arg2;
        argVal = new PyFloat(newInt->getVal());
    } else {
        argVal = (PyFloat*) arg2;
    }
    return new PyFloat(this->val + argVal->getVal());
}

PyObject* PyFloat::__sub__(vector<PyObject*>* args) {
    ostringstream msg;

    if (args->size() != 1) {
        msg << "TypeError: expected 1 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,msg.str());  
    }
    
    //make sure that passing in an int as a parameter works properly
    PyObject* arg2 = (PyObject*) (*args)[0];
    PyFloat* argVal;
    if (arg2->getType()==PyTypes[PyIntTypeId]) {
        PyInt* newInt = (PyInt*) arg2;
        argVal = new PyFloat(newInt->getVal());
    } else {
        argVal = (PyFloat*) arg2;
    }
    return new PyFloat(this->val - argVal->getVal());
}

PyObject* PyFloat::__mul__(vector<PyObject*>* args) {
    ostringstream msg;

    if (args->size() != 1) {
        msg << "TypeError: expected 1 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,msg.str());  
    }
    
    //make sure that passing in an int as a parameter works properly
    PyObject* arg2 = (PyObject*) (*args)[0];
    PyFloat* argVal;
    if (arg2->getType()==PyTypes[PyIntTypeId]) {
        PyInt* newInt = (PyInt*) arg2;
        argVal = new PyFloat(newInt->getVal());
    } else {
        argVal = (PyFloat*) arg2;
    }
    return new PyFloat(this->val * argVal->getVal());
}

PyObject* PyFloat::__truediv__(vector<PyObject*>* args) {
    ostringstream msg;

    if (args->size() != 1) {
        msg << "TypeError: expected 1 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,msg.str());  
    }
    
    //make sure that passing in an int as a parameter works properly
    PyObject* arg2 = (PyObject*) (*args)[0];
    PyFloat* argVal;
    if (arg2->getType()==PyTypes[PyIntTypeId]) {
        PyInt* newInt = (PyInt*) arg2;
        argVal = new PyFloat(newInt->getVal());
    } else {
        argVal = (PyFloat*) arg2;
    }
    if (argVal->getVal() == 0) {
        throw new PyException(PYILLEGALOPERATIONEXCEPTION, "ZeroDivisionError: division by zero");
    }
    return new PyFloat(this->val / argVal->getVal());
}

PyType* PyFloat::getType() {
    return PyTypes[PyFloatTypeId];
}

double PyFloat::getVal() {
    return val;
}


PyObject* PyFloat::__float__(vector<PyObject*>* args) {
    ostringstream msg;

    if (args->size() != 0) {
        msg << "TypeError: expected 0 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,msg.str());  
    }
    
    return this;
}

PyObject* PyFloat::__int__(vector<PyObject*>* args) {
    ostringstream msg;

    if (args->size() != 0) {
        msg << "TypeError: expected 0 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,msg.str());  
    }
    
    int x;
    
    x = (int)this->getVal();
    return new PyInt(x);
}

PyObject* PyFloat::__bool__(vector<PyObject*>* args) {
    ostringstream msg;
    
    if (args->size() != 0) {
        msg << "TypeError: expected 0 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,msg.str());  
    }
    
    if (this->getVal()==0.0)
        return new PyBool(false);
    
    return new PyBool(true);
}

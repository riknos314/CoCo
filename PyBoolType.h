/* 
 * File:   PyBoolType.h
 */

#ifndef PYBOOLTYPE_H
#define	PYBOOLTYPE_H

#include <PyBool.h>
#include <PyType.h>
#include <vector>
using namespace std;

class PyBoolType : public PyType {
public:
    PyBoolType();
    PyBoolType(string typeString, PyTypeId id);
    virtual ~PyBoolType();
    bool allowableArgCount(int count);
    
protected:
    PyObject* __call__(vector<PyObject*>* args);
};

#endif	/* PYBOOLTYPE_H */


/* 
 * File:   PyFloatType.h
 */

#ifndef PYFLOATTYPE_H
#define	PYFLOATTYPE_H

#include <PyFloat.h>
#include <PyType.h>
#include <vector>
using namespace std;

class PyFloatType : public PyType {
public:
    PyFloatType();
    PyFloatType(string typeString, PyTypeId id);
    virtual ~PyFloatType();
    bool allowableArgCount(int count);
    

    
protected:
    PyObject* __call__(vector<PyObject*>* args);
};

#endif	/* PYFLOATTYPE_H */


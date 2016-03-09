/* 
 * File:   PyIntType.h
 */

#ifndef PYINTTYPE_H
#define	PYINTTYPE_H

#include <PyInt.h>
#include <PyType.h>
#include <vector>
using namespace std;

class PyIntType : public PyType {
public:
    PyIntType();
    PyIntType(string typeString, PyTypeId id);
    virtual ~PyIntType();
    bool allowableArgCount(int count);
    

    
protected:
    PyObject* __call__(vector<PyObject*>* args);
};

#endif	/* PYINTTYPE_H */


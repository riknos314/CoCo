/* 
 * File:   PyComplexType.h
 */

#ifndef PYCOMPLEXTYPE_H
#define	PYCOMPLEXTYPE_H

#include <PyComplex.h>
#include <PyType.h>
#include <vector>
using namespace std;

class PyComplexType : public PyType {
public:
    PyComplexType();
    PyComplexType(string typeString, PyTypeId id);
    virtual ~PyComplexType();
    bool allowableArgCount(int count);

    
protected:
    PyObject* __call__(vector<PyObject*>* args);
};

#endif	/* PYCOMPLEXTYPE_H */


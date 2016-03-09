/* 
 * File:   PyListType.h
 */

#ifndef PYLISTTYPE_H
#define	PYLISTTYPE_H

#include <PyList.h>
#include <PyType.h>
#include <vector>
using namespace std;

class PyListType : public PyType {
public:
    PyListType();
    PyListType(string typeString, PyTypeId id);
    virtual ~PyListType();
    bool allowableArgCount(int count);
    

    
protected:
    PyObject* __call__(vector<PyObject*>* args);
};

#endif	/* PYLISTTYPE_H */


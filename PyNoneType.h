/* 
 * File:   PyNoneType.h
 */

#ifndef PYNONETYPE_H
#define	PYNONETYPE_H

#include <PyNone.h>
#include <PyType.h>
#include <vector>
using namespace std;

class PyNoneType : public PyType {
public:
    PyNoneType();
    PyNoneType(string typeString, PyTypeId id);
    virtual ~PyNoneType();
    bool allowableArgCount(int count);
    

    
protected:
    PyObject* __call__(vector<PyObject*>* args);
};

#endif	/* PYNONETYPE_H */


/* 
 * File:   PyTypeType.h
 */

#ifndef PYTYPETYPE_H
#define	PYTYPETYPE_H

#include <PyType.h>
#include <vector>
using namespace std;

class PyTypeType : public PyType {
public:
    PyTypeType();
    PyTypeType(string typeString, PyTypeId id);
    virtual ~PyTypeType();
    bool allowableArgCount(int count);
    

    
protected:
    PyObject* __call__(vector<PyObject*>* args);
};

#endif	/* PYTYPETYPE_H */


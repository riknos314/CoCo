
#include "PyNoneType.h"
#include "PyType.h"
#include "PyException.h"
#include "PyInt.h"
#include "PyNone.h"

PyNoneType::PyNoneType() : PyType("list", PyNoneTypeId) {
}

PyNoneType::PyNoneType(string typeString, PyTypeId id) : PyType(typeString, id) {
}

PyNoneType::~PyNoneType() {
}


PyObject* PyNoneType::__call__(vector<PyObject*>* args) {

    vector<PyObject*>* emptyArgs = new vector<PyObject*>();
    PyObject * arg;
    string funName;

    switch (args-> size()) {
        case 0:
            throw new PyException(PYILLEGALOPERATIONEXCEPTION, "TypeError: cannot create 'NoneType' instances");
            break;
        case 1: 
            arg = (*args)[0];
            funName = "__"+this->toString()+"__";
            return arg->callMethod(funName,emptyArgs);
            break;
        default:
            throw new PyException(PYILLEGALOPERATIONEXCEPTION, "Incorrect number of arguments for PyNone type");
            break;
    }
}

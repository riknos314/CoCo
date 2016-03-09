
#include "PyFloatType.h"
#include "PyType.h"
#include "PyException.h"
#include "PyInt.h"
#include "PyFloat.h"

PyFloatType::PyFloatType() : PyType("float", PyFloatTypeId) {
}

PyFloatType::PyFloatType(string typeString, PyTypeId id) : PyType(typeString, id) {
}

PyFloatType::~PyFloatType() {
}


PyObject* PyFloatType::__call__(vector<PyObject*>* args) {

    vector<PyObject*>* emptyArgs = new vector<PyObject*>();
    PyObject * arg;
    string funName;

    switch (args-> size()) {
        case 0:
            return new PyFloat(0.0);
            break;
        case 1: 
            arg = (*args)[0];
            funName = "__"+this->toString()+"__";
            return arg->callMethod(funName,emptyArgs);
            break;
        default:
            throw new PyException(PYILLEGALOPERATIONEXCEPTION, "Incorrect number of arguments for PyFloat type");
            break;
    }
}

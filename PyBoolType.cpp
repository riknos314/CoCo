
#include "PyBoolType.h"
#include "PyType.h"
#include "PyException.h"
#include "PyInt.h"
#include "PyBool.h"

PyBoolType::PyBoolType() : PyType("list", PyBoolTypeId) {
}

PyBoolType::PyBoolType(string typeString, PyTypeId id) : PyType(typeString, id) {
}

PyBoolType::~PyBoolType() {
}


PyObject* PyBoolType::__call__(vector<PyObject*>* args) {

    vector<PyObject*>* emptyArgs = new vector<PyObject*>();
    PyObject * arg;
    string funName;

    switch (args-> size()) {
        case 0:
            return new PyBool(false);
            break;
        case 1: 
            arg = (*args)[0];
            funName = "__"+this->toString()+"__";
            return arg->callMethod(funName,emptyArgs);
            break;
        default:
            throw new PyException(PYILLEGALOPERATIONEXCEPTION, "Incorrect number of arguments for PyBool type");
            break;
    }
}

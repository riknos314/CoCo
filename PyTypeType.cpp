
#include "PyTypeType.h"
#include "PyType.h"
#include "PyException.h"
#include "PyInt.h"

PyTypeType::PyTypeType() : PyType("type", PyTypeTypeId) {
}

PyTypeType::PyTypeType(string typeString, PyTypeId id) : PyType(typeString, id) {
}

PyTypeType::~PyTypeType() {
}


PyObject* PyTypeType::__call__(vector<PyObject*>* args) {

    vector<PyObject*>* emptyArgs = new vector<PyObject*>();
    PyObject * arg;
    string funName;

    switch (args-> size()) {
        case 0:
            throw new PyException(PYILLEGALOPERATIONEXCEPTION, "TypeError: type() takes 1 or 3 arguments");
            break;
        case 1: 
            arg = (*args)[0];
            funName = "__"+this->toString()+"__";
            return arg->callMethod(funName,emptyArgs);
            break;
        default:
            throw new PyException(PYILLEGALOPERATIONEXCEPTION, "Incorrect number of arguments for PyType type");
            break;
    }
}

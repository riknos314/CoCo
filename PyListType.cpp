
#include "PyListType.h"
#include "PyType.h"
#include "PyException.h"
#include "PyInt.h"
#include "PyList.h"

PyListType::PyListType() : PyType("list", PyListTypeId) {
}

PyListType::PyListType(string typeString, PyTypeId id) : PyType(typeString, id) {
}

PyListType::~PyListType() {
}


PyObject* PyListType::__call__(vector<PyObject*>* args) {

    vector<PyObject*>* emptyArgs = new vector<PyObject*>();
    PyObject * arg;
    string funName;

    switch (args-> size()) {
        case 0:
            return new PyList(emptyArgs);
            break;
        case 1: 
            arg = (*args)[0];
            funName = "__"+this->toString()+"__";
            return arg->callMethod(funName,emptyArgs);
            break;
        default:
            throw new PyException(PYILLEGALOPERATIONEXCEPTION, "Incorrect number of arguments for PyList type");
            break;
    }
}

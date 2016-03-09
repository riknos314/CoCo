
#include "PyIntType.h"
#include "PyType.h"
#include "PyException.h"
#include "PyInt.h"

PyIntType::PyIntType() : PyType("int", PyIntTypeId) {
}

PyIntType::PyIntType(string typeString, PyTypeId id) : PyType(typeString, id) {
}

PyIntType::~PyIntType() {
}


PyObject* PyIntType::__call__(vector<PyObject*>* args) {

    vector<PyObject*>* emptyArgs = new vector<PyObject*>();
    PyObject * arg;
    string funName;

    switch (args-> size()) {
        case 0:
            return new PyInt(0);
            break;
        case 1: 
            arg = (*args)[0];
            funName = "__"+this->toString()+"__";
            return arg->callMethod(funName,emptyArgs);
            break;
        default:
            throw new PyException(PYILLEGALOPERATIONEXCEPTION, "Incorrect number of arguments for PyInt type");
            break;
    }
}

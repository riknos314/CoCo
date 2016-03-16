
#include "PyComplexType.h"
#include "PyType.h"
#include "PyException.h"
#include "PyComplex.h"

PyComplexType::PyComplexType() : PyType("complex", PyComplexTypeId) {
}

PyComplexType::PyComplexType(string typeString, PyTypeId id) : PyType(typeString, id) {
}

PyComplexType::~PyComplexType() {
}


PyObject* PyComplexType::__call__(vector<PyObject*>* args) {

    PyObject* arg1;
    PyObject* arg2;
    string funName;

    switch (args-> size()) {
        case 2:
            arg1 = (*args)[1];
            arg2 = (*args)[0];
            return new PyComplex(arg1, arg2);
            break;
        default:
            throw new PyException(PYILLEGALOPERATIONEXCEPTION, "Incorrect number of arguments for PyComplextype");
            break;
    }
}

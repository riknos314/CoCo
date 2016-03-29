
#include "PyComplex.h"
#include "PyInt.h"
#include "PyType.h"
#include "PyStr.h"
#include "PyBool.h"
#include "PyFloat.h"
#include "PyException.h"
#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

PyComplex::PyComplex(PyObject* real, PyObject* imag) {
    this->real = real;
    this->imag = imag;

    dict["__add__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyComplex::__add__);
    dict["__sub__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyComplex::__sub__);
    dict["__mul__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyComplex::__mul__);
    dict["__truediv__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyComplex::__truediv__);
    dict["__eq__"] = (PyObject* (PyObject::*)(vector<PyObject*>*)) (&PyComplex::__eq__);
}

PyComplex::PyComplex(const PyComplex& orig) {
}

PyComplex::~PyComplex() {
}

PyType* PyComplex::getType() {
    return PyTypes[PyComplexTypeId];
}

string PyComplex::toString() {
    stringstream ss;
    double realPart, imagPart;

    istringstream realReader(real->toString());
    realReader.exceptions(ios_base::failbit | ios_base::badbit);
    
    istringstream imagReader(imag->toString());
    imagReader.exceptions(ios_base::failbit | ios_base::badbit);

    realReader >> realPart;
    imagReader >> imagPart;

    if (realPart != 0)
        ss << "(";

    if (realPart != 0)
        ss << real->toString();

    if (realPart != 0 && imagPart >= 0)
        ss << "+";

    ss << imag->toString() << "j";

    if (realPart != 0)
        ss << ")";

    return ss.str();
}

PyObject* PyComplex::__add__(vector<PyObject*>* args) {

    ostringstream message;
    PyComplex* other;

    vector<PyObject*>* realVec = new vector <PyObject*>();
    vector<PyObject*>* imagVec = new vector <PyObject*>();
    
    PyObject* finalReal;
    PyObject* finalImag;

    if (args->size() != 1) {
        message << "TypeError: expected 1 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,message.str());  
    }

    PyObject* arg = (*args)[0];
    other = (PyComplex*) arg;

    realVec->push_back(other->real);
    imagVec->push_back(other->imag); 
    finalReal = this->real->callMethod("__add__", realVec);
    finalImag = this->imag->callMethod("__add__", imagVec);

    return new PyComplex(finalReal, finalImag);
}

PyObject* PyComplex::__sub__(vector<PyObject*>* args) {

    ostringstream message;
    PyComplex* other;

    vector<PyObject*>* realVec = new vector <PyObject*>();
    vector<PyObject*>* imagVec = new vector <PyObject*>();
    
    PyObject* finalReal;
    PyObject* finalImag;

    if (args->size() != 1) {
        message << "TypeError: expected 1 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,message.str());  
    }

    PyObject* arg = (*args)[0];
    other = (PyComplex*) arg;

    realVec->push_back(other->real);
    imagVec->push_back(other->imag); 

    finalReal = this->real->callMethod("__sub__", realVec);
    finalImag = this->imag->callMethod("__sub__", imagVec);

    return new PyComplex(finalReal, finalImag);
}

PyObject* PyComplex::__mul__(vector<PyObject*>* args) {

    PyObject* ac;
    PyObject* bd;
    PyObject* bc;
    PyObject* ad;

    ostringstream message;
    PyComplex* other;

    vector<PyObject*>* realVec = new vector <PyObject*>();
    vector<PyObject*>* imagVec = new vector <PyObject*>();
    
    PyObject* finalReal;
    PyObject* finalImag;

    if (args->size() != 1) {
        message << "TypeError: expected 1 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,message.str());  
    }

    PyObject* arg = (*args)[0];
    other = (PyComplex*) arg;

    realVec->push_back(other->real);
    imagVec->push_back(other->imag); 

    ac = this->real->callMethod("__mul__", realVec);
    bd = this->imag->callMethod("__mul__", imagVec);
    bc = this->imag->callMethod("__mul__", realVec);
    ad = this->real->callMethod("__mul__", imagVec);

    PyObject* newbd;
    PyObject* newad;

    vector<PyObject*>* bdVec = new vector <PyObject*>();
    vector<PyObject*>* adVec = new vector <PyObject*>();

    bdVec-> push_back(bd);
    adVec-> push_back(ad);

    finalReal = ac->callMethod("__sub__", bdVec);
    finalImag = bc->callMethod("__add__", adVec);

    return new PyComplex(finalReal, finalImag);
}

PyObject* PyComplex::__truediv__(vector<PyObject*>* args) {

    PyObject* ac;
    PyObject* bd;
    PyObject* bc;
    PyObject* ad;

    ostringstream message;
    PyComplex* other;

    vector<PyObject*>* realVec = new vector <PyObject*>();
    vector<PyObject*>* imagVec = new vector <PyObject*>();
    
    PyObject* penultimateReal;
    PyObject* penultimateImag;
    PyObject* finalReal;
    PyObject* finalImag;

    if (args->size() != 1) {
        message << "TypeError: expected 1 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,message.str());  
    }

    PyObject* arg = (*args)[0];
    other = (PyComplex*) arg;

    realVec->push_back(other->real);
    imagVec->push_back(other->imag); 

    ac = this->real->callMethod("__mul__", realVec);
    bd = this->imag->callMethod("__mul__", imagVec);
    bc = this->imag->callMethod("__mul__", realVec);
    ad = this->real->callMethod("__mul__", imagVec);

    vector<PyObject*>* bdVec = new vector <PyObject*>();
    vector<PyObject*>* adVec = new vector <PyObject*>();

    bdVec-> push_back(bd);
    adVec-> push_back(ad);

    penultimateReal = ac->callMethod("__add__", bdVec);
    penultimateImag = bc->callMethod("__sub__", adVec);

    PyObject* cSq;
    PyObject* dSq;

    cSq = other->real->callMethod("__mul__",realVec);
    dSq = other->imag->callMethod("__mul__",imagVec);

    vector<PyObject*>* dSqVec = new vector <PyObject*>();
    dSqVec->push_back(dSq);

    PyObject* cSqPlusdSq = cSq->callMethod("__add__",dSqVec);

    vector<PyObject*>* cSqPlusdSqVec = new vector <PyObject*>();
    cSqPlusdSqVec->push_back(cSqPlusdSq);

    finalReal = penultimateReal->callMethod("__truediv__",cSqPlusdSqVec);
    finalImag = penultimateImag->callMethod("__truediv__",cSqPlusdSqVec);

    return new PyComplex(finalReal, finalImag);
}

PyObject* PyComplex::__eq__(vector<PyObject*>* args) {

    ostringstream message;
    PyComplex* other;

    vector<PyObject*>* realVec = new vector <PyObject*>();
    vector<PyObject*>* imagVec = new vector <PyObject*>();
    
    PyObject* finalReal;
    PyObject* finalImag;


    if (args->size() != 1) {
        message << "TypeError: expected 1 arguments, got " << args->size();
        throw new PyException(PYWRONGARGCOUNTEXCEPTION,message.str());  
    }

    PyObject* arg = (*args)[0];
    other = (PyComplex*) arg;
    

    realVec->push_back(other->real);
    imagVec->push_back(other->imag); 
    finalReal = this->real->callMethod("__eq__", realVec);
    finalImag = this->imag->callMethod("__eq__", imagVec);
    
    PyBool* realBool = (PyBool*) finalReal;
    PyBool* imagBool = (PyBool*) finalImag;
    

    return new PyBool((realBool->getVal() && imagBool->getVal()));
}

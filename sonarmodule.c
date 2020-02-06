#define PY_SSIZE_T_CLEAN

#include <Python.h>
#include "sonic.h"

PyObject*
sonar_measure(PyObject* self, PyObject* args);

static PyMethodDef
SonarMethods[] = {
    {"measure", sonar_measure, METH_VARARGS, "Measure a sensor"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef
sonarmodule = {
    PyModuleDef_HEAD_INIT,
    "sonar",
    NULL,
    -1,
    SonarMethods
};

PyMODINIT_FUNC
PyInit_sonar(void)
{
    PyObject* m;

    m = PyModule_Create(&sonarmodule);
    if (NULL == m)
    {
        return NULL;
    }

    initialize();

    return m;
}

PyObject*
sonar_measure(PyObject* self, PyObject* args)
{
    int port = 0;

    if (!PyArg_ParseTuple(args, "i", &port))
    {
        return Py_None;
    }

    return PyLong_FromDouble(measure(port));
}

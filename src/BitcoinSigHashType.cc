#include "BitcoinSigHashType.h"

static PyTypeObject BitcoinSigHashTypeType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.BitcoinSigHashType",      /* tp_name */
    sizeof(BitcoinSigHashTypeObject),     /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    nullptr,                   /* tp_doc */
};

int BitcoinSigHashType_init(BitcoinSigHashTypeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool BitcoinSigHashType_enum_init(PyObject *module) {
    
    BitcoinSigHashTypeType.tp_init = (initproc)BitcoinSigHashType_init;
    BitcoinSigHashTypeType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&BitcoinSigHashTypeType) < 0)
        return false;
    
    Py_INCREF(&BitcoinSigHashTypeType);
    if (PyModule_AddObject(module, "BitcoinSigHashType", (PyObject *) &BitcoinSigHashTypeType) < 0) {
        Py_DECREF(&BitcoinSigHashTypeType);
        return false;
    }

    // auto* o = PyObject_New(BitcoinSigHashTypeObject, &BitcoinSigHashTypeType);

    PyObject* dict = BitcoinSigHashTypeType.tp_dict;
    (void)dict;

    PyDict_SetItemString(dict, "All", PyLong_FromLong(TWBitcoinSigHashTypeAll));
    PyDict_SetItemString(dict, "None", PyLong_FromLong(TWBitcoinSigHashTypeNone));
    PyDict_SetItemString(dict, "Single", PyLong_FromLong(TWBitcoinSigHashTypeSingle));
    PyDict_SetItemString(dict, "Fork", PyLong_FromLong(TWBitcoinSigHashTypeFork));
    PyDict_SetItemString(dict, "ForkBTG", PyLong_FromLong(TWBitcoinSigHashTypeForkBTG));

    return true;
}
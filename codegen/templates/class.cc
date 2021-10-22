// Copyright 2021 Peng Huang <shawn.p.huang@gmail.com>
// This file is part of Wallet-core-python.
//
// Wallet-core-python is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Wallet-core-python is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Wallet-core-python.  If not, see <https://www.gnu.org/licenses/>.
//
// NOTE: this is a GENERATED FILE, changes made here WILL BE LOST.

#include "${name}.h"

${includes}

struct Py${name}Object {
  PyObject_HEAD;
  TW${name}* value;
};

static PyTypeObject Py${name}Type = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.${name}",      /* tp_name */
    sizeof(Py${name}Object),   /* tp_basicsize */
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


bool Py${name}_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &Py${name}Type) != 0;
}

// Create Py${name} from enum TW${name}.
PyObject* Py${name}_FromTW${name}(TW${name}* value) {
  if (!value)
    Py_RETURN_NONE;

  Py${name}Object* object = PyObject_New(Py${name}Object, &Py${name}Type);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TW${name}* Py${name}_GetTW${name}(PyObject* object) {
  assert(Py${name}_Check(object));
  return ((Py${name}Object*)object)->value;
}

static void Py${name}_dealloc(Py${name}Object *self) {
  if (self->value) {
    TW${name}Delete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

${functions}

static const PyGetSetDef get_set_defs[] = {
${getsetdefs}
};

static const PyMethodDef method_defs[] = {
${methoddefs}
};

bool PyInit_${name}(PyObject *module) {
  Py${name}Type.tp_dealloc = (destructor)Py${name}_dealloc;
  Py${name}Type.tp_getset = (PyGetSetDef*)get_set_defs;
  Py${name}Type.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&Py${name}Type) < 0)
    return false;

  Py_INCREF(&Py${name}Type);
  if (PyModule_AddObject(module, "${name}", (PyObject *) &Py${name}Type) < 0) {
    Py_DECREF(&Py${name}Type);
    return false;
  }

  return true;
}
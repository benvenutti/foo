#ifndef FOO_CALCULATOR_H
#define FOO_CALCULATOR_H

#include "FooExport.h"

namespace Foo {

class FOO_EXPORT Calculator {
  public:
    static int add(const int a, const int b) {
      return a + b;
    }

    static int sub(const int a, const int b) {
      return a - b;
    }
};

}

#endif
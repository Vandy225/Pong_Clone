#include <iostream>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

#include "tests.h"

int main() {
   CppUnit::TextUi::TestRunner runner;
   runner.addTest(Tests::suite());
   runner.run();
 
  return 0;
}

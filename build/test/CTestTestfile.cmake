# CMake generated Testfile for 
# Source directory: D:/Projects/Example/test
# Build directory: D:/Projects/Example/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(ExampleTest "D:/Projects/Example/build/test/Debug/ExampleTest.exe")
  set_tests_properties(ExampleTest PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/Example/test/CMakeLists.txt;17;add_test;D:/Projects/Example/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(ExampleTest "D:/Projects/Example/build/test/Release/ExampleTest.exe")
  set_tests_properties(ExampleTest PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/Example/test/CMakeLists.txt;17;add_test;D:/Projects/Example/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(ExampleTest "D:/Projects/Example/build/test/MinSizeRel/ExampleTest.exe")
  set_tests_properties(ExampleTest PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/Example/test/CMakeLists.txt;17;add_test;D:/Projects/Example/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(ExampleTest "D:/Projects/Example/build/test/RelWithDebInfo/ExampleTest.exe")
  set_tests_properties(ExampleTest PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/Example/test/CMakeLists.txt;17;add_test;D:/Projects/Example/test/CMakeLists.txt;0;")
else()
  add_test(ExampleTest NOT_AVAILABLE)
endif()

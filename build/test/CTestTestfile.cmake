# CMake generated Testfile for 
# Source directory: D:/Projects/Game/test
# Build directory: D:/Projects/Game/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Tests "D:/Projects/Game/build/test/Debug/Tests.exe")
  set_tests_properties(Tests PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/Game/test/CMakeLists.txt;17;add_test;D:/Projects/Game/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Tests "D:/Projects/Game/build/test/Release/Tests.exe")
  set_tests_properties(Tests PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/Game/test/CMakeLists.txt;17;add_test;D:/Projects/Game/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Tests "D:/Projects/Game/build/test/MinSizeRel/Tests.exe")
  set_tests_properties(Tests PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/Game/test/CMakeLists.txt;17;add_test;D:/Projects/Game/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Tests "D:/Projects/Game/build/test/RelWithDebInfo/Tests.exe")
  set_tests_properties(Tests PROPERTIES  _BACKTRACE_TRIPLES "D:/Projects/Game/test/CMakeLists.txt;17;add_test;D:/Projects/Game/test/CMakeLists.txt;0;")
else()
  add_test(Tests NOT_AVAILABLE)
endif()

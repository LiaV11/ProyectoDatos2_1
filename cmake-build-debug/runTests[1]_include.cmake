if(EXISTS "C:/Users/valer/CLionProjects/ProyectoDatos2_1/cmake-build-debug/runTests[1]_tests.cmake")
  include("C:/Users/valer/CLionProjects/ProyectoDatos2_1/cmake-build-debug/runTests[1]_tests.cmake")
else()
  add_test(runTests_NOT_BUILT runTests_NOT_BUILT)
endif()

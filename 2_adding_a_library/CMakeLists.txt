cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial VERSION 1.0)

option(USE_MYMATH "Use custom/hacky math implementation provided herein" ON)

# configure a header file to pass some of the CMake settings to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(USE_MYMATH)
  # add the MathFunctions library
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# add the executable
add_executable(Tutorial tutorial.cxx)

# target_link_libraries(Tutorial PUBLIC MathFunctions)
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}"
# "${PROJECT_SOURCE_DIR}/MathFunctions")
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}"
                                           "${EXTRA_INCLUDES}")

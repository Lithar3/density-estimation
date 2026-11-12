# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "D:/C_project/Laba1/out/build/x64-debug/_deps/matplotplusplus-src")
  file(MAKE_DIRECTORY "D:/C_project/Laba1/out/build/x64-debug/_deps/matplotplusplus-src")
endif()
file(MAKE_DIRECTORY
  "D:/C_project/Laba1/out/build/x64-debug/_deps/matplotplusplus-build"
  "D:/C_project/Laba1/out/build/x64-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix"
  "D:/C_project/Laba1/out/build/x64-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/tmp"
  "D:/C_project/Laba1/out/build/x64-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp"
  "D:/C_project/Laba1/out/build/x64-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src"
  "D:/C_project/Laba1/out/build/x64-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/C_project/Laba1/out/build/x64-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/C_project/Laba1/out/build/x64-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

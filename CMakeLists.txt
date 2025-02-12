cmake_minimum_required(VERSION 3.26)
project(oop)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/Options.cmake)

###############################################################################

# External dependencies with FindPackage (Fixing MySQL Issue)
set(MySQL_INCLUDE_DIR "/usr/include/mysql")
set(MySQL_LIBRARY "/usr/lib/x86_64-linux-gnu/libmysqlclient.so")

###############################################################################

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing name here
add_executable(${PROJECT_NAME}
    main.cpp
    generated/src/connection.cpp
    generated/src/User.cpp
)

include(cmake/CompilerFlags.cmake)

###############################################################################

# Add MySQL headers and link the library
target_include_directories(${PROJECT_NAME} PRIVATE ${MySQL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${MySQL_LIBRARY})

###############################################################################

# Copy binaries to "bin" folder
install(TARGETS ${PROJECT_NAME} DESTINATION ${DESTINATION_DIR})
if(APPLE)
    install(FILES launcher.command DESTINATION ${DESTINATION_DIR})
endif()


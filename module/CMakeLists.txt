add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ../lib/include)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE qrcode)

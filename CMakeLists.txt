cmake_minimum_required(VERSION 3.22)

project(CrowWebServer)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)
find_package(Crow)

# include_directories(${YOUR_CROW_DIRECTORY})  # Replace with your Crow directory path


add_executable(CrowWebServer main.cpp)  # Replace 'main.cpp' with the name of your source file
target_link_libraries(CrowWebServer ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(CrowWebServer PUBLIC Crow::Crow)


add_custom_command( TARGET CrowWebServer POST_BUILD
                    COMMAND size CrowWebServer
                    COMMENT "Printing size information of the executable")
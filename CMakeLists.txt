#Name				: Josef Kundinger-Markhauser
#Student number		: 040824003
#Course				: CST8219 - C++
#Professor's Name	: Eric Torunski
#Assignment due date: December 11 2020
#submission date	: December 9 2020
#File				: CMakeList.txt

cmake_minimum_required (VERSION 3.8)

project ("Assignment")

# Add source to this project's executable.
add_executable (Assignment "Assignment.cpp" "Assignment.h")

# Include the NANA library
target_include_directories(Assignment PUBLIC "nana\\include")

# Define compiler variable
add_definitions(-D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING)
add_definitions(-DNANA_ENABLE_AUDIO)

# Link NANA libraries
target_link_libraries(Assignment "nana_v142_Debug_x64")

target_link_directories(Assignment PUBLIC "nana\\build\\bin")

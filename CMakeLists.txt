cmake_minimum_required(VERSION 3.10)

project(ProjectEuler)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/*/main.c")

foreach(source_file ${SOURCES})
	get_filename_component(folder_name ${source_file} DIRECTORY)
	get_filename_component(folder_name ${folder_name} NAME)
	string(SUBSTRING ${folder_name} 3 -1 folder_name_without_prefix)
	add_executable(${folder_name_without_prefix} ${source_file})
endforeach()

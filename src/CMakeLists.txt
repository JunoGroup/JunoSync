set(HEADER_LIST "${JunoSync_SOURCE_DIR}/include/JunoSync/config.hpp")

add_library(Config config.cpp ${HEADER_LIST})

find_package(libconfig++)

target_include_directories(Config PUBLIC ../include)
target_link_libraries(Config PRIVATE Boost::boost libconfig)

source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
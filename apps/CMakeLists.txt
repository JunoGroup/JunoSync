add_executable(JunoSync junosync.cpp)

target_link_libraries(JunoSync PUBLIC Config Boost::boost)
if(WIN32)
	add_executable(JunoSync junosync.cpp config.cpp stringutils.cpp registry.cpp)
else()
	add_executable(JunoSync junosync.cpp config.cpp stringutils.cpp)
endif()

target_link_libraries(JunoSync Boost::boost)
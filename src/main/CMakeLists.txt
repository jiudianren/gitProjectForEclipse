include_directories(../za )
add_executable(main main.cpp)
target_link_libraries(main za )

install(TARGETS main
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
        RUNTIME DESTINATION ${BIN_INSTALL_DIR})
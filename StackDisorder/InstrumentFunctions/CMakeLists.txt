add_compile_options( -finstrument-functions )
add_compile_options( -g )
add_executable(Instrument Instrument.cpp)

install(TARGETS Instrument
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
        RUNTIME DESTINATION ${BIN_INSTALL_DIR})
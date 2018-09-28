include_directories(../Dynamic)
include_directories(../Graph)
include_directories(../HashTable )
include_directories(../List )
include_directories(../Other)
include_directories(../Skiplist)
include_directories(../Sort)
include_directories(../Tree)


add_executable(DataStructEXE main.cpp )
target_link_libraries(DataStructEXE  Dynamic Graph  List Other Sort Tree )

install(TARGETS DataStructEXE
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
        RUNTIME DESTINATION ${BIN_INSTALL_DIR})
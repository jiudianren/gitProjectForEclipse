#############################################
#project options, include:
#    MT--if current project is run in multi-thread environment
#    BUILD_SHARED_LIBS--default type of libraries(static or shared)
#    DB--project dependent physical database
#    MDB--project dependent memory physical database
#############################################
OPTION(MT "program run in multi-threads mode" ON)
OPTION(BUILD_SHARED_LIBS "libraries build static or shared" ON)



set(CMAKE_SKIP_RPATH TRUE)

#############################################
#ccache support
#############################################
find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    MESSAGE("-- program ccache has been found, do fast compile with ccache.")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

#############################################
#Build object options
#############################################
SET(OBJECT_MODE $ENV{OBJECT_MODE})
MESSAGE(STATUS "OBJECT_MODE " $ENV{OBJECT_MODE})
IF(OBJECT_MODE EQUAL 32)
    MESSAGE("-- ENV{OBJECT_MODE} has been export 32, use object mode 32.")
    ADD_DEFINITIONS(-D_32_BIT_)
    SET(FIND_LIBRARY_USE_LIB64_PATHS OFF)    #switch to mode 32
ELSE()
    MESSAGE("-- ENV{OBJECT_MODE} has not been export 32, use object mode 64.")
    SET(OBJECT_MODE 64)
    ADD_DEFINITIONS(-D_64_BIT_)
    SET(FIND_LIBRARY_USE_LIB64_PATHS  ON)    #switch to mode 64
ENDIF()

IF(UNIT_TEST MATCHES Y)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")    
    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fprofile-arcs -ftest-coverage -lgcov")
ENDIF()

#############################################
#Add definitions to the compiler
#    In addition, 
#    you can also add compile options
#############################################
#ADD_DEFINITIONS(-DDEBUG)
#ADD_DEFINITIONS("-Wall -ansi -pedantic -g")
#############################################
#Internal platform details:
#    along with compiler's info
#    -- such as using gcc on hp-ux .etc..
#############################################
SET(CMAKE_BUILD_ON_VISUAL_STUDIO 0)
IF(WIN32 AND NOT UNIX AND NOT BORLAND AND NOT MINGW)
    SET(CMAKE_BUILD_ON_VISUAL_STUDIO 1)
ENDIF()

SET(PLATFORM_NAME ${CMAKE_C_PLATFORM_ID})
MESSAGE(STATUS "PLATFORM_NAME" ${PLATFORM_NAME})

IF(PLATFORM_NAME MATCHES Linux)
    SET(CMAKE_EXE_LINKER_FLAGS "-Wl,--no-as-needed")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wformat=2 -Wconversion -Wsign-conversion -Wshadow -Wpointer-arith -Waggressive-loop-optimizations -m${OBJECT_MODE}")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wformat=2 -Wconversion -Wsign-conversion -Wshadow -Wpointer-arith -Waggressive-loop-optimizations -m${OBJECT_MODE}")
ELSEIF(PLATFORM_NAME MATCHES HP-UX)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} exec_magic +DD${OBJECT_MODE}")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} exec_magic +DD${OBJECT_MODE}")
ELSEIF(PLATFORM_NAME MATCHES AIX)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -q${OBJECT_MODE} -qrtti -qinfo=dcl:pro:ret:trd -qformat=all")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -q${OBJECT_MODE} -qrtti -qinfo=dcl:pro:ret:trd -qformat=all")
ENDIF()
SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")

#    multi-thread or not                      #
IF(MT)
    ADD_DEFINITIONS(-D_REENTRANT)
ENDIF()



#############################################
#Choose the type of build
#    options are: None Debug Release RelWithDebInfo MinSizeRel Maintainer
#############################################
set(CMAKE_BUILD_TYPE "${CMAKE_BUILD_TYPE}" CACHE STRING
    "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel Maintainer."
    FORCE)
if((NOT CMAKE_BUILD_TYPE) OR (CMAKE_BUILD_TYPE STREQUAL Release))
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()
message(STATUS "CMAKE_BUILD_TYPE:" ${CMAKE_BUILD_TYPE})

#############################################
#set install prefix
#############################################
set(CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}" CACHE STRING
    "Install directory used by install"
    FORCE)
if(NOT CMAKE_INSTALL_PREFIX)
    message(FATAL_ERROR "-DCMAKE_INSTALL_PREFIX= not specified in cmake command!!!")
else()
    message(STATUS "-DCMAKE_INSTALL_PREFIX=" ${CMAKE_INSTALL_PREFIX})
endif()

function(INSTALL_NO_OVERWRITE INSTALL_DIR FILE_NAME)
    find_file(INSTALL_FULL_PATH NAMES ${FILE_NAME} PATHS ${CMAKE_INSTALL_PREFIX}/${INSTALL_DIR}
              NO_DEFAULT_PATH
              NO_CMAKE_ENVIRONMENT_PATH
              NO_CMAKE_PATH
              NO_SYSTEM_ENVIRONMENT_PATH
              NO_CMAKE_SYSTEM_PATH
              NO_CMAKE_FIND_ROOT_PATH)
    if(${INSTALL_FULL_PATH} STREQUAL "INSTALL_FULL_PATH-NOTFOUND")
        message(STATUS ${FILE_NAME} " not found in " ${CMAKE_INSTALL_PREFIX} "/" ${INSTALL_DIR} " install it")
        install(FILES ${FILE_NAME} DESTINATION ${INSTALL_DIR})
    else()
        message(STATUS ${FILE_NAME} " already exists in " ${CMAKE_INSTALL_PREFIX} "/" ${INSTALL_DIR} " no overwrite")
    endif()
    unset(INSTALL_FULL_PATH CACHE)
endfunction(INSTALL_NO_OVERWRITE)
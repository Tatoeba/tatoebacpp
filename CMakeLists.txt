cmake_minimum_required(VERSION 2.6)

project(tatoebacpp)
include_directories(
    src
)

#TODO #10 replace by a lighter graphic library
#include(FindPkgConfig)
#FIND_PACKAGE( OpenCV REQUIRED )



file(
    GLOB
    controllers_files
    src/controllers/*
    src/controllers/apis/*
    src/controllers/webs/*
    src/controllers/generics/*
)

file(
    GLOB
    models_files
    src/models/*
)

file(
    GLOB
    results_files
    src/results/*
)

file(
    GLOB
    contents_files
    src/contents/*
)


file(
    GLOB
    generics_files
    src/generics/*
)




add_executable(
    tatoeba
    src/tatoeba.cpp
    src/main.cpp
    ${controllers_files}
    ${models_files}
    ${generics_files}
    ${results_files}
    ${contents_files}
    view_web.cpp
)

target_link_libraries(
    tatoeba
    tato
    cppcms
    cppdb
    booster
    sqlite3
    #tokyodystopia
    sphinxclient
    # TODO have lighter dependencies for
    # resizing images
    #opencv_core
    #opencv_highgui
)

#add_executable(
#    indexer
#    src/indexer.cpp
#    src/contents/Config.cpp
#    src/generics/Languages.cpp
#    src/models/TatoDB.cpp
#)

#target_link_libraries(
#    indexer
#    tato
#    cppcms
#    cppdb
#    tokyodystopia
#)
#


add_custom_command(
    OUTPUT view_web.cpp
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tools/cppcms_tmpl_cc 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/views/api/commons/*/*.tmpl 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/views/web/*/*.tmpl 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/views/api/*/*.tmpl 
        -o view_web.cpp
    DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/views/web/*/*.tmpl 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/views/api/*/*.tmpl 
)

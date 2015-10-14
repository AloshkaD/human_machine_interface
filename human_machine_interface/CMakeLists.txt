##############################################################################
# CMake
##############################################################################

cmake_minimum_required(VERSION 2.8.3)
set(PROJECT_NAME human_machine_interface)
project(${PROJECT_NAME} C CXX)

add_definitions(-std=c++11)
##############################################################################
# Catkin
##############################################################################
set(HUMANMACHINEINTERFACE_CONTROLLER_SOURCE_DIR
        src/controller/source)

set(HUMANMACHINEINTERFACE_CONTROLLER_INCLUDE_DIR
        src/controller/include)

set(HUMANMACHINEINTERFACE_VIEW_INCLUDE_DIR
        src/view)


set(HUMANMACHINEINTERFACE_HEADER_FILES
        ${HUMANMACHINEINTERFACE_CONTROLLER_INCLUDE_DIR}/*.h
)

set(HUMANMACHINEINTERFACE_SOURCE_FILES
        ${HUMANMACHINEINTERFACE_CONTROLLER_SOURCE_DIR}/*.cpp

)

set(HUMANMACHINEINTERFACE_HEADER_FILES
        ${HUMANMACHINEINTERFACE_VIEW_INCLUDE_DIR}/*.h
)



find_package(catkin REQUIRED COMPONENTS droneMsgsROS rviz roscpp image_transport  cv_bridge std_msgs geometry_msgs)
catkin_package(INCLUDE_DIRS ${HUMANMACHINEINTERFACE_INCLUDE_DIR} ${HUMANMACHINEINTERFACE_INCLUDE_DIR} CATKIN_DEPENDS)

include_directories(${HUMANMACHINEINTERFACE_INCLUDE_DIR})
include_directories(${catkin_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})
##############################################################################
# OpenSceneGraph
##############################################################################
FIND_PATH(OSG_INCLUDE_DIR osg/Node
            ${OSG_DIR}/include
            $ENV{OSG_DIR}/include
            $ENV{OSG_DIR}
            $ENV{OSGDIR}/include
            $ENV{OSGDIR}
            $ENV{OSG_ROOT}/include
            NO_DEFAULT_PATH
        )

FIND_PATH(OSG_INCLUDE_DIR osg/Node)
MACRO(FIND_OSG_LIBRARY MYLIBRARY MYLIBRARYNAME)
FIND_LIBRARY("${MYLIBRARY}_DEBUG"
           NAMES "${MYLIBRARYNAME}${CMAKE_DEBUG_POSTFIX}"
           PATHS
           ${OSG_DIR}/lib/Debug
           ${OSG_DIR}/lib64/Debug
           ${OSG_DIR}/lib
           ${OSG_DIR}/lib64
           $ENV{OSG_DIR}/lib/debug
           $ENV{OSG_DIR}/lib64/debug
           $ENV{OSG_DIR}/lib
           $ENV{OSG_DIR}/lib64
           $ENV{OSG_DIR}
           $ENV{OSGDIR}/lib
           $ENV{OSGDIR}/lib64
           $ENV{OSGDIR}
           $ENV{OSG_ROOT}/lib
           $ENV{OSG_ROOT}/lib64
           NO_DEFAULT_PATH
           )
FIND_LIBRARY("${MYLIBRARY}_DEBUG"
           NAMES "${MYLIBRARYNAME}${CMAKE_DEBUG_POSTFIX}"
           PATHS
           ~/Library/Frameworks
           /Library/Frameworks
           /usr/local/lib
           /usr/local/lib64
           /usr/lib
           /usr/lib64
           /sw/lib
           /opt/local/lib
           /opt/csw/lib
           /opt/lib
           [HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session\ Manager\\Environment;OSG_ROOT]/lib
           /usr/freeware/lib64
           )
FIND_LIBRARY(${MYLIBRARY}
           NAMES ${MYLIBRARYNAME}
           PATHS
           ${OSG_DIR}/lib/Release
           ${OSG_DIR}/lib64/Release
           ${OSG_DIR}/lib
           ${OSG_DIR}/lib64
           $ENV{OSG_DIR}/lib/Release
           $ENV{OSG_DIR}/lib64/Release
           $ENV{OSG_DIR}/lib
           $ENV{OSG_DIR}/lib64
           $ENV{OSG_DIR}
           $ENV{OSGDIR}/lib
           $ENV{OSGDIR}/lib64
           $ENV{OSGDIR}
           $ENV{OSG_ROOT}/lib
           $ENV{OSG_ROOT}/lib64
           NO_DEFAULT_PATH
           )
FIND_LIBRARY(${MYLIBRARY}
           NAMES ${MYLIBRARYNAME}
           PATHS
           ~/Library/Frameworks
           /Library/Frameworks
           /usr/local/lib
           /usr/local/lib64
           /usr/lib
           /usr/lib64
           /sw/lib
           /opt/local/lib
           /opt/csw/lib
           /opt/lib
           [HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session\ Manager\\Environment;OSG_ROOT]/lib
           /usr/freeware/lib64
            )

            IF( NOT ${MYLIBRARY}_DEBUG)
                IF(MYLIBRARY)
                    SET(${MYLIBRARY}_DEBUG ${MYLIBRARY})
                 ENDIF(MYLIBRARY)
            ENDIF( NOT ${MYLIBRARY}_DEBUG)


ENDMACRO(FIND_OSG_LIBRARY LIBRARY LIBRARYNAME)
FIND_OSG_LIBRARY(OSG_LIBRARY osg)
FIND_OSG_LIBRARY(OSGGA_LIBRARY osgGA)
FIND_OSG_LIBRARY(OSGUTIL_LIBRARY osgUtil)
FIND_OSG_LIBRARY(OSGDB_LIBRARY osgDB)
FIND_OSG_LIBRARY(OSGTEXT_LIBRARY osgText)
FIND_OSG_LIBRARY(OSGWIDGET_LIBRARY osgWidget)
FIND_OSG_LIBRARY(OSGTERRAIN_LIBRARY osgTerrain)
FIND_OSG_LIBRARY(OSGFX_LIBRARY osgFX)
FIND_OSG_LIBRARY(OSGVIEWER_LIBRARY osgViewer)
FIND_OSG_LIBRARY(OSGVOLUME_LIBRARY osgVolume)
FIND_OSG_LIBRARY(OPENTHREADS_LIBRARY OpenThreads)
FIND_OSG_LIBRARY(OSGANIMATION_LIBRARY osgAnimation)
FIND_OSG_LIBRARY(OSGMANIPULATOR_LIBRARY osgManipulator)
FIND_OSG_LIBRARY(OSGPARTICLE_LIBRARY osgParticle)
FIND_OSG_LIBRARY(OSGSHADOW_LIBRARY osgShadow)
FIND_OSG_LIBRARY(OSGSIM_LIBRARY osgSim)
FIND_OSG_LIBRARY(OSGQT_LIBRARY osgQt)

# check required dependencies
find_package(Boost REQUIRED)
find_package(ZLIB REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)

find_package(OpenSceneGraph 3.2.2 REQUIRED osg osgQt osgAnimation osgDB osgFX osgGA osgManipulator osgParticle osgShadow osgSim osgTerrain osgText osgUtil osgViewer osgVolume osgWidget)

include_directories(${OPENSCENEGRAPH_INCLUDE_DIRS})

##############################################################################
# Qwt library
##############################################################################

FIND_PATH(QWT_INCLUDE_DIR NAMES qwt.h PATHS
  /usr/include
  /usr/local/include
  "$ENV{LIB_DIR}/include"
  "$ENV{INCLUDE}"
  PATH_SUFFIXES qwt6 qwt-qt4 qwt qwt5
  )

FIND_LIBRARY(QWT_LIBRARY NAMES  qwt6 qwt qwt5 qwt-qt4 qwt5-qt4 PATHS
  /usr/lib
  /usr/local/lib
  "$ENV{LIB_DIR}/lib"
  "$ENV{LIB}/lib"
  )

IF (QWT_INCLUDE_DIR AND QWT_LIBRARY)
  SET(QWT_FOUND TRUE)
ENDIF (QWT_INCLUDE_DIR AND QWT_LIBRARY)

IF (QWT_FOUND)
  IF (NOT QWT_FIND_QUIETLY)
    MESSAGE(STATUS "Found Qwt: ${QWT_LIBRARY}")
  ENDIF (NOT QWT_FIND_QUIETLY)
ELSE (QWT_FOUND)
  IF (QWT_FIND_REQUIRED)
    MESSAGE(FATAL_ERROR "Could not find Qwt")
  ENDIF (QWT_FIND_REQUIRED)
ENDIF (QWT_FOUND)


include_directories(${QWT_INCLUDE_DIR})
link_directories(${QWT_LIBRARY})

##############################################################################
# Qt Environment
##############################################################################

# included via the dependency call in package.xml
find_package(Qt4 COMPONENTS QtCore QtGui QtSvg QtOpenGL REQUIRED)
include(${QT_USE_FILE})

## to avoid conflict with boost signals it is needed to define QT_NO_KEYWORDS.
add_definitions(-DQT_NO_KEYWORDS)
ADD_DEFINITIONS(${QT_DEFINITIONS})

##############################################################################
# Sections
##############################################################################

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/view/ui/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/view/resources/*.qrc)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS  src/controller/include/*.h)


QT4_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
QT4_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

include_directories(${CMAKE_CURRENT_BINARY_DIR})

##############################################################################
# Sources
##############################################################################

file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/controller/source/*.cpp)


##############################################################################
# Binaries
##############################################################################


MESSAGE(STATUS "Found Qt:  ${QT_LIBRARIES} ")
add_executable(human_machine_interface ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_MOC_HPP} ${QT_FORMS_HPP})
target_link_libraries(human_machine_interface ${OPENSCENEGRAPH_LIBRARIES}  ${QWT_LIBRARY} ${QT_LIBRARIES} ${catkin_LIBRARIES} )
install(TARGETS human_machine_interface RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

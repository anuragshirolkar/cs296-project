# Install script for directory: /users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "../../../../external")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D" TYPE FILE FILES "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Box2D.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Collision" TYPE FILE FILES
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/b2BroadPhase.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/b2Collision.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/b2Distance.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/b2DynamicTree.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/b2TimeOfImpact.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Collision/Shapes" TYPE FILE FILES
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2CircleShape.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2EdgeShape.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2ChainShape.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2PolygonShape.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2Shape.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Common" TYPE FILE FILES
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2BlockAllocator.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2Draw.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2GrowableStack.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2Math.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2Settings.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2StackAllocator.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2Timer.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Dynamics" TYPE FILE FILES
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2Body.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2ContactManager.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2Fixture.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2Island.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2TimeStep.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2World.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2WorldCallbacks.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Dynamics/Contacts" TYPE FILE FILES
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2CircleContact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2Contact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2ContactSolver.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2PolygonContact.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Dynamics/Joints" TYPE FILE FILES
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2DistanceJoint.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2FrictionJoint.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2GearJoint.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2Joint.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2MotorJoint.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2MouseJoint.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2PrismaticJoint.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2PulleyJoint.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2RevoluteJoint.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2RopeJoint.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2WeldJoint.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2WheelJoint.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Rope" TYPE FILE FILES "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Rope/b2Rope.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/buildcs296/Box2D/libBox2D.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets.cmake")
    FILE(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets.cmake"
         "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/buildcs296/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets.cmake")
    IF(EXPORT_FILE_CHANGED)
      FILE(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets-*.cmake")
      IF(OLD_CONFIG_FILES)
        MESSAGE(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        FILE(REMOVE ${OLD_CONFIG_FILES})
      ENDIF(OLD_CONFIG_FILES)
    ENDIF(EXPORT_FILE_CHANGED)
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/buildcs296/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets.cmake")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/buildcs296/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets-noconfig.cmake")
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Box2DConfig.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")


<<<<<<< HEAD
# Install script for directory: /home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D
=======
# Install script for directory: /users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D
>>>>>>> 5efaffe435e615eb1338796bfb9fb713f20ef4ce

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
<<<<<<< HEAD
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D" TYPE FILE FILES "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Box2D.h")
=======
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D" TYPE FILE FILES "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Box2D.h")
>>>>>>> 5efaffe435e615eb1338796bfb9fb713f20ef4ce
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Collision" TYPE FILE FILES
<<<<<<< HEAD
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Collision/b2BroadPhase.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Collision/b2Collision.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Collision/b2Distance.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Collision/b2DynamicTree.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Collision/b2TimeOfImpact.h"
=======
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/b2BroadPhase.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/b2Collision.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/b2Distance.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/b2DynamicTree.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/b2TimeOfImpact.h"
>>>>>>> 5efaffe435e615eb1338796bfb9fb713f20ef4ce
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Collision/Shapes" TYPE FILE FILES
<<<<<<< HEAD
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2CircleShape.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2EdgeShape.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2ChainShape.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2PolygonShape.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2Shape.h"
=======
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2CircleShape.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2EdgeShape.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2ChainShape.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2PolygonShape.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Collision/Shapes/b2Shape.h"
>>>>>>> 5efaffe435e615eb1338796bfb9fb713f20ef4ce
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Common" TYPE FILE FILES
<<<<<<< HEAD
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Common/b2BlockAllocator.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Common/b2Draw.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Common/b2GrowableStack.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Common/b2Math.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Common/b2Settings.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Common/b2StackAllocator.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Common/b2Timer.h"
=======
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2BlockAllocator.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2Draw.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2GrowableStack.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2Math.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2Settings.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2StackAllocator.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Common/b2Timer.h"
>>>>>>> 5efaffe435e615eb1338796bfb9fb713f20ef4ce
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Dynamics" TYPE FILE FILES
<<<<<<< HEAD
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2Body.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2ContactManager.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2Fixture.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2Island.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2TimeStep.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2World.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2WorldCallbacks.h"
=======
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2Body.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2ContactManager.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2Fixture.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2Island.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2TimeStep.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2World.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/b2WorldCallbacks.h"
>>>>>>> 5efaffe435e615eb1338796bfb9fb713f20ef4ce
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Dynamics/Contacts" TYPE FILE FILES
<<<<<<< HEAD
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2CircleContact.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2Contact.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2ContactSolver.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2PolygonContact.h"
=======
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2CircleContact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2Contact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2ContactSolver.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h"
    "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Contacts/b2PolygonContact.h"
>>>>>>> 5efaffe435e615eb1338796bfb9fb713f20ef4ce
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Dynamics/Joints" TYPE FILE FILES
<<<<<<< HEAD
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2DistanceJoint.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2FrictionJoint.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2GearJoint.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2Joint.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2MotorJoint.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2MouseJoint.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2PrismaticJoint.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2PulleyJoint.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2RevoluteJoint.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2RopeJoint.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2WeldJoint.h"
    "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Dynamics/Joints/b2WheelJoint.h"
=======
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
>>>>>>> 5efaffe435e615eb1338796bfb9fb713f20ef4ce
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
<<<<<<< HEAD
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Rope" TYPE FILE FILES "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Rope/b2Rope.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/buildcs296/Box2D/libBox2D.a")
=======
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Box2D/Rope" TYPE FILE FILES "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Rope/b2Rope.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/buildcs296/Box2D/libBox2D.a")
>>>>>>> 5efaffe435e615eb1338796bfb9fb713f20ef4ce
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets.cmake")
    FILE(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets.cmake"
<<<<<<< HEAD
         "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/buildcs296/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets.cmake")
=======
         "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/buildcs296/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets.cmake")
>>>>>>> 5efaffe435e615eb1338796bfb9fb713f20ef4ce
    IF(EXPORT_FILE_CHANGED)
      FILE(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets-*.cmake")
      IF(OLD_CONFIG_FILES)
        MESSAGE(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/Box2D/Box2D-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        FILE(REMOVE ${OLD_CONFIG_FILES})
      ENDIF(OLD_CONFIG_FILES)
    ENDIF(EXPORT_FILE_CHANGED)
  ENDIF()
<<<<<<< HEAD
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/buildcs296/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets.cmake")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/buildcs296/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets-noconfig.cmake")
=======
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/buildcs296/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets.cmake")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/buildcs296/Box2D/CMakeFiles/Export/lib/Box2D/Box2D-targets-noconfig.cmake")
>>>>>>> 5efaffe435e615eb1338796bfb9fb713f20ef4ce
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
<<<<<<< HEAD
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/home/anuragshirolkar/Desktop/project/cs296_base_code/external/src/Box2D/Box2D/Box2DConfig.cmake")
=======
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/Box2D" TYPE FILE FILES "/users/ug12/anuragshirolkar/Desktop/project/workspace/cs296_base_code/external/src/Box2D/Box2D/Box2DConfig.cmake")
>>>>>>> 5efaffe435e615eb1338796bfb9fb713f20ef4ce
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")


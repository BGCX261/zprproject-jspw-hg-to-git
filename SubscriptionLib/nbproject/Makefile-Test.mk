#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=
AS=as.exe

# Macros
CND_PLATFORM=Cygwin-Windows
CND_CONF=Test
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Response.o \
	${OBJECTDIR}/src/AuthResponse.o \
	${OBJECTDIR}/src/ClientVisitor.o \
	${OBJECTDIR}/src/Request.o \
	${OBJECTDIR}/src/Archive.o \
	${OBJECTDIR}/src/ServerVisitor.o \
	${OBJECTDIR}/src/NewMsgResponse.o \
	${OBJECTDIR}/test/main.o \
	${OBJECTDIR}/src/SubsRequest.o \
	${OBJECTDIR}/src/AuthRequest.o \
	${OBJECTDIR}/src/ExceptionLib.o \
	${OBJECTDIR}/src/UsubRequest.o \
	${OBJECTDIR}/src/Message.o \
	${OBJECTDIR}/src/StringArchive.o \
	${OBJECTDIR}/src/UsubResponse.o \
	${OBJECTDIR}/src/SubsResponse.o \
	${OBJECTDIR}/src/NewMsgRequest.o \
	${OBJECTDIR}/src/MsgResponse.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../../boost_lib/cygboost_system-mt-1_43.dll ../../boost_lib/cygboost_unit_test_framework-mt-1_43.dll

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Test.mk dist/Test/Cygwin-Windows/subscriptionlib.exe

dist/Test/Cygwin-Windows/subscriptionlib.exe: ../../boost_lib/cygboost_system-mt-1_43.dll

dist/Test/Cygwin-Windows/subscriptionlib.exe: ../../boost_lib/cygboost_unit_test_framework-mt-1_43.dll

dist/Test/Cygwin-Windows/subscriptionlib.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Test/Cygwin-Windows
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/subscriptionlib ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/Response.o: src/Response.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Response.o src/Response.cpp

${OBJECTDIR}/src/AuthResponse.o: src/AuthResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/AuthResponse.o src/AuthResponse.cpp

${OBJECTDIR}/src/ClientVisitor.o: src/ClientVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ClientVisitor.o src/ClientVisitor.cpp

${OBJECTDIR}/src/Request.o: src/Request.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Request.o src/Request.cpp

${OBJECTDIR}/src/Archive.o: src/Archive.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Archive.o src/Archive.cpp

${OBJECTDIR}/src/ServerVisitor.o: src/ServerVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ServerVisitor.o src/ServerVisitor.cpp

${OBJECTDIR}/src/NewMsgResponse.o: src/NewMsgResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/NewMsgResponse.o src/NewMsgResponse.cpp

${OBJECTDIR}/test/main.o: test/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/test
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/test/main.o test/main.cpp

${OBJECTDIR}/src/SubsRequest.o: src/SubsRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/SubsRequest.o src/SubsRequest.cpp

${OBJECTDIR}/src/AuthRequest.o: src/AuthRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/AuthRequest.o src/AuthRequest.cpp

${OBJECTDIR}/src/ExceptionLib.o: src/ExceptionLib.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ExceptionLib.o src/ExceptionLib.cpp

${OBJECTDIR}/src/UsubRequest.o: src/UsubRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/UsubRequest.o src/UsubRequest.cpp

${OBJECTDIR}/src/Message.o: src/Message.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Message.o src/Message.cpp

${OBJECTDIR}/src/StringArchive.o: src/StringArchive.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/StringArchive.o src/StringArchive.cpp

${OBJECTDIR}/src/UsubResponse.o: src/UsubResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/UsubResponse.o src/UsubResponse.cpp

${OBJECTDIR}/src/SubsResponse.o: src/SubsResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/SubsResponse.o src/SubsResponse.cpp

${OBJECTDIR}/src/NewMsgRequest.o: src/NewMsgRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/NewMsgRequest.o src/NewMsgRequest.cpp

${OBJECTDIR}/src/MsgResponse.o: src/MsgResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -Wall -Iheaders -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/MsgResponse.o src/MsgResponse.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Test
	${RM} dist/Test/Cygwin-Windows/subscriptionlib.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

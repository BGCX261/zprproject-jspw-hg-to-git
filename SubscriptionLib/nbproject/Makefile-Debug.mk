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
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/AuthResponse.o \
	${OBJECTDIR}/src/Response.o \
	${OBJECTDIR}/src/Request.o \
	${OBJECTDIR}/src/Serializeable.o \
	${OBJECTDIR}/src/NewMsgRequestr.o \
	${OBJECTDIR}/src/AuthRequest.o \
	${OBJECTDIR}/src/SubsRequest.o \
	${OBJECTDIR}/src/UsubRequest.o \
	${OBJECTDIR}/src/Message.o \
	${OBJECTDIR}/src/UsubResponse.o \
	${OBJECTDIR}/src/Library.o \
	${OBJECTDIR}/src/SubsResponse.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk dist/Debug/Cygwin-Windows/libsubscriptionlib.a

dist/Debug/Cygwin-Windows/libsubscriptionlib.a: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/Cygwin-Windows
	${RM} dist/Debug/Cygwin-Windows/libsubscriptionlib.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsubscriptionlib.a ${OBJECTFILES} 
	$(RANLIB) dist/Debug/Cygwin-Windows/libsubscriptionlib.a

${OBJECTDIR}/src/AuthResponse.o: src/AuthResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -Iheaders -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/AuthResponse.o src/AuthResponse.cpp

${OBJECTDIR}/src/Response.o: src/Response.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -Iheaders -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Response.o src/Response.cpp

${OBJECTDIR}/src/Request.o: src/Request.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -Iheaders -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Request.o src/Request.cpp

${OBJECTDIR}/src/Serializeable.o: src/Serializeable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -Iheaders -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Serializeable.o src/Serializeable.cpp

${OBJECTDIR}/src/NewMsgRequestr.o: src/NewMsgRequestr.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -Iheaders -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/NewMsgRequestr.o src/NewMsgRequestr.cpp

${OBJECTDIR}/src/AuthRequest.o: src/AuthRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -Iheaders -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/AuthRequest.o src/AuthRequest.cpp

${OBJECTDIR}/src/SubsRequest.o: src/SubsRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -Iheaders -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/SubsRequest.o src/SubsRequest.cpp

${OBJECTDIR}/src/UsubRequest.o: src/UsubRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -Iheaders -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/UsubRequest.o src/UsubRequest.cpp

${OBJECTDIR}/src/Message.o: src/Message.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -Iheaders -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Message.o src/Message.cpp

${OBJECTDIR}/src/UsubResponse.o: src/UsubResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -Iheaders -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/UsubResponse.o src/UsubResponse.cpp

${OBJECTDIR}/src/Library.o: src/Library.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -Iheaders -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Library.o src/Library.cpp

${OBJECTDIR}/src/SubsResponse.o: src/SubsResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -Iheaders -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/SubsResponse.o src/SubsResponse.cpp

${OBJECTDIR}/src/MsgResponse.o: src/MsgResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Isrc -Iheaders -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/MsgResponse.o src/MsgResponse.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/Cygwin-Windows/libsubscriptionlib.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

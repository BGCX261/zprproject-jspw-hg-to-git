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
	${OBJECTDIR}/_ext/1877225195/Interpreter.o \
	${OBJECTDIR}/src/DiscCommand.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/SubsCommand.o \
	${OBJECTDIR}/src/CreateCommand.o \
	${OBJECTDIR}/src/AuthCommand.o \
	${OBJECTDIR}/src/UsubCommand.o \
	${OBJECTDIR}/_ext/1877225195/Configuration.o


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
LDLIBSOPTIONS=-L../../boost-lib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk dist/Debug/Cygwin-Windows/client.exe

dist/Debug/Cygwin-Windows/client.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/Cygwin-Windows
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/client ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1877225195/Interpreter.o: /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Interpreter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1877225195
	${RM} $@.d
	$(COMPILE.cc) -g -Iheaders -Isrc -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1877225195/Interpreter.o /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Interpreter.cpp

${OBJECTDIR}/src/DiscCommand.o: src/DiscCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iheaders -Isrc -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/DiscCommand.o src/DiscCommand.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Iheaders -Isrc -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/SubsCommand.o: src/SubsCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iheaders -Isrc -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/SubsCommand.o src/SubsCommand.cpp

${OBJECTDIR}/src/CreateCommand.o: src/CreateCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iheaders -Isrc -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CreateCommand.o src/CreateCommand.cpp

${OBJECTDIR}/src/AuthCommand.o: src/AuthCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iheaders -Isrc -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/AuthCommand.o src/AuthCommand.cpp

${OBJECTDIR}/src/UsubCommand.o: src/UsubCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iheaders -Isrc -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/UsubCommand.o src/UsubCommand.cpp

${OBJECTDIR}/_ext/1877225195/Configuration.o: /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Configuration.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1877225195
	${RM} $@.d
	$(COMPILE.cc) -g -Iheaders -Isrc -I../../boost -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1877225195/Configuration.o /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Configuration.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/Cygwin-Windows/client.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

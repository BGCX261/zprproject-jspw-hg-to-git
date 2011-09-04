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
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/972419214/Request.o \
	${OBJECTDIR}/src/NewMsgCommand.o \
	${OBJECTDIR}/src/Client.o \
	${OBJECTDIR}/_ext/1877225195/Pool.o \
	${OBJECTDIR}/src/IoService.o \
	${OBJECTDIR}/src/DiscCommand.o \
	${OBJECTDIR}/_ext/1877225195/Interpreter.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/_ext/972419214/NewMsgRequest.o \
	${OBJECTDIR}/_ext/972419214/Archive.o \
	${OBJECTDIR}/_ext/972419214/ClientVisitor.o \
	${OBJECTDIR}/_ext/1877225195/Terminal.o \
	${OBJECTDIR}/_ext/1877225195/CmdFactory.o \
	${OBJECTDIR}/_ext/972419214/UsubResponse.o \
	${OBJECTDIR}/src/SubsCommand.o \
	${OBJECTDIR}/_ext/972419214/MsgResponse.o \
	${OBJECTDIR}/src/CreateCommand.o \
	${OBJECTDIR}/_ext/1877225195/Application.o \
	${OBJECTDIR}/src/AuthCommand.o \
	${OBJECTDIR}/src/UsubCommand.o \
	${OBJECTDIR}/_ext/972419214/StringArchive.o \
	${OBJECTDIR}/_ext/972419214/AuthResponse.o \
	${OBJECTDIR}/_ext/972419214/SubsResponse.o \
	${OBJECTDIR}/src/ConditionVariable.o \
	${OBJECTDIR}/_ext/1877225195/CommandThread.o \
	${OBJECTDIR}/_ext/972419214/UsubRequest.o \
	${OBJECTDIR}/_ext/1877225195/Configuration.o \
	${OBJECTDIR}/_ext/1877225195/Queue.o \
	${OBJECTDIR}/_ext/972419214/ServerVisitor.o \
	${OBJECTDIR}/_ext/1877225195/ExceptionClient.o \
	${OBJECTDIR}/_ext/972419214/AuthRequest.o \
	${OBJECTDIR}/_ext/972419214/ExceptionLib.o \
	${OBJECTDIR}/_ext/972419214/Response.o \
	${OBJECTDIR}/_ext/972419214/NewMsgResponse.o \
	${OBJECTDIR}/src/Command.o \
	${OBJECTDIR}/src/Visitor.o \
	${OBJECTDIR}/_ext/972419214/SubsRequest.o \
	${OBJECTDIR}/_ext/972419214/Message.o \
	${OBJECTDIR}/_ext/1877225195/Thread.o


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
	"${MAKE}"  -f nbproject/Makefile-Release.mk dist/Release/Cygwin-Windows/client.exe

dist/Release/Cygwin-Windows/client.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Release/Cygwin-Windows
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/client ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/972419214/Request.o: ../SubscriptionLib/src/Request.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/Request.o ../SubscriptionLib/src/Request.cpp

${OBJECTDIR}/src/NewMsgCommand.o: src/NewMsgCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/NewMsgCommand.o src/NewMsgCommand.cpp

${OBJECTDIR}/src/Client.o: src/Client.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Client.o src/Client.cpp

${OBJECTDIR}/_ext/1877225195/Pool.o: /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Pool.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1877225195
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1877225195/Pool.o /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Pool.cpp

${OBJECTDIR}/src/IoService.o: src/IoService.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/IoService.o src/IoService.cpp

${OBJECTDIR}/src/DiscCommand.o: src/DiscCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/DiscCommand.o src/DiscCommand.cpp

${OBJECTDIR}/_ext/1877225195/Interpreter.o: /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Interpreter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1877225195
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1877225195/Interpreter.o /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Interpreter.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/_ext/972419214/NewMsgRequest.o: ../SubscriptionLib/src/NewMsgRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/NewMsgRequest.o ../SubscriptionLib/src/NewMsgRequest.cpp

${OBJECTDIR}/_ext/972419214/Archive.o: ../SubscriptionLib/src/Archive.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/Archive.o ../SubscriptionLib/src/Archive.cpp

${OBJECTDIR}/_ext/972419214/ClientVisitor.o: ../SubscriptionLib/src/ClientVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/ClientVisitor.o ../SubscriptionLib/src/ClientVisitor.cpp

${OBJECTDIR}/_ext/1877225195/Terminal.o: /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Terminal.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1877225195
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1877225195/Terminal.o /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Terminal.cpp

${OBJECTDIR}/_ext/1877225195/CmdFactory.o: /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/CmdFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1877225195
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1877225195/CmdFactory.o /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/CmdFactory.cpp

${OBJECTDIR}/_ext/972419214/UsubResponse.o: ../SubscriptionLib/src/UsubResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/UsubResponse.o ../SubscriptionLib/src/UsubResponse.cpp

${OBJECTDIR}/src/SubsCommand.o: src/SubsCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/SubsCommand.o src/SubsCommand.cpp

${OBJECTDIR}/_ext/972419214/MsgResponse.o: ../SubscriptionLib/src/MsgResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/MsgResponse.o ../SubscriptionLib/src/MsgResponse.cpp

${OBJECTDIR}/src/CreateCommand.o: src/CreateCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CreateCommand.o src/CreateCommand.cpp

${OBJECTDIR}/_ext/1877225195/Application.o: /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1877225195
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1877225195/Application.o /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Application.cpp

${OBJECTDIR}/src/AuthCommand.o: src/AuthCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/AuthCommand.o src/AuthCommand.cpp

${OBJECTDIR}/src/UsubCommand.o: src/UsubCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/UsubCommand.o src/UsubCommand.cpp

${OBJECTDIR}/_ext/972419214/StringArchive.o: ../SubscriptionLib/src/StringArchive.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/StringArchive.o ../SubscriptionLib/src/StringArchive.cpp

${OBJECTDIR}/_ext/972419214/AuthResponse.o: ../SubscriptionLib/src/AuthResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/AuthResponse.o ../SubscriptionLib/src/AuthResponse.cpp

${OBJECTDIR}/_ext/972419214/SubsResponse.o: ../SubscriptionLib/src/SubsResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/SubsResponse.o ../SubscriptionLib/src/SubsResponse.cpp

${OBJECTDIR}/src/ConditionVariable.o: src/ConditionVariable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ConditionVariable.o src/ConditionVariable.cpp

${OBJECTDIR}/_ext/1877225195/CommandThread.o: /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/CommandThread.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1877225195
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1877225195/CommandThread.o /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/CommandThread.cpp

${OBJECTDIR}/_ext/972419214/UsubRequest.o: ../SubscriptionLib/src/UsubRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/UsubRequest.o ../SubscriptionLib/src/UsubRequest.cpp

${OBJECTDIR}/_ext/1877225195/Configuration.o: /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Configuration.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1877225195
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1877225195/Configuration.o /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Configuration.cpp

${OBJECTDIR}/_ext/1877225195/Queue.o: /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Queue.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1877225195
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1877225195/Queue.o /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Queue.cpp

${OBJECTDIR}/_ext/972419214/ServerVisitor.o: ../SubscriptionLib/src/ServerVisitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/ServerVisitor.o ../SubscriptionLib/src/ServerVisitor.cpp

${OBJECTDIR}/_ext/1877225195/ExceptionClient.o: /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/ExceptionClient.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1877225195
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1877225195/ExceptionClient.o /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/ExceptionClient.cpp

${OBJECTDIR}/_ext/972419214/AuthRequest.o: ../SubscriptionLib/src/AuthRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/AuthRequest.o ../SubscriptionLib/src/AuthRequest.cpp

${OBJECTDIR}/_ext/972419214/ExceptionLib.o: ../SubscriptionLib/src/ExceptionLib.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/ExceptionLib.o ../SubscriptionLib/src/ExceptionLib.cpp

${OBJECTDIR}/_ext/972419214/Response.o: ../SubscriptionLib/src/Response.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/Response.o ../SubscriptionLib/src/Response.cpp

${OBJECTDIR}/_ext/972419214/NewMsgResponse.o: ../SubscriptionLib/src/NewMsgResponse.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/NewMsgResponse.o ../SubscriptionLib/src/NewMsgResponse.cpp

${OBJECTDIR}/src/Command.o: src/Command.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Command.o src/Command.cpp

${OBJECTDIR}/src/Visitor.o: src/Visitor.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Visitor.o src/Visitor.cpp

${OBJECTDIR}/_ext/972419214/SubsRequest.o: ../SubscriptionLib/src/SubsRequest.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/SubsRequest.o ../SubscriptionLib/src/SubsRequest.cpp

${OBJECTDIR}/_ext/972419214/Message.o: ../SubscriptionLib/src/Message.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/972419214
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/972419214/Message.o ../SubscriptionLib/src/Message.cpp

${OBJECTDIR}/_ext/1877225195/Thread.o: /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Thread.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1877225195
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1877225195/Thread.o /cygdrive/G/Programowanie/ProjektyStudia/ZPR/zprproject-jspw/Client/src/Thread.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/Cygwin-Windows/client.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

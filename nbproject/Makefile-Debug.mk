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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Connection.o \
	${OBJECTDIR}/MainApp.o \
	${OBJECTDIR}/MainFrm.o \
	${OBJECTDIR}/TestEmberTree.o \
	${OBJECTDIR}/emberp.o \
	${OBJECTDIR}/emberplus_icon.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=`wx-config --cxxflags` 
CXXFLAGS=`wx-config --cxxflags` 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`wx-config --libs`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test02-emberplus

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test02-emberplus: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test02-emberplus ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Connection.o: Connection.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libember/Headers/ember -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libs101/Headers/s101 -I../../../ember-plus-1.8.2/libember/Headers/ember -I../../../ember-plus-1.8.2/libs101/Headers/s101 -std=c++17 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Connection.o Connection.cpp

${OBJECTDIR}/MainApp.o: MainApp.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libember/Headers/ember -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libs101/Headers/s101 -I../../../ember-plus-1.8.2/libember/Headers/ember -I../../../ember-plus-1.8.2/libs101/Headers/s101 -std=c++17 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MainApp.o MainApp.cpp

${OBJECTDIR}/MainFrm.o: MainFrm.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libember/Headers/ember -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libs101/Headers/s101 -I../../../ember-plus-1.8.2/libember/Headers/ember -I../../../ember-plus-1.8.2/libs101/Headers/s101 -std=c++17 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MainFrm.o MainFrm.cpp

${OBJECTDIR}/TestEmberTree.o: TestEmberTree.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libember/Headers/ember -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libs101/Headers/s101 -I../../../ember-plus-1.8.2/libember/Headers/ember -I../../../ember-plus-1.8.2/libs101/Headers/s101 -std=c++17 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TestEmberTree.o TestEmberTree.cpp

${OBJECTDIR}/emberp.o: emberp.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libember/Headers/ember -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libs101/Headers/s101 -I../../../ember-plus-1.8.2/libember/Headers/ember -I../../../ember-plus-1.8.2/libs101/Headers/s101 -std=c++17 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/emberp.o emberp.cpp

${OBJECTDIR}/emberplus_icon.o: emberplus_icon.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/emberplus_icon.o emberplus_icon.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

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
CND_PLATFORM=MinGW64-Windows
CND_DLIB_EXT=dll
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
	${OBJECTDIR}/ember.o \
	${OBJECTDIR}/emberplus_icon.o \
	${OBJECTDIR}/tst.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test02-emberplus.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test02-emberplus.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test02-emberplus ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Connection.o: Connection.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libember/Headers/ember -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libs101/Headers/s101 -I../../../ember-plus-1.8.2/libember/Headers/ember -I../../../ember-plus-1.8.2/libs101/Headers/s101 -I../../../../../msys64/home/josepva/ember-plus/libember/Headers/ember -I../../../../../msys64/home/josepva/ember-plus/libs101/Headers/s101 -std=c++17 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Connection.o Connection.cpp

${OBJECTDIR}/MainApp.o: MainApp.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libember/Headers/ember -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libs101/Headers/s101 -I../../../ember-plus-1.8.2/libember/Headers/ember -I../../../ember-plus-1.8.2/libs101/Headers/s101 -I../../../../../msys64/home/josepva/ember-plus/libember/Headers/ember -I../../../../../msys64/home/josepva/ember-plus/libs101/Headers/s101 -std=c++17 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MainApp.o MainApp.cpp

${OBJECTDIR}/MainFrm.o: MainFrm.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libember/Headers/ember -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libs101/Headers/s101 -I../../../ember-plus-1.8.2/libember/Headers/ember -I../../../ember-plus-1.8.2/libs101/Headers/s101 -I../../../../../msys64/home/josepva/ember-plus/libember/Headers/ember -I../../../../../msys64/home/josepva/ember-plus/libs101/Headers/s101 -std=c++17 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MainFrm.o MainFrm.cpp

${OBJECTDIR}/ember.o: ember.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libember/Headers/ember -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libs101/Headers/s101 -I../../../ember-plus-1.8.2/libember/Headers/ember -I../../../ember-plus-1.8.2/libs101/Headers/s101 -I../../../../../msys64/home/josepva/ember-plus/libember/Headers/ember -I../../../../../msys64/home/josepva/ember-plus/libs101/Headers/s101 -std=c++17 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ember.o ember.cpp

${OBJECTDIR}/emberplus_icon.o: emberplus_icon.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/emberplus_icon.o emberplus_icon.c

${OBJECTDIR}/tst.o: tst.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libember/Headers/ember -I/C/msys64/home/SAUD-DEVOPS/ember-plus-1.8.2/libs101/Headers/s101 -I../../../ember-plus-1.8.2/libember/Headers/ember -I../../../ember-plus-1.8.2/libs101/Headers/s101 -I../../../../../msys64/home/josepva/ember-plus/libember/Headers/ember -I../../../../../msys64/home/josepva/ember-plus/libs101/Headers/s101 -std=c++17 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/tst.o tst.cpp

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

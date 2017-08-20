#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-GPIO.mk)" "nbproject/Makefile-local-GPIO.mk"
include nbproject/Makefile-local-GPIO.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=GPIO
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/XCTraining.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/XCTraining.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=--mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=C:/Users/dungl/Documents/GitHub/XC8Training/Source/IntManager.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/I2C.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/DAC.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/ADC.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/IO.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/SPI.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/TMR.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/UART.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/DataConvert.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/DataCrypto.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/Main.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/System.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/SegLCD.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/GPIO.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/91294600/IntManager.p1 ${OBJECTDIR}/_ext/91294600/I2C.p1 ${OBJECTDIR}/_ext/91294600/DAC.p1 ${OBJECTDIR}/_ext/91294600/ADC.p1 ${OBJECTDIR}/_ext/91294600/IO.p1 ${OBJECTDIR}/_ext/91294600/SPI.p1 ${OBJECTDIR}/_ext/91294600/TMR.p1 ${OBJECTDIR}/_ext/91294600/UART.p1 ${OBJECTDIR}/_ext/91294600/DataConvert.p1 ${OBJECTDIR}/_ext/91294600/DataCrypto.p1 ${OBJECTDIR}/_ext/91294600/Main.p1 ${OBJECTDIR}/_ext/91294600/System.p1 ${OBJECTDIR}/_ext/91294600/SegLCD.p1 ${OBJECTDIR}/_ext/91294600/GPIO.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/91294600/IntManager.p1.d ${OBJECTDIR}/_ext/91294600/I2C.p1.d ${OBJECTDIR}/_ext/91294600/DAC.p1.d ${OBJECTDIR}/_ext/91294600/ADC.p1.d ${OBJECTDIR}/_ext/91294600/IO.p1.d ${OBJECTDIR}/_ext/91294600/SPI.p1.d ${OBJECTDIR}/_ext/91294600/TMR.p1.d ${OBJECTDIR}/_ext/91294600/UART.p1.d ${OBJECTDIR}/_ext/91294600/DataConvert.p1.d ${OBJECTDIR}/_ext/91294600/DataCrypto.p1.d ${OBJECTDIR}/_ext/91294600/Main.p1.d ${OBJECTDIR}/_ext/91294600/System.p1.d ${OBJECTDIR}/_ext/91294600/SegLCD.p1.d ${OBJECTDIR}/_ext/91294600/GPIO.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/91294600/IntManager.p1 ${OBJECTDIR}/_ext/91294600/I2C.p1 ${OBJECTDIR}/_ext/91294600/DAC.p1 ${OBJECTDIR}/_ext/91294600/ADC.p1 ${OBJECTDIR}/_ext/91294600/IO.p1 ${OBJECTDIR}/_ext/91294600/SPI.p1 ${OBJECTDIR}/_ext/91294600/TMR.p1 ${OBJECTDIR}/_ext/91294600/UART.p1 ${OBJECTDIR}/_ext/91294600/DataConvert.p1 ${OBJECTDIR}/_ext/91294600/DataCrypto.p1 ${OBJECTDIR}/_ext/91294600/Main.p1 ${OBJECTDIR}/_ext/91294600/System.p1 ${OBJECTDIR}/_ext/91294600/SegLCD.p1 ${OBJECTDIR}/_ext/91294600/GPIO.p1

# Source Files
SOURCEFILES=C:/Users/dungl/Documents/GitHub/XC8Training/Source/IntManager.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/I2C.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/DAC.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/ADC.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/IO.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/SPI.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/TMR.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/UART.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/DataConvert.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/DataCrypto.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/Main.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/System.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/SegLCD.c C:/Users/dungl/Documents/GitHub/XC8Training/Source/GPIO.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-GPIO.mk dist/${CND_CONF}/${IMAGE_TYPE}/XCTraining.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F1936
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/91294600/IntManager.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/IntManager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/IntManager.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/IntManager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/IntManager.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/IntManager.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/IntManager.d ${OBJECTDIR}/_ext/91294600/IntManager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/IntManager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/I2C.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/I2C.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/I2C.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/I2C.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/I2C.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/I2C.d ${OBJECTDIR}/_ext/91294600/I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/DAC.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/DAC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/DAC.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/DAC.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/DAC.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/DAC.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/DAC.d ${OBJECTDIR}/_ext/91294600/DAC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/DAC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/ADC.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/ADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/ADC.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/ADC.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/ADC.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/ADC.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/ADC.d ${OBJECTDIR}/_ext/91294600/ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/IO.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/IO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/IO.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/IO.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/IO.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/IO.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/IO.d ${OBJECTDIR}/_ext/91294600/IO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/IO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/SPI.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/SPI.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/SPI.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/SPI.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/SPI.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/SPI.d ${OBJECTDIR}/_ext/91294600/SPI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/TMR.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/TMR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/TMR.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/TMR.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/TMR.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/TMR.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/TMR.d ${OBJECTDIR}/_ext/91294600/TMR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/TMR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/UART.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/UART.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/UART.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/UART.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/UART.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/UART.d ${OBJECTDIR}/_ext/91294600/UART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/UART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/DataConvert.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/DataConvert.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/DataConvert.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/DataConvert.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/DataConvert.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/DataConvert.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/DataConvert.d ${OBJECTDIR}/_ext/91294600/DataConvert.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/DataConvert.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/DataCrypto.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/DataCrypto.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/DataCrypto.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/DataCrypto.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/DataCrypto.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/DataCrypto.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/DataCrypto.d ${OBJECTDIR}/_ext/91294600/DataCrypto.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/DataCrypto.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/Main.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/Main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/Main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/Main.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/Main.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/Main.d ${OBJECTDIR}/_ext/91294600/Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/System.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/System.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/System.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/System.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/System.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/System.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/System.d ${OBJECTDIR}/_ext/91294600/System.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/System.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/SegLCD.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/SegLCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/SegLCD.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/SegLCD.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/SegLCD.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/SegLCD.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/SegLCD.d ${OBJECTDIR}/_ext/91294600/SegLCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/SegLCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/GPIO.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/GPIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/GPIO.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/GPIO.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/GPIO.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/GPIO.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/GPIO.d ${OBJECTDIR}/_ext/91294600/GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/91294600/IntManager.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/IntManager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/IntManager.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/IntManager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/IntManager.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/IntManager.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/IntManager.d ${OBJECTDIR}/_ext/91294600/IntManager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/IntManager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/I2C.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/I2C.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/I2C.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/I2C.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/I2C.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/I2C.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/I2C.d ${OBJECTDIR}/_ext/91294600/I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/DAC.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/DAC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/DAC.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/DAC.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/DAC.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/DAC.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/DAC.d ${OBJECTDIR}/_ext/91294600/DAC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/DAC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/ADC.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/ADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/ADC.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/ADC.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/ADC.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/ADC.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/ADC.d ${OBJECTDIR}/_ext/91294600/ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/IO.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/IO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/IO.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/IO.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/IO.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/IO.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/IO.d ${OBJECTDIR}/_ext/91294600/IO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/IO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/SPI.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/SPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/SPI.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/SPI.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/SPI.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/SPI.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/SPI.d ${OBJECTDIR}/_ext/91294600/SPI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/TMR.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/TMR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/TMR.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/TMR.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/TMR.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/TMR.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/TMR.d ${OBJECTDIR}/_ext/91294600/TMR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/TMR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/UART.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/UART.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/UART.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/UART.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/UART.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/UART.d ${OBJECTDIR}/_ext/91294600/UART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/UART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/DataConvert.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/DataConvert.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/DataConvert.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/DataConvert.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/DataConvert.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/DataConvert.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/DataConvert.d ${OBJECTDIR}/_ext/91294600/DataConvert.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/DataConvert.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/DataCrypto.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/DataCrypto.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/DataCrypto.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/DataCrypto.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/DataCrypto.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/DataCrypto.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/DataCrypto.d ${OBJECTDIR}/_ext/91294600/DataCrypto.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/DataCrypto.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/Main.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/Main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/Main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/Main.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/Main.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/Main.d ${OBJECTDIR}/_ext/91294600/Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/System.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/System.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/System.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/System.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/System.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/System.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/System.d ${OBJECTDIR}/_ext/91294600/System.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/System.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/SegLCD.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/SegLCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/SegLCD.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/SegLCD.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/SegLCD.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/SegLCD.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/SegLCD.d ${OBJECTDIR}/_ext/91294600/SegLCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/SegLCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/91294600/GPIO.p1: C:/Users/dungl/Documents/GitHub/XC8Training/Source/GPIO.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/91294600" 
	@${RM} ${OBJECTDIR}/_ext/91294600/GPIO.p1.d 
	@${RM} ${OBJECTDIR}/_ext/91294600/GPIO.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/91294600/GPIO.p1  C:/Users/dungl/Documents/GitHub/XC8Training/Source/GPIO.c 
	@-${MV} ${OBJECTDIR}/_ext/91294600/GPIO.d ${OBJECTDIR}/_ext/91294600/GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/91294600/GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/XCTraining.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/XCTraining.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=icd3  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"      --ram=default,-320-32f  $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/XCTraining.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/XCTraining.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/XCTraining.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/XCTraining.X.${IMAGE_TYPE}.map  --double=24 --float=24 --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 --warn=-3 --asmlist -DXPRJ_GPIO=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/XCTraining.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/GPIO
	${RM} -r dist/GPIO

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif

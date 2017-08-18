#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a pre- and a post- target defined where you can add customization code.
#
# This makefile implements macros and targets common to all configurations.
#
# NOCDDL


# Building and Cleaning subprojects are done by default, but can be controlled with the SUB
# macro. If SUB=no, subprojects will not be built or cleaned. The following macro
# statements set BUILD_SUB-CONF and CLEAN_SUB-CONF to .build-reqprojects-conf
# and .clean-reqprojects-conf unless SUB has the value 'no'
SUB_no=NO
SUBPROJECTS=${SUB_${SUB}}
BUILD_SUBPROJECTS_=.build-subprojects
BUILD_SUBPROJECTS_NO=
BUILD_SUBPROJECTS=${BUILD_SUBPROJECTS_${SUBPROJECTS}}
CLEAN_SUBPROJECTS_=.clean-subprojects
CLEAN_SUBPROJECTS_NO=
CLEAN_SUBPROJECTS=${CLEAN_SUBPROJECTS_${SUBPROJECTS}}


# Project Name
PROJECTNAME=XCTraining.X

# Active Configuration
DEFAULTCONF=GPIO
CONF=${DEFAULTCONF}

# All Configurations
ALLCONFS=GPIO 7SegLED TextLCD 74HC595 MAX7219 MUX DEMUX Timer Counter TickTimer LEDScanner PWM MatrixButton ADC DAC SegLCD UART InternalEEPROM RTCMCP79410 24AAEEPROM SRAM Flash Checksum CRC8 CRC16 XTEA 


# build
.build-impl: .build-pre
	${MAKE} -f nbproject/Makefile-${CONF}.mk SUBPROJECTS=${SUBPROJECTS} .build-conf


# clean
.clean-impl: .clean-pre
	${MAKE} -f nbproject/Makefile-${CONF}.mk SUBPROJECTS=${SUBPROJECTS} .clean-conf

# clobber
.clobber-impl: .clobber-pre .depcheck-impl
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=GPIO clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=7SegLED clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=TextLCD clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=74HC595 clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MAX7219 clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MUX clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=DEMUX clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=Timer clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=Counter clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=TickTimer clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=LEDScanner clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=PWM clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MatrixButton clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=ADC clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=DAC clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=SegLCD clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=UART clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=InternalEEPROM clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=RTCMCP79410 clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=24AAEEPROM clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=SRAM clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=Flash clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=Checksum clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=CRC8 clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=CRC16 clean
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=XTEA clean



# all
.all-impl: .all-pre .depcheck-impl
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=GPIO build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=7SegLED build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=TextLCD build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=74HC595 build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MAX7219 build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MUX build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=DEMUX build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=Timer build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=Counter build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=TickTimer build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=LEDScanner build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=PWM build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=MatrixButton build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=ADC build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=DAC build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=SegLCD build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=UART build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=InternalEEPROM build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=RTCMCP79410 build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=24AAEEPROM build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=SRAM build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=Flash build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=Checksum build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=CRC8 build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=CRC16 build
	    ${MAKE} SUBPROJECTS=${SUBPROJECTS} CONF=XTEA build



# dependency checking support
.depcheck-impl:
#	@echo "# This code depends on make tool being used" >.dep.inc
#	@if [ -n "${MAKE_VERSION}" ]; then \
#	    echo "DEPFILES=\$$(wildcard \$$(addsuffix .d, \$${OBJECTFILES}))" >>.dep.inc; \
#	    echo "ifneq (\$${DEPFILES},)" >>.dep.inc; \
#	    echo "include \$${DEPFILES}" >>.dep.inc; \
#	    echo "endif" >>.dep.inc; \
#	else \
#	    echo ".KEEP_STATE:" >>.dep.inc; \
#	    echo ".KEEP_STATE_FILE:.make.state.\$${CONF}" >>.dep.inc; \
#	fi

USE_RASPIKE_ART=1

mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_CXXOBJS +=\
    Button.o \
    Start.o \
    LineTracer.o \
	
SRCLANG := c++

APPL_DIRS += $(mkfile_path)Device \
             $(mkfile_path)DeviceMonitor \
             $(mkfile_path)Control \
             $(mkfile_path)Run \
             $(mkfile_path)RunSignal \
             $(mkfile_path)LineTracer \

INCLUDES += \
    -I$(mkfile_path)Device \
    -I$(mkfile_path)DeviceMonitor \
    -I$(mkfile_path)Control \
    -I$(mkfile_path)Run \
    -I$(mkfile_path)RunSignal \
    -I$(mkfile_path)LineTracer \

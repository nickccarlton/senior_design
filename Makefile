# Project Name
TARGET = prove_concept

# Sources
CPP_SOURCES = prove_concept.cpp

# Library Locations
DAISYSP_DIR ?= ../../DaisySP
LIBDAISY_DIR ?= ../../libDaisy

# Core location, and generic Makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile


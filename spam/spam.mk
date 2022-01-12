ifndef verbose
	SILENT = @
endif
ifeq ($(config),debug)
	OBJS_DIR := obj/Debug
	BIN_DIR := bin/Debug
	INCLUDES := -I src/  
	OBJS := $(OBJS_DIR)/main.o $(OBJS_DIR)/spam.o $(OBJS_DIR)/IProjectGenerator.o $(OBJS_DIR)/LinuxProjectGenerator.o $(OBJS_DIR)/onelua.o $(OBJS_DIR)/regex.o $(OBJS_DIR)/GenUUID.o $(OBJS_DIR)/Container.o $(OBJS_DIR)/ITarget.o $(OBJS_DIR)/IfdefTarget.o $(OBJS_DIR)/IfEqualTarget.o $(OBJS_DIR)/ElseTarget.o $(OBJS_DIR)/IfndefTarget.o $(OBJS_DIR)/PhonyTarget.o $(OBJS_DIR)/MakefileTarget.o 
	LIBS := 
	LIB_PATHS := 
	ALL_CPPFLAGS := $(CPP_FLAGS) $(CXX_FLAGS) -MMD -MP $(INCLUDES) -std=c++11 -Os -g -O0 
	ALL_LDFLAGS := $(LDFLAGS) $(LIB_PATHS) 
else
	OBJS_DIR := obj/Release
	BIN_DIR := bin/Release
	INCLUDES := -I src/  
	OBJS := $(OBJS_DIR)/main.o $(OBJS_DIR)/spam.o $(OBJS_DIR)/IProjectGenerator.o $(OBJS_DIR)/LinuxProjectGenerator.o $(OBJS_DIR)/onelua.o $(OBJS_DIR)/regex.o $(OBJS_DIR)/GenUUID.o $(OBJS_DIR)/Container.o $(OBJS_DIR)/ITarget.o $(OBJS_DIR)/IfdefTarget.o $(OBJS_DIR)/IfEqualTarget.o $(OBJS_DIR)/ElseTarget.o $(OBJS_DIR)/IfndefTarget.o $(OBJS_DIR)/PhonyTarget.o $(OBJS_DIR)/MakefileTarget.o 
	LIBS := 
	LIB_PATHS := 
	ALL_CPPFLAGS := $(CPP_FLAGS) $(CXX_FLAGS) -MMD -MP $(INCLUDES) -std=c++11 -Os -g -O0 
	ALL_LDFLAGS := $(LDFLAGS) $(LIB_PATHS) 
endif
CXX := g++
all:  create_dirs $(OBJS) $(BIN_DIR)/spam


 $(BIN_DIR)/spam:  
	$(SILENT) echo Linking $@...
	$(SILENT) $(CXX) $(OBJS) $(ALL_LDFLAGS) $(LIBS) -o $@ 

.PHONY:  create_dirs clean 

create_dirs: 
	$(SILENT) mkdir -p $(OBJS_DIR)
	$(SILENT) mkdir -p $(BIN_DIR)
clean: 
	rm -f $(OBJS_DIR)/*
	rm -f $(BIN_DIR)/*
$(OBJS_DIR)/main.o : src/main.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/spam.o : src/spam.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/IProjectGenerator.o : src/IProjectGenerator.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/LinuxProjectGenerator.o : src/LinuxProjectGenerator.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/onelua.o : src/lua/onelua.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/regex.o : src/util/regex.c
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/GenUUID.o : src/util/GenUUID.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/Container.o : src/astd/Container.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/ITarget.o : src/target/ITarget.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/IfdefTarget.o : src/target/IfdefTarget.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/IfEqualTarget.o : src/target/IfEqualTarget.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/ElseTarget.o : src/target/ElseTarget.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/IfndefTarget.o : src/target/IfndefTarget.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/PhonyTarget.o : src/target/PhonyTarget.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/MakefileTarget.o : src/target/MakefileTarget.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

-include $(OBJS:%.o=%.d)
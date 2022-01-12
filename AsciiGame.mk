ifndef verbose
	SILENT = @
endif
ifeq ($(config),debug)
	OBJS_DIR := obj/Debug
	BIN_DIR := bin/Debug
	INCLUDES := -I .  
	OBJS := $(OBJS_DIR)/main.o $(OBJS_DIR)/Player.o $(OBJS_DIR)/GameApp.o $(OBJS_DIR)/Options.o $(OBJS_DIR)/MainMenuScene.o 
	LIBS := $(BIN_DIR)/libAsciiLib.so -lSDL2 -lSDL2_ttf -lGL 
	LIB_PATHS := 
	ALL_CPPFLAGS := $(CPP_FLAGS) $(CXX_FLAGS) -MMD -MP $(INCLUDES) -std=c++14 
	ALL_LDFLAGS := $(LDFLAGS) $(LIB_PATHS) -Wl,-rpath,'$$ORIGIN' -s
else
	OBJS_DIR := obj/Release
	BIN_DIR := bin/Release
	INCLUDES := -I .  
	OBJS := $(OBJS_DIR)/main.o $(OBJS_DIR)/Player.o $(OBJS_DIR)/GameApp.o $(OBJS_DIR)/Options.o $(OBJS_DIR)/MainMenuScene.o 
	LIBS := bin/Release/libAsciiLib.so -lSDL2 -lSDL2_ttf -lGL 
	LIB_PATHS := 
	ALL_CPPFLAGS := $(CPP_FLAGS) $(CXX_FLAGS) -MMD -MP $(INCLUDES) -std=c++14 
	ALL_LDFLAGS := $(LDFLAGS) $(LIB_PATHS) -Wl,-rpath,'$$ORIGIN' -s
endif
CXX := g++
all:  create_dirs $(OBJS) $(BIN_DIR)/AsciiGame


 $(BIN_DIR)/AsciiGame:  
	$(SILENT) echo Linking $@...
	$(SILENT) $(CXX) $(OBJS) $(ALL_LDFLAGS) $(LIBS) -o $@ 

.PHONY:  create_dirs clean 

create_dirs: 
	$(SILENT) mkdir -p $(OBJS_DIR)
	$(SILENT) mkdir -p $(BIN_DIR)
clean: 
	rm -f $(OBJS_DIR)/*
	rm -f $(BIN_DIR)/*
$(OBJS_DIR)/main.o : testGame/main.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/Player.o : testGame/Player.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/GameApp.o : testGame/GameApp.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/Options.o : testGame/Options.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/MainMenuScene.o : testGame/scene/MainMenuScene.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

-include $(OBJS:%.o=%.d)
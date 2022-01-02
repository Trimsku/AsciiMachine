ifndef verbose
	SILENT = @
endif

ifeq ($(config),debug)
	OBJS_DIR := obj/Debug
	BIN_DIR := bin/Debug
	ARGS := -O0 -g -fsanitize=address
else
	OBJS_DIR := obj/Release
	BIN_DIR := bin/Release
	ARGS := -O3
endif
ARGS += -lSDL2
ARGS += -lSDL2_ttf
ARGS += -Lbin/Release/ -Wl,-rpath=bin/Release/ -lAsciiLib 
ARGS += -std=c++14
ARGS += -I . -I asciiengine/common/entity/ 
OBJS := $(OBJS_DIR)/main.o $(OBJS_DIR)/Player.o $(OBJS_DIR)/GameApp.o $(OBJS_DIR)/MainMenuScene.o 
BINS := $(BIN_DIR)/AsciiGame

all: create_dirs $(OBJS) $(BINS)

.PHONY: create_dirs clean
create_dirs:
	$(SILENT) mkdir -p $(OBJS_DIR)
	$(SILENT) mkdir -p $(BIN_DIR)
clean:
	rm -f $(OBJS_DIR)/*

	rm -f $(BIN_DIR)/*
$(BIN_DIR)/AsciiGame: $(OBJS)
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX)  $(CFLAGS) $(OBJS) $(ARGS) -o $@

$(OBJS_DIR)/main.o: testGame/main.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX)  $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/main.d

$(OBJS_DIR)/Player.o: testGame/Player.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX)  $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/Player.d

$(OBJS_DIR)/GameApp.o: testGame/GameApp.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX)  $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/GameApp.d

$(OBJS_DIR)/MainMenuScene.o: testGame/scene/MainMenuScene.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX)  $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/MainMenuScene.d

-include $(OBJS:%.o=%.d)

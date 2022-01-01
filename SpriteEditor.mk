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
ARGS += -Lbin/Release/ -Wl,-rpath=bin/Release/ -lAsciiLib 
ARGS += -std=c++14
ARGS += -I . -I asciiengine/common/entity/ 
OBJS := $(OBJS_DIR)/SpriteEditor.o 
BINS := $(BIN_DIR)/SpriteEditor

all: create_dirs $(OBJS) $(BINS)

.PHONY: create_dirs clean
create_dirs:
	$(SILENT) mkdir -p $(OBJS_DIR)
	$(SILENT) mkdir -p $(BIN_DIR)
clean:
	rm -f $(OBJS_DIR)/*

	rm -f $(BIN_DIR)/*
$(BIN_DIR)/SpriteEditor: $(OBJS)
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX)  $(CFLAGS) $(OBJS) $(ARGS) -o $@

$(OBJS_DIR)/SpriteEditor.o: se/SpriteEditor.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX)  $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/SpriteEditor.d

-include $(OBJS:%.o=%.d)

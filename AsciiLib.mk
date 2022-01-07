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
ARGS += -lGLEW
ARGS += -lGL
ARGS += -std=c++14
ARGS += -I . 
OBJS := $(OBJS_DIR)/Clock.o $(OBJS_DIR)/String.o $(OBJS_DIR)/AnimationManager.o $(OBJS_DIR)/AnimatedTexture.o $(OBJS_DIR)/AnimatedText.o $(OBJS_DIR)/AnimatedTextBuilder.o $(OBJS_DIR)/AnimatedTextUTF8.o $(OBJS_DIR)/AnimatedTextBuilderUTF8.o $(OBJS_DIR)/Shader.o $(OBJS_DIR)/Scene.o $(OBJS_DIR)/Camera.o $(OBJS_DIR)/Subject.o $(OBJS_DIR)/Observer.o $(OBJS_DIR)/StringUtil.o $(OBJS_DIR)/Font.o $(OBJS_DIR)/SDL_FontCache.o $(OBJS_DIR)/Engine.o $(OBJS_DIR)/utf-8.o 
BINS := $(BIN_DIR)/libAsciiLib.so

all: create_dirs $(OBJS) $(BINS)

.PHONY: create_dirs clean
create_dirs:
	$(SILENT) mkdir -p $(OBJS_DIR)
	$(SILENT) mkdir -p $(BIN_DIR)
clean:
	rm -f $(OBJS_DIR)/*

	rm -f $(BIN_DIR)/*
$(BIN_DIR)/libAsciiLib.so: $(OBJS)
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) --shared $(CFLAGS) $(OBJS) $(ARGS) -o $@

$(OBJS_DIR)/Clock.o: src/astd/Clock.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/Clock.d

$(OBJS_DIR)/String.o: src/astd/String.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/String.d

$(OBJS_DIR)/AnimationManager.o: src/client/AnimationManager.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/AnimationManager.d

$(OBJS_DIR)/AnimatedTexture.o: src/client/AnimatedTexture.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/AnimatedTexture.d

$(OBJS_DIR)/AnimatedText.o: src/client/AnimatedText.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/AnimatedText.d

$(OBJS_DIR)/AnimatedTextBuilder.o: src/client/AnimatedTextBuilder.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/AnimatedTextBuilder.d

$(OBJS_DIR)/AnimatedTextUTF8.o: src/client/AnimatedTextUTF8.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/AnimatedTextUTF8.d

$(OBJS_DIR)/AnimatedTextBuilderUTF8.o: src/client/AnimatedTextBuilderUTF8.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/AnimatedTextBuilderUTF8.d

$(OBJS_DIR)/Shader.o: src/client/Shader.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/Shader.d

$(OBJS_DIR)/Scene.o: src/common/Scene.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/Scene.d

$(OBJS_DIR)/Camera.o: src/common/Camera.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/Camera.d

$(OBJS_DIR)/Subject.o: src/common/event/Subject.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/Subject.d

$(OBJS_DIR)/Observer.o: src/common/event/Observer.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/Observer.d

$(OBJS_DIR)/StringUtil.o: src/common/util/StringUtil.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/StringUtil.d

$(OBJS_DIR)/Font.o: src/core/Font.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/Font.d

$(OBJS_DIR)/SDL_FontCache.o: src/core/SDL_FontCache.c
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/SDL_FontCache.d

$(OBJS_DIR)/Engine.o: src/core/Engine.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/Engine.d

$(OBJS_DIR)/utf-8.o: src/core/utf-8.c
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) -fPIC $(CFLAGS) -c $< -o $@ $(ARGS) -MMD -MP -MF $(OBJS_DIR)/utf-8.d

-include $(OBJS:%.o=%.d)

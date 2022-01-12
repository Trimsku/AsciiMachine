ifndef verbose
	SILENT = @
endif
ifeq ($(config),debug)
	OBJS_DIR := obj/Debug
	BIN_DIR := bin/Debug
	INCLUDES := -I .  
	OBJS := $(OBJS_DIR)/Clock.o $(OBJS_DIR)/String.o $(OBJS_DIR)/AnimationManager.o $(OBJS_DIR)/AnimatedTexture.o $(OBJS_DIR)/AnimatedText.o $(OBJS_DIR)/AnimatedTextBuilder.o $(OBJS_DIR)/AnimatedTextUTF8.o $(OBJS_DIR)/AnimatedTextBuilderUTF8.o $(OBJS_DIR)/Shader.o $(OBJS_DIR)/Scene.o $(OBJS_DIR)/Camera.o $(OBJS_DIR)/Subject.o $(OBJS_DIR)/Observer.o $(OBJS_DIR)/StringUtil.o $(OBJS_DIR)/Font.o $(OBJS_DIR)/SDL_FontCache.o $(OBJS_DIR)/Engine.o $(OBJS_DIR)/utf-8.o 
	LIBS := -lSDL2 -lSDL2_ttf -lGL 
	LIB_PATHS := 
	ALL_CPPFLAGS := $(CPP_FLAGS) $(CXX_FLAGS) -MMD -MP $(INCLUDES) -fPIC -std=c++14 
	ALL_LDFLAGS := $(LDFLAGS) $(LIB_PATHS) -shared -Wl,-soname=libAsciiLib.so -s 
else
	OBJS_DIR := obj/Release
	BIN_DIR := bin/Release
	INCLUDES := -I .  
	OBJS := $(OBJS_DIR)/Clock.o $(OBJS_DIR)/String.o $(OBJS_DIR)/AnimationManager.o $(OBJS_DIR)/AnimatedTexture.o $(OBJS_DIR)/AnimatedText.o $(OBJS_DIR)/AnimatedTextBuilder.o $(OBJS_DIR)/AnimatedTextUTF8.o $(OBJS_DIR)/AnimatedTextBuilderUTF8.o $(OBJS_DIR)/Shader.o $(OBJS_DIR)/Scene.o $(OBJS_DIR)/Camera.o $(OBJS_DIR)/Subject.o $(OBJS_DIR)/Observer.o $(OBJS_DIR)/StringUtil.o $(OBJS_DIR)/Font.o $(OBJS_DIR)/SDL_FontCache.o $(OBJS_DIR)/Engine.o $(OBJS_DIR)/utf-8.o 
	LIBS := -lSDL2 -lSDL2_ttf -lGL 
	LIB_PATHS := 
	ALL_CPPFLAGS := $(CPP_FLAGS) $(CXX_FLAGS) -MMD -MP $(INCLUDES) -fPIC -std=c++14 
	ALL_LDFLAGS := $(LDFLAGS) $(LIB_PATHS) -shared -Wl,-soname=libAsciiLib.so -s 
endif
CXX := g++
all:  create_dirs $(OBJS) $(BIN_DIR)/libAsciiLib.so


 $(BIN_DIR)/libAsciiLib.so:  
	$(SILENT) echo Linking $@...
	$(SILENT) $(CXX) $(OBJS) $(ALL_LDFLAGS) $(LIBS) -o $@ 

.PHONY:  create_dirs clean 

create_dirs: 
	$(SILENT) mkdir -p $(OBJS_DIR)
	$(SILENT) mkdir -p $(BIN_DIR)
clean: 
	rm -f $(OBJS_DIR)/*
	rm -f $(BIN_DIR)/*
$(OBJS_DIR)/Clock.o : src/astd/Clock.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/String.o : src/astd/String.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/AnimationManager.o : src/client/AnimationManager.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/AnimatedTexture.o : src/client/AnimatedTexture.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/AnimatedText.o : src/client/AnimatedText.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/AnimatedTextBuilder.o : src/client/AnimatedTextBuilder.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/AnimatedTextUTF8.o : src/client/AnimatedTextUTF8.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/AnimatedTextBuilderUTF8.o : src/client/AnimatedTextBuilderUTF8.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/Shader.o : src/client/Shader.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/Scene.o : src/common/Scene.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/Camera.o : src/common/Camera.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/Subject.o : src/common/event/Subject.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/Observer.o : src/common/event/Observer.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/StringUtil.o : src/common/util/StringUtil.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/Font.o : src/core/Font.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/SDL_FontCache.o : src/core/SDL_FontCache.c
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/Engine.o : src/core/Engine.cpp
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

$(OBJS_DIR)/utf-8.o : src/core/utf-8.c
	$(SILENT) echo Building $@...
	$(SILENT) $(CXX) $(ALL_CPPFLAGS) -o "$@" -MF "$(@:%.o=%.d)" -c "$<" 

-include $(OBJS:%.o=%.d)
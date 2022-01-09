ifndef config
	config=release
endif

ifndef verbose
	SILENT = @
endif

ifeq ($(config),debug)
	GCONFIG = debug
else
	GCONFIG = release
endif

PROJECTS := AsciiLib AsciiGame 
.PHONY: all help $(PROJECTS)


all: $(PROJECTS)

AsciiLib:
	$(SILENT) echo "==== Building AsciiLib ($(GCONFIG)) ===="
	$(SILENT) $(MAKE) --no-print-directory -C . -f AsciiLib.mk config=$(GCONFIG)
AsciiGame:
	$(SILENT) echo "==== Building AsciiGame ($(GCONFIG)) ===="
	$(SILENT) $(MAKE) --no-print-directory -C . -f AsciiGame.mk config=$(GCONFIG)

clean:
	$(SILENT) $(MAKE) --no-print-directory -C . -f AsciiLib.mk clean
	$(SILENT) $(MAKE) --no-print-directory -C . -f AsciiGame.mk clean
help:
	$(SILENT) echo "Usage: make [config=name] [target]"
	$(SILENT) echo ""
	$(SILENT) echo "Configurations:"
	$(SILENT) echo "	debug"
	$(SILENT) echo "	release"
	$(SILENT) echo ""
	$(SILENT) echo "Targets:"
	$(SILENT) echo "	all (default)"
	$(SILENT) echo "	clean"
	$(SILENT) echo "	AsciiLib"
	$(SILENT) echo "	AsciiGame"

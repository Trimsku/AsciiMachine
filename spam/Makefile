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

PROJECTS := spam 
.PHONY: all help $(PROJECTS)


all: $(PROJECTS)

spam:
	$(SILENT) echo "==== Building spam ($(GCONFIG)) ===="
	$(SILENT) $(MAKE) --no-print-directory -C . -f spam.mk config=$(GCONFIG)

clean:
	$(SILENT) $(MAKE) --no-print-directory -C . -f spam.mk clean
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
	$(SILENT) echo "	spam"

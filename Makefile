include config.mk.global # global vars common to all projects (warning/linker flags, default target etc.)
include config.mk.local  # project-local vars (source files, prj name, relative path to executable etc.) & any overrides to global config

.PHONY : all
all : $(DEFAULT_TARGET)

#: debug: make 'debug' target
debug : $(SRC_FILES)
	rm -f $(EXEC)
	mkdir -p $@
	g++ $^ $(CC_FLAGS_DEBUG) -o $@/$(EXEC)
	ln -s $@/$(EXEC)

#: release: make 'release' target
release : $(SRC_FILES)
	rm -f $(EXEC)
	mkdir -p $@
	g++ $^ $(CC_FLAGS_RELEASE) -o $@/$(EXEC)
	ln -s $@/$(EXEC)

.PHONY : run
run: all
	./$(EXEC)

.PHONY : clean
clean :
	rm -f $(EXEC)
	rm -rf debug/
	rm -rf release/

.PHONY : exec_clean
exec_clean :
	@echo "Deleting all .x files ..."
	find . -name "*.x" -type f \( -perm -u=x \) -print -delete

.PHONY : variables
variables :
	@echo DEFAULT_TARGET : $(DEFAULT_TARGET)
	@echo PRJ_NAME : $(PRJ_NAME)
	@echo SRC_FILES : $(SRC_FILES)
	@echo EXEC : $(EXEC)
	@echo CC_FLAGS_DEBUG : $(CC_FLAGS_DEBUG)
	@echo CC_FLAGS_RELEASE : $(CC_FLAGS_RELEASE)

# C++ project makefile

# Settings:
## OUTPUT
OUT := tr1.exe
## Input folder containg .cpp files:
SOURCE_DIR := source
## Input folders containg .hpp files and .tmp files:
INCLUDE_DIRS := . include
## Static linked libraries folders:
STATIC_LINKED_LIBRARIES_DIRS :=
## Output folder containg .o files
OUTPUT_OBJ_DIR := objs
## Test folders containg code to test.
TEST_DIRS := test
## Compiler:
CXX := g++
## Flags given to compiler:
CXXFLAGS := -std=c++14 -lm
## Archiver to make C++ linked libraries:
AR = ar
## Flags given to Archiver:
ARFLAGS = rvs

################################################################################

SOURCE_FILES := $(wildcard $(SOURCE_DIR)/*.cpp)

SLL_HEADERS := $(foreach ITEM, $(STATIC_LINKED_LIBRARIES_DIRS), $(wildcard $(ITEM)/*.hpp))
INCLUDE_FILES := $(foreach ITEM, $(INCLUDE_DIRS), $(wildcard $(ITEM)/*.hpp)) \
                 $(SLL_HEADERS)

ARCHIVE_FILES := $(foreach ITEM, $(STATIC_LINKED_LIBRARIES_DIRS), $(ITEM)/$(ITEM).a)
OBJ_FILES := $(addprefix $(OUTPUT_OBJ_DIR)/, $(notdir $(SOURCE_FILES:.cpp=.o)))

#-------------------------------------------------------------------------------

standart_command: compile

#-------------------------------------------------------------------------------

compile: $(OUT)

ifeq ($(suffix $(OUT)), .a)
$(OUT): $(OBJ_FILES) $(ARCHIVE_FILES)
	$(AR) $(ARFLAGS) $@ $^
else
$(OUT): $(OBJ_FILES) $(ARCHIVE_FILES)
	$(CXX) -o $@ $^ $(CXXFLAGS)
endif

$(OUTPUT_OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp $(INCLUDE_FILES)
	mkdir -p $(OUTPUT_OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(addprefix -I , $(INCLUDE_DIRS) $(STATIC_LINKED_LIBRARIES_DIRS))

$(ARCHIVE_FILES):
	$(foreach ITEM, $(STATIC_LINKED_LIBRARIES_DIRS), cd $(ITEM) && $(MAKE) $(DEBUG) ${\n})

#-------------------------------------------------------------------------------

debug: CXXFLAGS += -ggdb
DEBUG :=
debug: DEBUG += debug

#-------------------------------------------------------------------------------

test: compile
	cd $(TEST_DIRS) && $(MAKE) $(DEBUG) test

#-------------------------------------------------------------------------------

clean:
	$(RM) -f $(OBJ_FILES)
	$(RM) -rf $(OUTPUT_OBJ_DIR)
	$(foreach ITEM, $(TEST_DIRS), cd $(ITEM) && $(MAKE) clean ${\n})
	$(foreach ITEM, $(STATIC_LINKED_LIBRARIES_DIRS), cd $(ITEM) && $(MAKE) clean ${\n})

#-------------------------------------------------------------------------------

reset: clean
	$(RM) -f $(OUT)
	$(foreach ITEM, $(TEST_DIRS), cd $(ITEM) && $(MAKE) reset ${\n})
	$(foreach ITEM, $(STATIC_LINKED_LIBRARIES_DIRS), cd $(ITEM) && $(MAKE) reset ${\n})

#-------------------------------------------------------------------------------

help:
	@echo Commands:
	@echo -e '  ' compile
	@echo -e '  ' debug compile
	@echo -e '  ' test
	@echo -e '  ' debug test
	@echo -e '  ' clean
	@echo -e '  ' reset

#-------------------------------------------------------------------------------

FOLDERS := include source test \
           test/tinclude test/tsource

new_project:
	$(foreach folder, $(FOLDERS), mkdir -p $(folder) ${\n})


################################################################################

define \n


endef

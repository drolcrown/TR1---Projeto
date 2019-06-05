# C++ project test makefile

# Settings:
## OUTPUT
TOUT := test_tr1.exe
## Input folder containg .cpp files:
TSOURCE_DIR := tsource
## Input folders containg .hpp files and .tmp files:
INCLUDE_DIRS := tinclude .. ../include
## Static linked libraries folders:
STATIC_LINKED_LIBRARIES_DIRS := 
## Output directory containg .o testers files:
OUTPUT_TOBJ_DIR := tobjs
# Tested objects folders:
OBJ_DIRS := ../objs
## Compiler:
CXX := g++
## Flags given to compiler:
CXXFLAGS := -std=c++14 -lm

################################################################################

TSOURCE_FILES := $(wildcard $(TSOURCE_DIR)/*.cpp)

SLL_HEADERS  := $(foreach ITEM, $(STATIC_LINKED_LIBRARIES_DIRS), $(wildcard $(ITEM)/*.hpp))
INCLUDE_FILES := $(foreach ITEM, $(INCLUDE_DIRS), $(wildcard $(ITEM)/*.hpp)) \
                 $(SLL_HEADERS)

ARCHIVE_FILES := $(foreach ITEM, $(STATIC_LINKED_LIBRARIES_DIRS), $(wildcard $(ITEM)/*.a))
OBJ_FILES := $(foreach ITEM, $(OBJ_DIRS), $(filter-out $(ITEM)/main.o ,$(wildcard $(ITEM)/*.o)))
TOBJ_FILES := $(addprefix $(OUTPUT_TOBJ_DIR)/, $(notdir $(TSOURCE_FILES:.cpp=.o)))

#-------------------------------------------------------------------------------

standart_command: test

#-------------------------------------------------------------------------------

compile: $(TOUT)

$(TOUT): $(TOBJ_FILES) $(OBJ_FILES) $(ARCHIVE_FILES)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(OUTPUT_TOBJ_DIR)/%.o: $(TSOURCE_DIR)/%.cpp $(INCLUDE_FILES)
	mkdir -p $(OUTPUT_TOBJ_DIR)
	$(CXX) $< -c -o $@ $(CXXFLAGS) $(addprefix -I , $(INCLUDE_DIRS) $(DIR_INCLUDE) $(SLL_HEADERS) .)

#-------------------------------------------------------------------------------

debug: CXXFLAGS += -ggdb
DEBUG :=
debug: DEBUG += debug

#-------------------------------------------------------------------------------

test: compile
	./$(TOUT)

#-------------------------------------------------------------------------------

clean:
	$(RM) -f $(TOBJ_FILES)
	$(RM) -rf $(OUTPUT_TOBJ_DIR)

#-------------------------------------------------------------------------------

reset: clean
	$(RM) -f $(TOUT)

help:
	@echo Commands:
	@echo -e '  ' compile
	@echo -e '  ' debug compile
	@echo -e '  ' test
	@echo -e '  ' debug test
	@echo -e '  ' clean
	@echo -e '  ' reset

#-------------------------------------------------------------------------------

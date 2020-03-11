# Name the project
TARGET  = simple-libmqtt

BUILD_DIR = ./build

CC_FLAGS 	=   
LD_FLAGS 	= 

# List of all .c source files.
SRC = $(wildcard src/*.c) 
INC = -Isrc/

# All .o files go to build dir.
OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

# gcc will create these .d files containing dependencies.
DEP = $(OBJ:%.o=%.d)

all : $(TARGET)

# Links object files
$(TARGET) : $(OBJ)
	@echo Linking $@
	$(CC) $(LD_FLAGS) $^ -o $@ -lmosquitto

# Include all .d files this expands to a list of targets and dependancies
-include $(DEP)

# The -MMD flags additionaly creates a .d file with
# the same name as the .o file.
$(BUILD_DIR)/%.o : %.c
	@mkdir -p $(@D)
	@echo Compiling $<
	$(CC) $(INC) -MMD $(CC_FLAGS) -c $< -o $@

.PHONY : clean install
clean :
	-@rm -rf $(TARGET) $(OBJ) $(DEP) 2>/dev/null

# inspiration from https://makefiletutorial.com
TARGET := cards
CC	:= gcc
CXX := c++
BUILD_DIR := ./build
SRC_DIRS := ./src
# Get all the c++/c files
SRCS := $(shell find $(SRC_DIRS) -name *.cpp or -name *.c)
# String Substitute every c/c++ that was found in SRCs.
# IE. hello.cpp becomes ./build/hello.cpp.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
# Get folders in ./src using find
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
# Prepend the "-I" to "module" so that it becomes "-Imodule" which GCC wants
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
LIB_DIR :=
LIBS :=

#FLAGS
CFLAGS := -Wall -g
# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP

# Include the .d makefiles. The - at the front suresses the errors of missing
# # Makefiles. Initially, all the .d files will be missing, and we don't want those
# # errors to show up.
-include $(DEPS)

#BUILD: final step
#TODO FIGURE OUT WHERE $(LDFLAGS) CAME FROM
$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

#BUILD: c sources
#TODO what does $@ and $< mean?
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

#BUILD: c++ sources
#TODO CXXFLAGS
$(BUILD_DIR)/%.c.o: %.c
    mkdir -p $(dir $@)
    $(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


#OTHER COMMANDS:
clean:
   -@rm -rvf $(BUILD_DIR)

info:
   @echo "[*] Object dir:      ${OBJ_DIR}     "
   @echo "[*] Sources:         ${SRC}         "
   @echo "[*] Objects:         ${OBJECTS}     "
   @echo "[*] Dependencies:    ${DEPENDENCIES}"

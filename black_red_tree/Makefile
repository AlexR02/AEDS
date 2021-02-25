CXX      := -gcc
CXXFLAGS := -pedantic-errors -Wall -Wextra 
LDFLAGS  := -lstdc++ -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/
TARGET   := app
INCLUDE  := -Include/
SRC      := $(wildcard src/*.c)
#  $(wildcard src/module1*.c) \
#  $(wildcard src/module2*.c) \
#  $(wildcard src/module3*.c) \

OBJECTS := $(SRC:%.c=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)
	
.PHONY: all build clean debug release run

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)
	
debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -03
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*
	

run:
	./$(BUILD)/$(TARGET)	

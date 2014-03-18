# makefile to build mme
TARGET   = mme
T_TARGET = mmetests

CC       = g++
LINKER   = g++ -o

# compiling flags here
CFLAGS   = -lsqlite3
TCFLAGS  = -lsqlite3

# linking flags here
LFLAGS   = -Wall -I. -lm
TLFLAGS  = -Wall

# configuration for src obj and bin
SRCDIR   = ../src
TESTDIR  = ../test
OBJDIR   = ../obj
BINDIR   = ../bin


SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
T_SRCS   := $(wildcard $(TESTDIR)/*.cpp)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
T_OBJS   := $(T_SRC:$(TESTDIR)/%.cpp=$(OBJDIR)/%.o)

rm       = rm -f

.PHONEY: all
all: $(BINDIR)/$(TARGET)
	@echo "Binary complete!"

.PHONEY: test
test: $(BINDIR)/$(T_TARGET)
	@echo "Test binary complete!"

$(BINDIR)/$(T_TARGET): $(OBJECTS) $(T_OBJS)
	@$(LINKER) $@ $(TLFLAGS) $(OBJECTS) $(T_OBJS)
	@echo "Linking tests complete!"

$(T_OBJS): $(OBJDIR)/%.o : $(T_SRC)/%.cpp
	@$(CC) $(CTFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	@$(rm) $(OBJDIR)/*
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

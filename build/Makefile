# makefile to build mme
TARGET   = mme
T_TARGET = mmetests

# configuration for src obj and bin
SRCDIR   = ../src
TESTDIR  = ../test
OBJDIR   = ../obj
BINDIR   = ../bin
LIBDIR   = ../lib
GTESTDIR = $(LIBDIR)/gtest-1.7.0
CC       = g++
LINKER   = g++ -o

# compiling flags here
CFLAGS   = -lsqlite3
TCFLAGS  = -isystem $(GTESTDIR)/include

# linking flags here
LFLAGS   = -Wall -I. -lm
TLFLAGS  = -isystem $(GTESTDIR)/include $(GTESTDIR)/src/gtest_main.cc ../libgtest.a -pthread -lsqlite3


SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
T_SRCS   := $(wildcard $(TESTDIR)/*.cpp)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
T_OBJS   := $(T_SRCS:$(TESTDIR)/%.cpp=$(OBJDIR)/%.o)

rm       = rm -f

.PHONEY: test
test: $(BINDIR)/$(T_TARGET)
	@echo "Test binary complete!"

$(BINDIR)/$(T_TARGET): $(T_OBJS) $(OBJECTS)
	@$(LINKER) $@ $(TLFLAGS) $(T_OBJS) ../obj/clientconnection.o 
	@echo "Linking tests complete!"

$(T_OBJS): $(OBJDIR)/%.o : $(TESTDIR)/%.cpp
	@$(CC) $(TCFLAGS) -c $< -o $@
	@echo "Compiled  test "$<" successfully!"

.PHONEY: all
all: $(BINDIR)/$(TARGET)
	@echo "Binary complete!"

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
	@$(rm) $(BINDIR)/$(TARGET) $(BINDIR)/$(T_TARGET)
	@echo "Executable removed!"

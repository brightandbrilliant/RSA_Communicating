# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# Directories
SRC_DIR = .
INCLUDE_DIR = include
LIB_DIR = lib_

# Source files
SRCS = $(SRC_DIR)/RSA_server.cpp $(INCLUDE_DIR)/RSA_coding.cpp $(INCLUDE_DIR)/tcp_server_client_class.cpp \
       $(SRC_DIR)/RSA_client.cpp $(SRC_DIR)/RSA_transist.cpp $(SRC_DIR)/multi_thread.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable files
EXECUTABLES = RSA_server RSA_client RSA_transist

# Libraries
LIBS = -lwsock32

# Default target
all: $(EXECUTABLES)

# Build targets
RSA_server: $(SRC_DIR)/RSA_server.o $(INCLUDE_DIR)/RSA_coding.o $(INCLUDE_DIR)/tcp_server_client_class.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

RSA_client: $(SRC_DIR)/RSA_client.o $(INCLUDE_DIR)/RSA_coding.o $(INCLUDE_DIR)/tcp_server_client_class.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

RSA_transist: $(SRC_DIR)/RSA_transist.o $(INCLUDE_DIR)/RSA_coding.o $(INCLUDE_DIR)/tcp_server_client_class.o $(INCLUDE_DIR)/multi_thread.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Pattern rule for compiling .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(LIB_DIR) -c $< -o $@

# Clean target
clean:
	rm $(OBJS) $(EXECUTABLES)

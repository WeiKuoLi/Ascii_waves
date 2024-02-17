all: animation

CXX = g++
override CXXFLAGS += -g -Wno-everything -I./include -L./lib -pthread -lm
EIGEN_INCLUDE_DIR ?= ./external/eigen3

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

animation: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(EIGEN_INCLUDE_DIR) -O3 $(SRCS) -o "$@"

animation-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(EIGEN_INCLUDE_DIR) -O0 $(SRCS) -o "$@"

clean:
	rm -f animation animation-debug


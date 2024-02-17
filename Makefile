all: asciiwaves

CXX = g++
override CXXFLAGS += -g -Wno-everything -I./include -L./lib -pthread -lm
EIGEN_INCLUDE_DIR ?= /usr/include/eigen3 

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

asciiwaves: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(EIGEN_INCLUDE_DIR) -O3 $(SRCS) -o "$@"

asciiwaves-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(EIGEN_INCLUDE_DIR) -O0 $(SRCS) -o "$@"

clean:
	rm -f asciiwaves asciiwaves-debug


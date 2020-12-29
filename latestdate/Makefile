ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Windows)
	CC := cl
	CFLAGS := /Fe:main
	cleanup := \rm -f *.obj main.exe
else ifeq ($(detected_OS),Linux) 
	CC := g++
	CFLAGS := -std=c++14 -lstdc++fs -o main.out
	cleanup := \rm -f *.o main.out
else ifeq ($(detected_OS),Darwin) 
	CC := g++
	CFLAGS := -std=c++14 -o main.out
	cleanup := \rm -f *.o main.out
else
	echo "No recognizing OS"
	exit 1
endif

files := main.cpp getlatest.cpp

main: $(files)
	$(CC) $(CFLAGS) $(files)
clean:
	$(cleanup)

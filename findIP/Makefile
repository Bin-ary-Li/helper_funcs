ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Windows)
	files := main.cpp winEnumIP.cpp findip.cpp
	CC := cl
	CFLAGS := /Fe:main
	cleanup := \rm -f *.obj main.exe
else ifeq ($(detected_OS),Linux) 
	files := main.cpp unixEnumIP.cpp findip.cpp
	CC = g++
	CFLAGS = -std=c++14 -o main.out
else ifeq ($(detected_OS),Darwin) 
	files := main.cpp unixEnumIP.cpp findip.cpp
	CC = g++
	CFLAGS = -std=c++14 -o main.out
else
	echo "No recognizing OS"
	exit 1
endif

main: $(files)
	$(CC) $(CFLAGS) $(files)
clean:
	$(cleanup)

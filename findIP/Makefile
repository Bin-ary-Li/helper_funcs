ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Windows)
	files := main.cpp winEnumIP.cpp findip.cpp
	CC := cl
	CFLAGS := /EHsc
	cleanup := \rm -f *.obj main.exe *~ *#
else ifeq ($(detected_OS),Linux) 
	CC = g++
	CFLAGS = -std=c++14
else ifeq ($(detected_OS),Darwin) 
	CC = g++
	CFLAGS = -std=c++14
else
	echo "No recognizing OS"
	exit 1
endif

main: $(files)
	$(CC) $(files) $(CFLAGS)
clean:
	$(cleanup)

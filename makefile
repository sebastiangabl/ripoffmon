INCLUDES = -I"C:/MinGW/SFML-2.3.2/include"
CFLAGS = -Wall -std=c++11 $(INCLUDES)

LDFLAGS = -L"C:/MinGW/SFML-2.3.2/lib" -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

SRC = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJS = $(SRC:src/%.cpp=obj/%.o)

ifeq ($(OS),Windows_NT)
	build_folders := $(shell mkdir obj\Managers obj\Utils >nul 2>&1)
	MAIN = ripoffmon.exe
	CLEAN = del obj\*.o /s > nul 2>&1
else
	build_folders := $(shell mkdir -p obj/Managers obj/Utils)
	MAIN = ripoffmon
	CLEAN = rm obj/*.o -r > /dev/null 2>&1
endif

all: $(MAIN)

$(MAIN): $(OBJS)
	g++ $(OBJS) -o $@ $(LDFLAGS)

obj/%.o: src/%.cpp
	g++ -c $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	@$(CLEAN)

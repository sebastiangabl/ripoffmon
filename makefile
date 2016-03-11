INCLUDES = -I"C:/MinGW/SFML-2.3.2/include"
CFLAGS = -Wall -std=c++11 $(INCLUDES)

LDFLAGS = -L"C:/MinGW/SFML-2.3.2/lib" -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

SRC = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJS = $(SRC:.cpp=.o)

ifeq ($(OS),Windows_NT)
  MAIN = ripoffmon.exe
  CLEAN = del *.o /s
  DIRS =
else
  MAIN = ripoffmon
  CLEAN = rm *.o -r
endif

$(MAIN): $(OBJS)
	g++ $(OBJS) -o $@ $(LDFLAGS)

%.o: %.cpp
	g++ -c $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	@$(CLEAN)

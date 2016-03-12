CFLAGS = -Wall -O3 -std=c++11
LDFLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -llua53

SRC = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJS = $(SRC:src/%.cpp=obj/%.o)

ifeq ($(OS),Windows_NT)
	build_folders := $(shell mkdir obj\Creature obj\Lua obj\Managers obj\Utils >nul 2>&1)
	NAME = ripoffmon.exe
	CLEANCMD = del obj\*.o /s > nul 2>&1
else
	build_folders := $(shell mkdir -p obj/Creature obj/Lua obj/Managers obj/Utils obj/Lua)
	NAME = ripoffmon
	CLEANCMD = rm obj/*.o -r > /dev/null 2>&1
endif

#default build
all: $(NAME)

$(NAME): $(OBJS)
	g++ $(OBJS) -o $@ $(LDFLAGS)

#special windows build to include exe information
windows: $(OBJS)
	windres src/resource.rc -O coff -o obj/resource.res
	g++ $(OBJS) obj/resource.res -o $(NAME) $(LDFLAGS)

obj/%.o: src/%.cpp
	g++ -c $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	@$(CLEANCMD)

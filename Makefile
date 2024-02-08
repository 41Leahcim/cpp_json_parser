app: $(wildcard src/*.cpp)
	g++ src/*.cpp -I include -Os -Wall -Wextra -o app

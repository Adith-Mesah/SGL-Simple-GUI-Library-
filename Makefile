name = main
objs = main.o src/SGL_utilities.o src/SGL_panel.o src/SGL_event_engine.o
compiler = gcc

$(name): $(objs)
	$(compiler) -o $(name) $(objs) `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lm

	
.PHONY=clean
clean:
	rm $(objs)

.PHONY=run
run: $(name)
	./$(name)

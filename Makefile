psx: src/main.o src/cpu.o
	$(CXX) $< -o $@

src/%.o: src/%.cpp
	$(CXX) $< -Iinclude -c -o $@

psx: src/main.o src/CPU.o
	$(CXX) $< -o $@

src/%.o: src/%.cpp
	$(CXX) $< -Iinclude -c -o $@

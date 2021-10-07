EXEC = spacecraft

BINDIR = bin
OBJDIR = obj
SRCDIR = src
INCDIR = include

CXX = g++
CXXFLAGS = -Wall
SFML = -lsfml-graphics -lsfml-window -lsfml-system

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(BINDIR)/$(EXEC): $(OBJDIR) $(OBJECTS) $(BINDIR)
	$(CXX) $(OBJECTS) $(SFML) -o $@

$(BINDIR):
	mkdir -p ./$(BINDIR)

$(OBJDIR):
	mkdir -p ./$(OBJDIR)

$(OBJDIR)/Main.o: $(SRCDIR)/Main.cpp $(OBJDIR)/Game.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Game.o: $(SRCDIR)/Game.cpp $(INCDIR)/Game.hpp $(OBJDIR)/Background.o $(OBJDIR)/SpaceCraft.o $(OBJDIR)/Fire.o $(OBJDIR)/Asteroid.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Background.o: $(SRCDIR)/Background.cpp $(INCDIR)/Background.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/SpaceCraft.o: $(SRCDIR)/SpaceCraft.cpp $(INCDIR)/SpaceCraft.hpp $(OBJDIR)/Fire.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Fire.o: $(SRCDIR)/Fire.cpp $(INCDIR)/Fire.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Asteroid.o: $(SRCDIR)/Asteroid.cpp $(INCDIR)/Asteroid.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BINDIR) $(OBJDIR)

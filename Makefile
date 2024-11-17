# Nombre del ejecutable
EXECUTABLE = programa

# Archivos fuente
SOURCES = main.cpp costos.cpp

# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -I. -Wall

# Regla para compilar todo
all: $(EXECUTABLE)

# Regla para compilar el ejecutable
$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)

# Regla de limpieza
clean:
	rm -f $(EXECUTABLE)

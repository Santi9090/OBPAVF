CXX = g++
CXXFLAGS = -Wall

OBJS = Fabrica.o \
	Controladores/ControladorSesion.o \
	Controladores/ControladorPelicula.o \
	Controladores/ControladorAltaCine.o \
	Controladores/ControladorAltaFuncion.o \
	Controladores/ControladorCrearReserva.o \
	Controladores/ControladorVerReservaPelicula.o \
	Manejadores/ManejadorCine.o \
	Manejadores/ManejadorPelicula.o \
	Manejadores/ManejadorFuncion.o \
	Manejadores/ManejadorUsuario.o \
	Clases/Cine.o \
	Clases/Sala.o \
	Clases/Pelicula.o \
	Clases/Funcion.o \
	Clases/Usuario.o \
	Clases/Reserva.o \
	Clases/Comentario.o \
	Clases/Puntaje.o \
	Clases/Sesion.o \
	Clases/Credito.o \
	Clases/Debito.o \
	DataTypes/DtDireccion.o \
	DataTypes/DtPelicula.o \
	DataTypes/DtFecha.o \
	DataTypes/DtHorario.o \
	DataTypes/DtCine.o \
	DataTypes/DtFuncion.o \
	DataTypes/DtSala.o \
	DataTypes/DtCredito.o \
	DataTypes/DtReserva.o \
	DataTypes/DtDebito.o \
	main.o

main: $(OBJS)
	$(CXX) $(OBJS) -o cine

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) cine

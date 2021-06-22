GDAL_HOME = /home/francesco/Software/OSGeo4W/gdal-323-x86_64-linux-bin
LDFLAGS = -L$(GDAL_HOME)/lib
LIBS = -lgdal
CPPFLAGS = -Iinclude
CXXFLAGS =
CC  = gcc
CXX = g++
LD  = g++
RM  = rm -f
EEXT =
OEXT = .o
TARGET = ex1

.PHONY: clean distclean all

all: $(TARGET)$(EEXT)

$(TARGET)$(OEXT): $(TARGET).cpp
	$(CXX) -c $< $(CPPFLAGS) -o $@

$(TARGET)$(EEXT): $(TARGET)$(OEXT)
	$(LD)  $< -o $@  $(LDFLAGS) $(LIBS)

clean:
	$(RM) $(TARGET).o

distclean: clean
	$(RM) $(TARGET) test.tif

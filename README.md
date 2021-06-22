# c++ raster image creation example linking gdal library

## update the Makefile with the actual path of your GDAL installation

### to compile on GNU/linux
make -f Makefile.lnx
### to remove obj on GNU/linux
make -f Makefile.lnx clean
### to remove all on GNU/linux
make -f Makefile.lnx distclean 

### to compile on MS win
mingw32-make -f Makefile.mingw
### to remove obj on MS win
mingw32-make -f Makefile.mingw clean
### to remove all on MS win
mingw32-make -f Makefile.mingw distclean 

### to run on unix like / msys:
./ex1

### to run on win cmd terminal
ex1

it will create an image file : test.tif


#include "gdal.h"

void create_new_tiff(char * DstFilename, int nx, int ny);

int main()
{
	char  filename[10] = "test.tif";
	unsigned short int nx, ny;
	nx = 600;
	ny = 500;
	create_new_tiff(filename, nx, ny);
	return 0;
}

void create_new_tiff(char * DstFilename, int nx, int ny)
{

	const char *pszFormat = "GTiff";
	int test[nx*ny];
	GDALDatasetH hDstDS;
	GDALRasterBandH hBand;
	char **papszOptions = NULL;

	GDALAllRegister();
	GDALDriverH hDriver = GDALGetDriverByName( pszFormat );

	hDstDS = GDALCreate( hDriver, DstFilename, nx, ny, 1, GDT_Int16, papszOptions);
	hBand = GDALGetRasterBand( hDstDS, 1 );

	for(int i=0; i<nx*ny; i++) test[i] = i%65536;

	CPLErr Err = GDALRasterIO( hBand, GF_Write, 0, 0, nx, ny, test, nx, ny, GDT_Int16, 0, 0);
	GDALClose( hDstDS );
}


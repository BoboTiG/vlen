
/* ======================================================== */
/*	$Author: BoboTiG <bobotig@gmail.com> $                  */
/*	$Id: vlen $                                             */
/*	$Revision: 4 $, $Date: 2011/08/06 $                     */
/*	$Source: http://www.bobotig.fr $, $Date: 2010/07/18 $   */
/*                                                          */
/*	vlen détermine la durée d'une vidéo.                    */
/* ======================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <opencv/highgui.h>

int main(int argc, char *argv[]) {
	CvCapture* video = 0;
	double fps, total, len, h, m, s, r = 0;
	unsigned int quiet = 0;
	
	if ( argc < 2 ) {
		printf("Usage : vlen FICHIER [-q]\n");
		return EXIT_FAILURE;
	}
	if ( ! strcmp(argv[1], "-h") || ! strcmp(argv[1], "--help") ) {
		printf("Copyright (C) 2010-2012 by BoboTiG.\n\
\n\
vlen comes with ABSOLUTELY NO WARRANTY.\n\
This is free software, and you are welcome to redistribute it under \n\
certain conditions. See the GNU General Public Licence for details.\n\
\n\
vlen détermine la durée d'une vidéo.\n\
\n\
Usage : vlen FICHIER [-q]\n\
\n\
Options :\n\
 -h,  --help		affiche ce message\n\
 -q,  --quiet		affiche la durée seulement\n\
 -v,  --version		affiche les versions du programme et d'OpenCV\n\
\n\
Rapporter erreurs, suggestions et commentaires à <bobotig@gmail.com>.\n");
		return EXIT_SUCCESS;
	} else if ( ! strcmp(argv[1], "-v") || 
	            ! strcmp(argv[1], "--version") ) {
		printf("vlen v0.2.\nOpenCV v%s.\n", CV_VERSION);
		return EXIT_SUCCESS;
	}
	if ( argv[2] ) {
		if ( ! strcmp(argv[2], "-q") || ! strcmp(argv[2], "--quiet") ) {
			quiet = 1;
		}
	}
	video = cvCreateFileCapture(argv[1]);
	if ( ! video ) {
		if ( ! quiet ) {
			printf("Impossible de charger la vidéo : %s\n", argv[1]);
		}
		return EXIT_FAILURE;
	}
	cvQueryFrame(video);
	fps = (double) cvGetCaptureProperty(video, CV_CAP_PROP_FPS);
	total = (double) cvGetCaptureProperty(video, CV_CAP_PROP_FRAME_COUNT);
	cvReleaseCapture(&video);
	len = total / fps;
	h = len / (double) 3600;
	r = fmod(len, (double) 3600);
	m = r / (double) 60;
	s = fmod(r, (double) 60);
	if ( quiet ) {
		printf("%02d:%02d:%06.3f\n", (int) h, (int) m, s);
	} else {
		printf("Fichier : %s\n", argv[1]);
		printf("FPS     : %.3f\n", fps);
		printf("Total   : %.0f\n", total);
		printf("Durée   : %02d:%02d:%06.3f\n", (int) h, (int) m, s);
	}
	return EXIT_SUCCESS;
}

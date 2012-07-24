
/* ======================================================== */
/*	$Author: BoboTiG <bobotig@gmail.com> $                  */
/*	$Id: vlen $                                             */
/*	$Revision: 3 $, $Date: 2011/02/05 $                     */
/*	$Source: http://www.bobotig.fr $, $Date: 2010/07/18 $   */
/*                                                          */
/*	vlen is a tool to get the duration of a video file.     */
/* ======================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <opencv/highgui.h>

int main(int argc, char *argv[]) {
	CvCapture* video = 0;
	double fps, total, len, h, m, s, r = 0;
	unsigned int quiet	= 0;
	
	if ( argc < 2 ) {
		printf("Usage : vlen FILE [-q]\n");
		return EXIT_FAILURE;
	}
	if ( ! strcmp(argv[1], "-h") || ! strcmp(argv[1], "--help") ) {
		printf("Copyright (C) 2010-2011 by BoboTiG.\n\
\n\
vlen comes with ABSOLUTELY NO WARRANTY.\n\
This is free software, and you are welcome to redistribute it under \n\
certain conditions. See the GNU General Public Licence for details.\n\
\n\
vlen is a tool to get the duration of a video file.\n\
\n\
Usage : vlen FILE [-q]\n\
\n\
Options :\n\
 -h,  --help		display this message\n\
 -q,  --quiet		only print video duration\n\
 -v,  --version		print tools version\n\
\n\
Report bugs, suggestions and comments to <bobotig@gmail.com>.\n");
		return EXIT_SUCCESS;
	} else if ( ! strcmp(argv[1], "-v") || 
	            ! strcmp(argv[1], "--version") ) {
		printf("vlen v0.1d.\nOpenCV library v%s.\n", CV_VERSION);
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
			printf("Could not load video file : %s\n", argv[1]);
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
		printf("File     : %s\n", argv[1]);
		printf("FPS      : %.3f\n", fps);
		printf("Count    : %.0f\n", total);
		printf("Duration : %02d:%02d:%06.3f\n", (int) h, (int) m, s);
	}
	return EXIT_SUCCESS;
}

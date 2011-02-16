#include <stdio.h>
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "capture.h"

int frames;

//image resolution
int W = 320;
int H = 240;

CvCapture *capture = 0; // Structure for getting video from camera or avi
int frame_number = 1;
//CvVideoWriter *writer;

//Initialize capture from avi
/*int initVideoCapture()
{

//capture = cvCreateFileCapture("C:/Documents and Settings/mikesapi/Desktop/Thesis Material/Ground Truth/ssm/ssm1.avi");
	//capture = cvCreateFileCapture("C:/Documents and Settings/mikesapi/Desktop/Thesis Material/Ground Truth/jam/jam9.avi");
	//capture = cvCreateFileCapture("C:/Documents and Settings/mikesapi/Desktop/Thesis Material/Screenshots/me3.avi");
	frames = (int) cvGetCaptureProperty(
		capture,
		CV_CAP_PROP_FRAME_COUNT
		);
	double fps = cvGetCaptureProperty(
			capture,
			CV_CAP_PROP_FPS);
	CvSize size = cvSize(
		(int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH),
		(int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT)
		);
	int isColor = 1;
	writer = cvCreateVideoWriter(
	"C:/Documents and Settings/mikesapi/Desktop/Thesis Material/Ground Truth/ssm/my_ssm.avi",
		CV_FOURCC('P','I','M','1'),
		30,
		size,
		isColor
		);

	printf("no of frames = %d", frames);

	if( !frames )
	{
		fprintf(stderr, "failed to initialize camera capture\n");
		return 0;
	}

	return 1;
}*/

// Initialize capture from camera
int initCapture()
{
	// Initialize video capture
	capture = cvCaptureFromCAM( CV_CAP_ANY );

	cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH, W );
	cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT, H );
	
	if( !capture )
	{
		fprintf(stderr, "failed to initialize camera capture\n");
		return 0;
	}

	return 1;
}

void closeCapture()
{
	// Terminate video capture and free capture resources
	cvReleaseCapture( &capture );
	//cvReleaseVideoWriter( &writer );

	return;
}


// Get the next frame from the camera
IplImage * nextFrame()
{
	IplImage * frame = cvQueryFrame( capture );

	if( !frame ){
		fprintf(stderr, "failed to get a video frame\n");
		//frame_number = frame_number -1;

		return NULL;
	}

	//frame_number++;
	//printf("frame_number = %d", frame_number);   

	/*if(frame_number == 2 ){
		cvSaveImage("C:/Documents and Settings/mikesapi/Desktop/Thesis Material/Ground Truth/jam/jam1.jpg",  frame);
	}
		if(frame_number == 51){
		cvSaveImage("C:/Documents and Settings/mikesapi/Desktop/Thesis Material/Ground Truth/jam/jam50.jpg",  frame);
	}
			if(frame_number == 101){
		cvSaveImage("C:/Documents and Settings/mikesapi/Desktop/Thesis Material/Ground Truth/jam/jam100.jpg",  frame);
	}
				if(frame_number == 151){
		cvSaveImage("C:/Documents and Settings/mikesapi/Desktop/Thesis Material/Ground Truth/jam/jam150.jpg",  frame);
	}
					if(frame_number == 200){
		cvSaveImage("C:/Documents and Settings/mikesapi/Desktop/Thesis Material/Ground Truth/jam/jam200.jpg",  frame);
	}*/


	
	return frame;
}

/*
void printResults(float roll[], float yaw[], float pitch[])
   {
      FILE *fp;
      int i;
   
      //open the file 
      //fp = fopen("C:/Documents and Settings/mikesapi/Desktop/Thesis Material/Ground Truth/ssm/my_ssm7.txt", "w");
      //fp = fopen("C:/Documents and Settings/mikesapi/Desktop/Thesis Material/Ground Truth/jam/my_jam4.txt", "w");
		//fp = fopen("C:/Documents and Settings/mikesapi/Desktop/Thesis Material/Screenshots/me3.txt", "w");
	  
      if (fp == NULL) {
         printf("I couldn't open results.dat for writing.\n");
         exit(0);
      }
   
      //write to the file
      for (i=1; i<=frames+1; ++i)
		 
         fprintf(fp, "%d,		%0.6f,		%0.6f,			%0.6f\n", i, roll[i], yaw[i], pitch[i]);
   
      //close the file
      fclose(fp);
   
      return;
   }
*/


/*void writeVideo( IplImage* frame)
{
	cvWriteFrame( writer, frame);
	
	
}
*/

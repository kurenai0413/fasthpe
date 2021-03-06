/*
Copyright (C) 2010 Michael Sapienza
   
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FACE_FEATURE_TRACK_H
#define FACE_FEATURE_TRACK_H

//include templates structure

void closeTemplateMatch();
int initTracker(IplImage* frame, Face* F );
//int dynamicTracker(IplImage* frame, CvPoint L, CvPoint R, CvPoint N, CvPoint M );
IplImage* trackObject( IplImage* frame, Face* F, FaceGeom* G);

#endif
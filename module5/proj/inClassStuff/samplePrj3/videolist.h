#ifndef VIDEOLIST_H
#define VIDEOLIST_H
//class object for a list of videos
#include "video.h"

//constants
const int CAP = 100;

//define class VideoList for array of videos and size

class VideoList
{
	private:
		Video list[CAP];
		int size;
	public:
		//constructors
		VideoList();
		VideoList(char []);
		//destructor
		~VideoList();
		//database functions
		void addVideo(Video);
		void searchByTitle();
		void searchByGenre();
		void showList();
		void removeVideo();
		void writeData(char []);
};

#endif

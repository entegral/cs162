// songList.h
#ifndef songList_h
#define songList_h
#include "main.h"

class SongList
{
	private:
		Song list[CAP];
        int size;

	public:
        songList();
        void addToLibrary(Song[], int &);
		void displayLibrary(Song[], int &);
		void removeFromLibrary(Song [], int &);
		void searchForSongs(Song [], int &);
};


#endif

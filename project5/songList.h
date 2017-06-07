#ifndef VIDEOLIST_H
#define VIDEOLIST_H

#include "song.h"

// define SongList class and for array and library size

class SongList
{
	private:
		struct Node {
			Song data;
			Node *next, *prev;
		};
		int size;
		Node *head, *tail;

	public:
		// constructors
		SongList();
		SongList(char fileName[]);
		// destructors
		~SongList();

		void addNode(Node *);
        void addToLibrary();
		void displayLibrary();
		void displayLibrary(Node *);
		void removeFromLibrary();
//		void searchForSongs();
//		// void searchForSongs();
//		void writeData(char []);
};


#endif

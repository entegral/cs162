// song.h
#ifndef song_h
#define song_h

using namespace std;

// constants
const int CAP = 100;
const int MAXCHAR = 101;

// main function prototypes
void printMenu();
bool quitProgram();

// tool prototypes
int intInput();
char charInput();
void charArrayInput(char input[]);

// database funtion prototypes
void openFile(char [], ofstream &);
void writeData(const Song [], int &, ofstream &);
void openFile(char [], ifstream &);
void loadData(ifstream &, Song[], int &);

class Song
{
	private:
		char title[MAXCHAR];
		char artist[MAXCHAR];
		char album[MAXCHAR];
		int durationMin;
		int durationSec;

// add custom and default constructor for Songs
// add mutator and accessor functions for songs
//	 	- mutators - setTitle(), setArtist(), setDurationMin(), setDurationSec(), setAlbum()
	public:
		song();
		song(char [], char [], int, int, char []);
		void printSongInfo();
};

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

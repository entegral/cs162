//This is the implementation file for VideoList class
#include "videolist.h"
#include "tools.h"

//constructors
VideoList::VideoList()
{
	size = 0;
}

//constructor from file
VideoList::VideoList(char fileName[])
{
	size = 0;
	ifstream inFile;
	Video aVideo;
	char tempTitle[MAXCHAR], genreDesc[MAXCHAR];
	int tempQty;
	Genre tempGenre;
	double tempRating;

	inFile.open(fileName);
	if(!inFile)
	{
		cout << "cannot open file! Exiting!!" << endl;
		exit(0);
	}

	inFile.getline(tempTitle, MAXCHAR, ';');
	while(!inFile.eof())
	{
		inFile.getline(genreDesc, MAXCHAR, ';');
		tempGenre = readGenre(genreDesc[0]);
		inFile >> tempQty;
		inFile.ignore(5, ';');
		inFile >> tempRating;
		inFile.ignore(5, '\n');
		//populate aVideo;
		aVideo.setTitle(tempTitle);
		aVideo.setGenre(tempGenre);
		aVideo.setQty(tempQty);
		aVideo.setRating(tempRating);
		addVideo(aVideo);
		inFile.getline(tempTitle, MAXCHAR, ';');
	}
	inFile.close();
}

//destructor
VideoList::~VideoList()
{
//nothing to do
}

//Add a video to the store
void VideoList::addVideo(Video aVideo)
{
	list[size++] = aVideo;
}

//search by Title
void VideoList::searchByTitle()
{
	char searchTitle[MAXCHAR];
	char tempTitle[MAXCHAR];
	cout << "Please enter title to search for:";
	cin.get(searchTitle, MAXCHAR);
	convertCase(searchTitle);
	for(int i = 0; i < size; i++)
	{
		list[i].getTitle(tempTitle);
		convertCase(tempTitle);
		if(strstr(tempTitle, searchTitle) != NULL)
		{
			list[i].printVideo();
		}
	}
}

//search by Genre
void VideoList::searchByGenre()
{
	char letter;
	Genre srchGenre;
	Genre tempGenre;
    cout << "Please enter the genre to search for (A-ACTION, F-FAMILY, C-COMEDY, H-HORROR):";
    cin >> letter;
    srchGenre = readGenre(letter);
    for(int i = 0; i < size; i++)
    {
		tempGenre = list[i].getGenre();
        if(srchGenre == tempGenre)
        {
			list[i].printVideo();
        }
    }
}

//writes the data to the file
void VideoList::writeData(char fileName[])
{
	ofstream outFile;
	outFile.open(fileName);
	for(int i = 0; i < size; i++)
	{
		list[i].printVideo(outFile);
	}
}
	
//displays the list
void VideoList::showList()
{
	for(int i = 0; i < size; i++)
	{
		cout << i+1 << ") ";
		list[i].printVideo();
	}
	cout << endl;
}

//removes a video from the list
void VideoList::removeVideo()
{
	int delIndex = 0;
    delIndex = readInt("Please enter index of video to delete:");
    if(delIndex < size)
    {
         for(int i = delIndex; i < size; i++)
        {
            list[i-1] = list[i];
        }
    }
    size--;
}


	






	
	































	

//This is the implementation file for video.h (the Video class)
#include "video.h"

//default constructor
Video::Video()
{
	strcpy(title, "No title");
	genre = ILLEGAL;
	qty = 0;
	rating =0;
}

//constructor with parameters
Video::Video(char tempTitle[], Genre tempGenre, int tempQty, double tempRating)
{
	strcpy(title, tempTitle);
	genre = tempGenre;
	qty = tempQty;
	rating = tempRating;
}

//destructor
Video::~Video()
{

//nothing to do now
}

//mutator functions
void Video::setTitle(char newTitle[])
{
	strcpy(title, newTitle);
}

void Video::setGenre(Genre newGenre)
{
	genre = newGenre;
}

void Video::setQty(int newQty)
{
	qty = newQty;
}

void Video::setRating(double newRating)
{
	rating = newRating;
}

//accessor functions
void Video::getTitle(char returnTitle[]) const
{
	strcpy(returnTitle, title);
}

Genre Video::getGenre() const
{
	return genre;
}

int Video::getQty() const
{
	return qty;
}

double Video::getRating() const
{
	return rating;
}

//prints to console
void Video::printVideo()
{
	char genreDesc[MAXCHAR];
	printGenre(this->genre, genreDesc);
	cout << title << ';' << genreDesc << ';' << qty << ';' << rating << endl;
}

//prints to file
void Video::printVideo(ofstream &outFile)
{
	char genreDesc[MAXCHAR];
    printGenre(this->genre, genreDesc);
	outFile << title << ';' << genreDesc << ';' << qty << ';' << rating << endl;
}	


//This function assigns a Genre based on the letter and returns the Genre
Genre readGenre(char letter)
{
    Genre tempGenre;
    switch(tolower(letter))
    {
        case 'a':
            tempGenre = static_cast<Genre>(0);
            break;
        case 'f':
            tempGenre = static_cast<Genre>(1);
            break;
        case 'c':
            tempGenre = static_cast<Genre>(2);
            break;
        case 'h':
            tempGenre = static_cast<Genre>(3);
            break;
        default:
            tempGenre = static_cast<Genre>(4);
    }
    return tempGenre;
}

//This function populates the genreDesc based on the Genre
void printGenre(Genre tempGenre, char genreDesc[])
{
    switch(tempGenre)
    {
        case 0:
            strcpy(genreDesc, "ACTION");
            break;
        case 1:
            strcpy(genreDesc, "FAMILY");
            break;
        case 2:
            strcpy(genreDesc, "COMEDY");
            break;
        case 3:
            strcpy(genreDesc, "HORROR");
            break;
        case 4:
            strcpy(genreDesc, "ILLEGAL");
            break;
    }
    return;
}

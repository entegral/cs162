all: video

video: videolist.o video.o tools.o driver.o
	g++ videolist.o video.o tools.o driver.o -o video

videolist.o: videolist.cpp
	g++ -c videolist.cpp
video.o: video.cpp
	g++ -c video.cpp

driver.o: driver.cpp
	g++ -c driver.cpp

tools.o: tools.cpp
	g++ -c tools.cpp

clean:
	rm *.o video	

#ifndef TEHATER_H
#define TEHATER_H

#define ROW 10
#define COL 7
class Theater  // ±ØÀå ÁÂ¼®
{
	int seat[ROW][COL];
public:
	Theater();
	void setSeat(int v, int row, int col);
	int getSeat(int row, int col);
	void printSeat();
};

#endif



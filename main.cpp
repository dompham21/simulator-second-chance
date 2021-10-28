/* 
graphics in Dev-C++ - nguyenvanquan7826 
*/
#include <bits/stdc++.h>
#include <iostream>
#include <winbgim.h> 

using namespace std;
const int WIDTH = 1330;
const int HEIGHT = 800;
bool isRunning = false;


char* itegerToChar(int x) {
	char iTemp[10];
	itoa(x, iTemp, 10);
	return iTemp; 
}

/* ===== MAP ID ===== */
void khoi_tao_mapID(short **mapID){
	for(short i=0; i<=WIDTH; i++){
		for(short j=0; j<=HEIGHT; j++){
			mapID[i][j] = 0;
		}
	}
}

void giai_phong_mapID(short **mapID){
	for(short x = 0; x <= WIDTH; x++)  
		delete[] mapID[x];
	delete[] mapID;
}

// Set mot vung id 
void setID(int x1,int y1,int x2,int y2, int ID,short **mapID){
	for(short x=x1;x<=x2;x++){
		for(short y = y1;y<=y2;y++) {
			mapID[x][y] = ID;
		}
	}
}
/* ===== END MAP ID ===== */


void tao_button(int x1,int y1,int x2,int y2,char* a,int color,int color_text, int ID, short **mapID){
	setfillstyle(1,color);
	bar(x1,y1,x2, y2);
	
	settextstyle(10,0,1);
	setbkcolor(color);
	setcolor(color_text);

	outtextxy(x1+(x2-x1)/2 - strlen(a)*12/2,y1+5,a);	
	setbkcolor(11); //reset lai bk


	setID(x1,y1,x2,y2,ID,mapID);
	

}
void tao_o(int x,int y,int x2,int y2){
	setfillstyle(1, 15);
	bar(x, y, x + x2, y + y2);
	setcolor(0);
	rectangle(x,y,x+x2,y+y2);
}

void tao_dong(int x,int y,int chieu_cao,int slcot, int rong){
	for(int i=0;i<slcot;i++){
		tao_o(x,y,rong,chieu_cao);
		x += rong;
	}
}

void tao_bang(int x, int y, int chieu_cao, int slcot, int sldong, int rong) {
	int vt = y;

	for(int i = 0; i < sldong; i++) {
		vt = y + chieu_cao*i;
		tao_dong(x, vt, chieu_cao, slcot, rong);
				
	}

}


void drawArrow(int x, int y, int x2, int y2) {
	line(x+100,y+50,x2+150,y+50);
	line(x2+130, y+35, x2+150, y+50);
	line(x2+130, y+65, x2+150, y+50);

}

void drawQueue(int x, int y, int x2, int y2) {
	setfillstyle(1, 15);
	setcolor(0);
	settextstyle(10,0,4);

	
	
	bar(x, y, x + x2, y + y2);
	rectangle(x, y, x+x2, y+y2);
	
	bar(x + x2 + 150, y, x + x2 + 250, y + y2);
	rectangle(x + x2 + 150, y, x+x2 + 250, y+y2);

	bar(x + x2 + 400, y, x + x2 + 500, y + y2);
	rectangle(x + x2 + 400, y, x+x2 +500, y+y2);
	
	setcolor(COLOR(247,145,31)); //color orange with rbg
	
	bar(x - x2 - 150, y, x + x2 - 250, y + y2);
	rectangle(x - x2 - 150, y, x+x2 - 250, y+y2);
	
	bar(x + x2 + 650, y, x + x2 + 750, y + y2);
	rectangle(x + x2 + 650, y, x+x2 +750, y+y2);
	

	outtextxy(40, y - 50, "Dequeue");
	outtextxy(x + x2 + 640, y - 50, "Enqueue");
	setcolor(0);

	drawArrow(x, y, x+x2, y+y2);
	drawArrow(x + x2 + 150, y, x+x2 + 250, y+y2);



}

void drawPage(vector<int> t) {
	settextstyle(10,0,4);	
	setcolor(0);
	outtextxy(15, 450, "So loi trang: 0");
	int n = t.size(); 
	for(int i=0;i<n;i++) {
		outtextxy(25 + i*65,550,itegerToChar(t[i]));
	}
}



void printQueue(deque<int> q, deque<bool> bitref, int x, int y) 
{
	setbkcolor(15);
	settextstyle(10,0,3);
	deque<int> temp = q;
	int i=0;
	//printing content of queue 
	while (!temp.empty()){
	settextstyle(10,0,3);

		outtextxy(x, y + i*45 + 5,itegerToChar(temp.front()));
		char res[20] = "";
		strcat(res,"(");
		strcat(res,itegerToChar(bitref[i]));
		strcat(res,")");

		outtextxy(x + 14, y + i*45 + 5,res);

		settextstyle(10,0,5);
		
		outtextxy(335 + i*250, 280, itegerToChar(temp.front()));
		settextstyle(10,0,4);

		delay(1200);

		temp.pop_front();
		i++;
	}
}

void printPopQueue(deque<int> q) {
	setfillstyle(1, 15);
	settextstyle(10,0,5);

	outtextxy(335, 280, itegerToChar(q[0]));
	outtextxy(585, 280, itegerToChar(q[1]));
	setbkcolor(15);
	bar(835, 280, 870, 320);

}


 

int getPosition(deque<int> q, int x) {
	for(int i=0;i<3;i++) {
		if(x == q[i]) {
			return i;
		}
	}
}

bool checkBitRef( deque<bool> bitref) {
	for(int i=0;i<3;i ++) {
		if(bitref[i] == 0) {
			return false;
		}
	}
	return true;
}

// Function to find an element in the queue 
bool findQueue(deque<int> q, int x)
{
	while (!q.empty()) {
		if (x == q.front())
			return true;
		q.pop_front();
	}

	// Element not found
	return false;
}


// Function to implement LRU Approximation Second Chance
void SecondChance(vector<int> t, int frames)
{
	
	int n = t.size();
	deque<int> q;

	
	int hits = 0, faults = 0;

	deque<bool> second_chance;

	bool bitref[3] = { 1, 1, 1};

	// To check if the queue is filled up or not
	int count = 0;

	for (int i = 0; i < t.size(); i++) {
		
		if (!findQueue(q, t[i])) {
                
			// Queue is not filled up to capacity
			if (count < frames) {
				q.push_back(t[i]);
				second_chance.push_back(true);
				settextstyle(10,0,5);
				setbkcolor(15);
				outtextxy(1090, 280, itegerToChar(t[i]) );
				count++;
			}

			// Queue is filled up to capacity
			else {
				if(checkBitRef(second_chance)) {
					for(int i=0;i<frames;i++ ) {
						second_chance[i] = false;
					}
				}
				
				settextstyle(10,0,5);
				setbkcolor(15);
				
				outtextxy(90, 280, itegerToChar(q.front()));

				q.pop_front();
				q.push_back(t[i]);
				printPopQueue(q);

				
				outtextxy(1090, 280, itegerToChar(t[i]) );
				
				second_chance.pop_front();
				second_chance.push_back(true);
			}
			faults ++;
			setbkcolor(11);
			settextstyle(10,0,4);
			outtextxy(25 + i*65, 750,"*");
			char res[30] = "";
			
			strcat(res, "So loi trang: ");
			strcat(res, itegerToChar(faults));
			outtextxy(15, 450, res);
	
			
		}

		// If the input for the iteration was a hit
		else {
			int pos = getPosition(q, t[i]);
			
			if(pos == 1) {
				int x = q[pos];
				q[pos] = q[2];
				q[2] = x;
					
			}
			else {
				settextstyle(10,0,5);
				setbkcolor(15);
				int t1 = q.front();
				

				q.pop_front();
				q.push_back(t1);
								
			}	
			bar(90, 280, 140, 320);
			bar(1090, 280, 1140, 320);


			second_chance.pop_front();
			second_chance.push_back(true);	
				
			hits ++;
			
		}
			
		printQueue(q, second_chance, 15 + i*65, 605);
		
        

    }
    
    isRunning = false; //end 
    
}


void checkMouse(short **mapID, int idButton, vector<int> t, int frames) {
	int x = - 1, y = -1;


	while (1) {
		delay(0.001); //delay nhan click 
			
		int ID = 0;
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,x,y);
			ID = mapID[x][y];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(x != -1 && y != -1 && isRunning == false)
		switch(ID) {
			case 1: {
				SecondChance(t, frames);				
				isRunning = true;
				break;
			}
			default:
				break;			
		}
		
	}
}

int main(int argc, char *argv[])
{
	// now, you can run project
	initwindow(WIDTH, HEIGHT);			// init window graphics
	setbkcolor(11);					// set background
   	cleardevice();
   	
	setcolor(COLOR(247,145,31)); //color orange with rbg
	settextstyle(10,0,5);
	setlinestyle(0,1,2);
	
	/*========MapID=========*/
   	short **mapID = new short*[WIDTH+1]; 
	
	for(int x = 0;x <= WIDTH;x++) {
		mapID[x] = new short[HEIGHT+1];
	} 
	
	khoi_tao_mapID(mapID);	


	/*=====================*/
	
	outtextxy(300,50,"THUAT TOAN CO HOI THU HAI");
	
	int arr[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0 ,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	vector<int> t (arr, arr + n); //Convert to vector
	int frames = 3;  //So khung trang
	
	int ID = 1;
	
	drawQueue(300, 250, 100, 100);
	drawPage(t);
	tao_bang(10, 600, 45, n, 3, 65);
	tao_button(1000,60,1120,90,"Bat dau",13,0,1,mapID);
	
	checkMouse(mapID, ID, t, frames);
	while(!kbhit()) delay(1);		// pause screen	
	return 0;
}

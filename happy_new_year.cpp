#include "happy_new_year.h"
// main
// ====================================================================
int main() {
	init_sky();
	init_urban();

	night();
	return 0;
}


// implement
// ====================================================================
string getAscii(string path) {
	string result, temp;
	ifstream in(path+".txt");
	while(getline(in, temp)){
		result += temp + '\n'; 
	};
	in.close();
	return result;
}

void night(){
		
	moveObject();
}

void morning(){
	string sun = getAscii("sun");
}

void moveObject() {
	int x = 0, ck_x = 0;
	while(ck_x < CANVAS_SKY_X){
		init_sky();
		// text
		for(int y = 0; y < TEXT_HEIGHT; y++) {
			for(int x = 0; x < TEXT_WIDTH; x++) {
				if(x >= ck_x) break;
				canvas_sky[y][x+10] = text[y][x];
			}
		}
		// sun
		for(int y = 0; y < SUN_HIEIGHT; y++) {
			for(int x = 0; x < SUN_WIDTH; x++) {
				canvas_sky[y][x+ck_x+10] = sun[y][x];
			}
		}
		ck_x++;
		system("clear");
		print_sky();	
		print_urban();	
		usleep(1000*200);
	}
}

// 더 높은 추상화 가능
void init_sky() {
	memset(canvas_sky, ' ', sizeof(canvas_sky) );	
}
/*
void init_night() {
	string night_sky = getAscii("night_sky");
	int y = 0, x = 0;
	for(auto& ch : night_sky) {
		if(ch != '\n') {
			canvas_sky[y][x] = ch;
			x++;
			continue;
		}
		x = 0;
		y++;
		if(y == CANVAS_SKY_Y) break;
	}
}
*/

void init_urban() {
	string urban = getAscii("urban");
	int y = 0, x = 0;
	for(auto& ch : urban) {
		if(ch != '\n') {
			canvas_urban[y][x] = ch;
			x++;
			continue;
		}
		x = 0;
		y++;
		if(y == CANVAS_URBAN_Y) break;
	}
}

void print_sky() {
	for(int y = 0; y < CANVAS_SKY_Y; y++){
		for(int x = 0; x < CANVAS_SKY_X; x++) {
			move(y,x);
			cout << canvas_sky[y][x];
		}
		cout << '\n';
	}
}

void print_urban(){
	for(int y = 0; y < CANVAS_URBAN_Y; y++){
		for(int x = 0; x < CANVAS_URBAN_X; x++) {
			cout << canvas_urban[y][x];
		}
		cout << '\n';
	}
}



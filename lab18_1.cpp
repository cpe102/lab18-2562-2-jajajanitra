#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect,Rect);

int main(){
	Rect a,b;
	cout << "Please input Rect 1 (x y w h): ";
	cin >> a.x >> a.y >> a.w >> a.h;
	cout << "Please input Rect 2 (x y w h): ";
	cin >> b.x >> b.y >> b.w >> b.h;
	cout << "Overlap area = " << overlap(a,b);
	return 0;
}

double overlap(Rect a,Rect b)
{
	double xa = a.x + a.w;
	double ya = a.y - a.h;
	double xb = b.x + b.w;
	double yb = b.y - b.h;
	double minx,maxx,miny,maxy,result;
	if(a.x > b.x){minx = a.x;}else{minx = b.x;}
	if(xa < xb){maxx = xa;}else{maxx = xb;}
	if(a.y < b.y){miny = a.y;}else{miny = b.y;}
	if(ya > yb){maxy = ya;}else{maxy = yb;}
	if(maxx-minx > 0 && maxy-miny < 0){result = -((maxx-minx)*(maxy-miny));}
	else{result = 0;}

	return result;

}
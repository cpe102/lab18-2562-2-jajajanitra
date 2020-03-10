#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *,Rect *);

int main(){
	Rect a,b;
    Rect *p = &a,*q =&b;
	cout << "Please input Rect 1 (x y w h): ";
	cin >> p->x >> p->y >> p->w >> p->h;
	cout << "Please input Rect 2 (x y w h): ";
	cin >> q->x >> q->y >> q->w >> q->h;
	cout << "Overlap area = " << overlap(&a,&b);
	return 0;
}

double overlap(Rect *p,Rect *q)
{
	double xa = p->x + p->w;
	double ya = p->y - p->h;
	double xb = q->x + q->w;
	double yb = q->y - q->h;
	double minx,maxx,miny,maxy,result;
	if(p->x > q->x){minx = p->x;}else{minx = q->x;}
	if(xa < xb){maxx = xa;}else{maxx = xb;}
	if(p->y < q->y){miny = p->y;}else{miny = q->y;}
	if(ya > yb){maxy = ya;}else{maxy = yb;}
	if(maxx-minx > 0 && maxy-miny < 0){result = -((maxx-minx)*(maxy-miny));}
	else{result = 0;}

	return result;

}

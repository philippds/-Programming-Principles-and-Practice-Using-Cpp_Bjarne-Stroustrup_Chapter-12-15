//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 15 Shape Graphing Drill 1

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

constexpr int xmax = 600;
constexpr int ymax = 600;

constexpr int x_orig = xmax / 2;
constexpr int y_orig = ymax / 2;
Point orig(x_orig, y_orig);

constexpr int r_min = -10;
constexpr int r_max = 11;

constexpr int n_points = 400;

constexpr int x_scale = 30;
constexpr int y_scale = 30;

double one(double x)
{
	return 1;
}

int main()
try
{
	Point tl(100, 100);
	Simple_window win(tl, xmax, ymax, "Function graphs.");
	
	Axis x(Axis::x, Point(orig.x - 200, orig.y), 400, 20, "1 == 20");
	x.set_color(Color::red);

	Axis y(Axis::y, Point(orig.x, orig.y + 200), 400, 20, "1 == 20");
	y.set_color(Color::red);

	Function f1(one, r_min, r_max, orig, n_points);
	f1.set_color(Color::black);

	win.attach(f1);

	win.attach(x);
	win.attach(y);

	win.wait_for_button();
}
catch (exception& e) {
	cout << e.what() << endl;
	return 1;
}
catch (...) {
	cout << "Exiting" << endl;
	return 2;
}
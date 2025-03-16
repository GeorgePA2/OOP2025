#include "Canvas.h"
#include <iostream>
Canvas::Canvas(int width, int height) : width(width), height(height) {
	this->canvas = new char*[width];
	for (int i = 0; i < width; i++) {
		this->canvas[i] = new char[height];
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j <= height; j++) {
			this->canvas[i][j] = ' ';
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch) {
	this->canvas[x][y] = ch;
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	int t;
	if (left > right) {
		t = left;
		left = right;
		right = t;
	}
	if (bottom < top) {
		t = top;
		top = bottom;
		bottom = t;
	}
	for (int i = left; i <= right; i++) {
		this->canvas[top][i] = ch;
		this->canvas[bottom][i] = ch;
	}
	for (int i = top; i <= bottom; i++) {
		this->canvas[i][left] = ch;
		this->canvas[i][right] = ch;
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	int t;
	if (left > right) {
		t = left;
		left = right;
		right = t;
	}
	if (bottom < top) {
		t = top;
		top = bottom;
		bottom = t;
	}
	for (int i = top + 1; i < bottom; i++) {
		for (int j = left + 1; j < right; j++) {
			this->canvas[i][j] = ch;
		}
	}
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	if (abs(y1 - y2) < abs(x1 - x2)) {
		printf("realizam cazul 1 \n");
		if (x1 > x2) {
			int t = x1;
			x1 = x2;
			x2 = t;
		}
		int dx = x2 - x1;
		int dy = y2 - y1;
		int yi = 1;
		if (dy < 0) {
			yi = -1;
			dy = -dy;
	}
		int D = (2 * dy) - dx;
		int y = y1;

		for (int x = x1; x <= x2; x++) {
			this->canvas[y][x] = ch;
			if (D > 0) {
				y = y + yi;
				D = D + (2 * (dy - dx));
			}
			else {
				D = D + 2 * dy;
			}
		}
	}
	else {
		printf("realizam cazul 2 \n");
		if (y1 > y2) {
			int t = y1;
			y1 = y2;
			y2 = t;
		}
		if (x1 > x2) {
			int t = x1;
			x1 = x2;
			x2 = t;
		}
		int dx = x2 - x1;
		int dy = y2 - y1;
		int xi = 1;
		if (dx < 0) {
			xi = -1;
			dx = -dx;
		}
		int D = (2 * dx) - dy;
		int x = x1;
		for (int y = y1; y < y2; y++) {
			this->canvas[x][y] = ch;
			if (D > 0) {
				x = x + xi,
					D = D + (2 * (dx - dy));
			}
			else {
				D = D + 2 * dx;
			}
		}

	}
	}

void DrawlineH(int x1, int y1, int x2, int y2, char ch) {

}

void Canvas::Print() {
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			printf("%c", this->canvas[i][j]);
		}
		printf("\n");
	}
}
void Canvas::Clear() {
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			this->canvas[i][j] = ' ';
		}
	}
}
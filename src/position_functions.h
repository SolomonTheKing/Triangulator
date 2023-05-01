#include <math.h>


// convert to real based numerals
int based_pixel_grid_converter(int ypos) {return GetScreenHeight() - ypos;}

// half of an integer
int get_middle(int w_or_h) {
    return w_or_h / 2;
}

int get_height_middle(int mb = 0) {
    return GetScreenHeight() / 2.0f - mb;
}

int get_width_middle() {
    return GetScreenWidth() / 2.0f;
}

void DrawTriangleR(float ts_x, float ts_y, float tm_x, float tm_y, float te_x, float te_y) {
    DrawLine(ts_x, ts_y, tm_x, tm_y, BLACK);
    DrawLine(tm_x, tm_y, te_x, te_y, BLACK);
    DrawLine(te_x, te_y, ts_x, ts_y, BLACK);
}

float GetLineDistanceF(float x1, float y1, float x2, float y2) {
    float p1 = x2 - x1;
          p1 = p1 * p1;
    float p2 = y2 - y1;
          p2 = p2 * p2;
          p1 = p1 + p2;
      return (float)sqrt(p1);
}
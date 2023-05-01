/*******************************************************************************************
*
*   if you copyrigh this you a bitch FEFWEF
*
********************************************************************************************/
  

#include <cstdlib>
#include <string>
#include "raylib.h"
#include "position_functions.h"

struct {
    float s_x; 
    float s_y;
    float m_x;
    float m_y;
    float e_x;
    float e_y;
} Triangle;
    
struct {
    int indent_size;
    int pre_indent_size;
} line_desc;


int main(int argc, char *argv[]) {
    
    const int screenWidth = 720;
    const int screenHeight = 640;
    //Vector2 MousePos = {0, 0}

    Triangle.s_x = 10;
    Triangle.s_y = 10;
    Triangle.m_x = 10;
    Triangle.m_y = 30;
    Triangle.e_x = 30;
    Triangle.e_y = 30;
    
    line_desc.indent_size = 12;
    line_desc.pre_indent_size = 5;

    InitWindow(screenWidth, screenHeight, "triangulator");
    SetWindowState(FLAG_VSYNC_HINT);
    SetWindowState(FLAG_WINDOW_UNDECORATED);
    
    Font font = LoadFont("resources/romulus.png");


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        BeginDrawing();
        
        // input
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Triangle.s_x = GetMousePosition().x;
            Triangle.s_y = GetMousePosition().y;
        } else if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)) {
            Triangle.m_x = GetMousePosition().x;
            Triangle.m_y = GetMousePosition().y;
        } else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
            Triangle.e_x = GetMousePosition().x;
            Triangle.e_y = GetMousePosition().y;
        }
        
        // draw length
        // ----------------------------
        // line 1
        
        // draw borders
        if (Triangle.e_x > Triangle.s_x) { // draw left of line
            DrawLine(Triangle.s_x - 1 - line_desc.pre_indent_size, Triangle.s_y, Triangle.s_x - 1 - line_desc.indent_size, Triangle.s_y, RED);
            DrawLine(Triangle.m_x - 1 - line_desc.pre_indent_size, Triangle.m_y, Triangle.m_x - 1 - line_desc.indent_size, Triangle.m_y, RED);
            DrawLine(Triangle.s_x - 1 - line_desc.indent_size, Triangle.s_y, Triangle.m_x - line_desc.indent_size, Triangle.m_y, RED);
            
            
            // draw text
            int the_line_distance = GetLineDistanceF(Triangle.s_x, Triangle.s_y, Triangle.m_x, Triangle.m_y);
            
            // get middle x
            float middle_of_line_x = ((Triangle.s_x + Triangle.m_x)/2);
                  middle_of_line_x = middle_of_line_x - 1 - line_desc.indent_size - 50; // format it
            
            // get middle y
            float middle_of_line_y = ((Triangle.s_y + Triangle.m_y)/2);
                  middle_of_line_y = middle_of_line_y - 1 - line_desc.indent_size; // format it
            
            DrawText(TextFormat("%04i", the_line_distance), middle_of_line_x, middle_of_line_y, 20, RED);
            
        } else { // draw right of line
            DrawLine(Triangle.s_x + 1 + line_desc.pre_indent_size, Triangle.s_y, Triangle.s_x + 1 + line_desc.indent_size, Triangle.s_y, RED);
            DrawLine(Triangle.m_x + 1 + line_desc.pre_indent_size, Triangle.m_y, Triangle.m_x + 1 + line_desc.indent_size, Triangle.m_y, RED);
            DrawLine(Triangle.s_x + 1 + line_desc.indent_size, Triangle.s_y, Triangle.m_x + line_desc.indent_size, Triangle.m_y, RED);
            
            
            // draw text
            int the_line_distance = GetLineDistanceF(Triangle.s_x, Triangle.s_y, Triangle.m_x, Triangle.m_y);
            
            // get middle x
            float middle_of_line_x = ((Triangle.s_x + Triangle.m_x)/2);
                  middle_of_line_x = middle_of_line_x + 1 + line_desc.indent_size + 20; // format it
            
            // get middle y
            float middle_of_line_y = ((Triangle.s_y + Triangle.m_y)/2);
                  middle_of_line_y = middle_of_line_y + 1 + line_desc.indent_size; // format it
            
            DrawText(TextFormat("%04i", the_line_distance), middle_of_line_x, middle_of_line_y, 20, RED);
        }
        
        // line 2
        if (Triangle.e_x < Triangle.s_x || Triangle.m_y > Triangle.e_y) { // draw left of line
            DrawLine(Triangle.m_x - 1 - line_desc.pre_indent_size, Triangle.m_y, Triangle.m_x - 1 - line_desc.indent_size, Triangle.m_y, GREEN);
            DrawLine(Triangle.e_x - 1 - line_desc.pre_indent_size, Triangle.e_y, Triangle.e_x - 1 - line_desc.indent_size, Triangle.e_y, GREEN);
            DrawLine(Triangle.m_x - 1 - line_desc.indent_size, Triangle.m_y, Triangle.e_x - line_desc.indent_size, Triangle.e_y, GREEN);
            
            
            // draw text
            int the_line_distance = GetLineDistanceF(Triangle.m_x, Triangle.m_y, Triangle.s_x, Triangle.s_y);
            
            // get middle x
            float middle_of_line_x = ((Triangle.m_x + Triangle.e_x)/3);
                  middle_of_line_x = middle_of_line_x - 1 - line_desc.indent_size - 50; // format it
            
            // get middle y
            float middle_of_line_y = ((Triangle.m_y + Triangle.e_y)/2);
                  middle_of_line_y = middle_of_line_y - 1 - line_desc.indent_size; // format it
            
            DrawText(TextFormat("%04i", the_line_distance), middle_of_line_x, middle_of_line_y, 20, GREEN);
            
        } else { // draw right of line
            DrawLine(Triangle.m_x + 1 + line_desc.pre_indent_size, Triangle.m_y, Triangle.m_x + 1 + line_desc.indent_size, Triangle.m_y, GREEN);
            DrawLine(Triangle.e_x + 1 + line_desc.pre_indent_size, Triangle.e_y, Triangle.e_x + 1 + line_desc.indent_size, Triangle.e_y, GREEN);
            DrawLine(Triangle.m_x + 1 + line_desc.indent_size, Triangle.m_y, Triangle.e_x + line_desc.indent_size, Triangle.e_y, GREEN);
            
            
            // draw text
            int the_line_distance = GetLineDistanceF(Triangle.m_x, Triangle.m_y, Triangle.s_x, Triangle.s_y);
            
            // get middle x
            float middle_of_line_x = ((Triangle.m_x + Triangle.e_x)/3);
                  middle_of_line_x = middle_of_line_x + 1 + line_desc.indent_size + 50; // format it
            
            // get middle y
            float middle_of_line_y = ((Triangle.m_y + Triangle.e_y)/2);
                  middle_of_line_y = middle_of_line_y + 1 + line_desc.indent_size; // format it
            
            DrawText(TextFormat("%04i", the_line_distance), middle_of_line_x, middle_of_line_y, 20, GREEN);
        }
        
        // line 3
        if (Triangle.s_x > Triangle.m_x) { // draw left of line
            DrawLine(Triangle.e_x - 1 - line_desc.pre_indent_size, Triangle.e_y, Triangle.e_x - 1 - line_desc.indent_size, Triangle.e_y, BLUE);
            DrawLine(Triangle.s_x - 1 - line_desc.pre_indent_size, Triangle.s_y, Triangle.s_x - 1 - line_desc.indent_size, Triangle.s_y, BLUE);
            DrawLine(Triangle.e_x - 1 - line_desc.indent_size, Triangle.e_y, Triangle.s_x - line_desc.indent_size, Triangle.s_y, BLUE);
            
            
            // draw text
            int the_line_distance = GetLineDistanceF(Triangle.e_x, Triangle.e_y, Triangle.m_x, Triangle.m_y);
            
            // get middle x
            float middle_of_line_x = ((Triangle.e_x + Triangle.s_x)/2.666);
                  middle_of_line_x = middle_of_line_x - 1 - line_desc.indent_size - 50; // format it
            
            // get middle y
            float middle_of_line_y = ((Triangle.e_y + Triangle.s_y)/2);
                  middle_of_line_y = middle_of_line_y - 1 - line_desc.indent_size; // format it
            
            DrawText(TextFormat("%04i", the_line_distance), middle_of_line_x, middle_of_line_y, 20, BLUE);
            
        } else { // draw right of line
            DrawLine(Triangle.e_x + 1 + line_desc.pre_indent_size, Triangle.e_y, Triangle.e_x + 1 + line_desc.indent_size, Triangle.e_y, BLUE);
            DrawLine(Triangle.s_x + 1 + line_desc.pre_indent_size, Triangle.s_y, Triangle.s_x + 1 + line_desc.indent_size, Triangle.s_y, BLUE);
            DrawLine(Triangle.e_x + 1 + line_desc.indent_size, Triangle.e_y, Triangle.s_x + line_desc.indent_size, Triangle.s_y, BLUE);
            
            
            // draw text
            int the_line_distance = GetLineDistanceF(Triangle.e_x, Triangle.e_y, Triangle.m_x, Triangle.m_y);
            
            // get middle x
            float middle_of_line_x = ((Triangle.e_x + Triangle.s_x)/2.666);
                  middle_of_line_x = middle_of_line_x + 1 + line_desc.indent_size + 50; // format it
            
            // get middle y
            float middle_of_line_y = ((Triangle.e_y + Triangle.s_y)/2);
                  middle_of_line_y = middle_of_line_y + 1 + line_desc.indent_size; // format it
            
            DrawText(TextFormat("%04i", the_line_distance), middle_of_line_x, middle_of_line_y, 20, BLUE);
        }
        
        DrawTriangleR(Triangle.s_x, Triangle.s_y, Triangle.m_x, Triangle.m_y, Triangle.e_x, Triangle.e_y);
            

		ClearBackground(WHITE);
            

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

#include <components.h>

void draw_loading_bar(int x, int y, int width, int height, float progress, Color borderColor, Color color) {
    DrawRectangle(x, y, width, height, borderColor);
    DrawRectangle(x+4, y+4, (width-4)*progress, height-4, color);
}

void render_loading_screen(float progress) {
    int text_width = MeasureText(loading_text, 20);
    const char* loading_text = TextFormat("LOADING %.02f%%", progress);
    DrawText(loading_text, screenWidth/2 - MeasureText/2, screenHeight/2 - 40, 20, GRAY);
    MemFree(loading_text);
}

/// Checks if the mouse clicked inside the specified bounds
///
/// @param bounds hitbox
/// @param button the mouse button
bool check_rectangle_clicked(Rectangle bounds, int button) {
    Vector2 mouse_pos = GetMousePosition();
    return IsMouseButtonReleased(button) && CheckCollisionPointRec(mouse_pos, bounds);
}
bool draw_button(Rectangle bounds, const char* text, int fontSize, Color bg_color, Color text_color) {
    DrawRectangleRec(startButton, bg_color);
    DrawRectangleLinesEx(startButton, 2, text_color);
    DrawText(text, bounds.x + bounds.width / 2 - MeasureText(text, fontSize) / 2, fontSize, text_color);
    return check_rectangle_clicked(bounds, MOUSE_LEFT_BUTTON);
}
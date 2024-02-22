#include <stdbool.h>
#include <raylib.h>

/// Renders loading screen with the specified progress
/// 
/// @param progress Percentage from 0.0..=1.0
void render_loading_screen(float progress);

bool draw_button(Rectangle bounds, const char* text, int fontSize, Color bg_color, Color text_color);
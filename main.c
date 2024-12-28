#include "minilibx-linux/mlx.h"
#include <math.h>

// İki nokta arasında bir çizgi çizen fonksiyon
void draw_line(void *mlx, void *window, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_pixel_put(mlx, window, x0, y0, color); // Pikseli çiz

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

int main()
{
    void *mlx;
    void *window;

    // MiniLibX başlatma
    mlx = mlx_init();
    window = mlx_new_window(mlx, 1920, 1080, "MiniLibX");

    // Pencerenin merkezi
    int center_x = 960;
    int center_y = 540;

    // Üçgenin köşe koordinatları (tam ortalanmış)
    int x0 = center_x;
    int y0 = center_y - 200; // Üst nokta (yukarı)
    int x1 = center_x - 150;
    int y1 = center_y + 100; // Sol alt köşe
    int x2 = center_x + 150;
    int y2 = center_y + 100; // Sağ alt köşe

    // Üçgenin kenarlarını çiz
    draw_line(mlx, window, x0, y0, x1, y1, 0xFF0000); // Kırmızı çizgi
    draw_line(mlx, window, x1, y1, x2, y2, 0x00FF00); // Yeşil çizgi
    draw_line(mlx, window, x2, y2, x0, y0, 0x0000FF); // Mavi çizgi

    // Pencereyi açık tut
    mlx_loop(mlx);

    return 0;
}
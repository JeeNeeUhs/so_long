#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

// Kare çizme fonksiyonu
// void draw_square_grid(void *mlx, void *window, int x_count, int y_count, int square_size, int color)
// {
//     for (int i = 0; i <= y_count; i++) // Yatay çizgiler
//     {
//         for (int j = 0; j <= x_count; j++) // Dikey çizgiler
//         {
//             // Her bir karenin yatay çizgileri
//             for (int k = 0; k < square_size; k++)
//                 mlx_pixel_put(mlx, window, j * square_size + k, i * square_size, color);
            
//             // Her bir karenin dikey çizgileri
//             for (int k = 0; k < square_size; k++)
//                 mlx_pixel_put(mlx, window, j * square_size, i * square_size + k, color);
//         }
//     }
// }

// int main()
// {
//     int x, y, square_size;

//     // Kullanıcıdan girdileri alma
//     printf("X (kare sayısı yatayda): ");
//     scanf("%d", &x);
//     printf("Y (kare sayısı dikeyde): ");
//     scanf("%d", &y);
//     printf("Kare kenar uzunluğu (piksel): ");
//     scanf("%d", &square_size);

//     // Pencere boyutlarını hesaplama
//     int window_width = x * square_size;
//     int window_height = y * square_size;

//     // MiniLibX başlatma
//     void *mlx = mlx_init();
//     if (!mlx)
//     {
//         printf("MiniLibX başlatılamadı!\n");
//         return 1;
//     }

//     void *window = mlx_new_window(mlx, window_width, window_height, "Kare Grid");
//     if (!window)
//     {
//         printf("Pencere oluşturulamadı!\n");
//         return 1;
//     }

//     // Kare gridini çiz
//     draw_square_grid(mlx, window, x, y, square_size, 0xFFFFFF); // Beyaz renk

//     // Pencereyi açık tut
//     mlx_loop(mlx);

//     return 0;
// }


// Kare gridindeki her karenin sol üst köşesine piksel koyan fonksiyon
void draw_grid_pixels(void *mlx, void *window, int x_count, int y_count, int square_size, int color)
{
    for (int i = 0; i < y_count; i++) // Dikey kare sayısı
    {
        for (int j = 0; j < x_count; j++) // Yatay kare sayısı
        {
            int x = j * square_size; // Karenin sol üst köşesinin X koordinatı
            int y = i * square_size; // Karenin sol üst köşesinin Y koordinatı
            mlx_pixel_put(mlx, window, x, y, color); // Pikseli beyaz koy
        }
    }
}

int main()
{
    int x, y, square_size;

    // Kullanıcıdan girdileri alma
    printf("X (kare sayısı yatayda): ");
    scanf("%d", &x);
    printf("Y (kare sayısı dikeyde): ");
    scanf("%d", &y);
    printf("Kare kenar uzunluğu (piksel): ");
    scanf("%d", &square_size);

    // Pencere boyutlarını hesaplama
    int window_width = x * square_size;
    int window_height = y * square_size;

    // MiniLibX başlatma
    void *mlx = mlx_init();
    if (!mlx)
    {
        printf("MiniLibX başlatılamadı!\n");
        return 1;
    }

    void *window = mlx_new_window(mlx, window_width, window_height, "Kare Grid - Sol Üst Piksel");
    if (!window)
    {
        printf("Pencere oluşturulamadı!\n");
        return 1;
    }

    // Kare gridini çiz (her karenin sol üst köşesine beyaz piksel)
    draw_grid_pixels(mlx, window, x, y, square_size, 0xFFFFFF); // Beyaz renk

    // Pencereyi açık tut
    mlx_loop(mlx);

    return 0;
}

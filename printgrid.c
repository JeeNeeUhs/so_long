#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

// Resmi her karenin içine yerleştiren fonksiyon
void draw_grid_with_image(void *mlx, void *window, void *image, int x_count, int y_count, int square_size)
{
    for (int i = 0; i < y_count; i++) // Dikey kare sayısı
    {
        for (int j = 0; j < x_count; j++) // Yatay kare sayısı
        {
            int x = j * square_size; // Karenin sol üst köşesinin X koordinatı
            int y = i * square_size; // Karenin sol üst köşesinin Y koordinatı
            mlx_put_image_to_window(mlx, window, image, x, y); // Resmi karenin içine yerleştir
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

    // if (square_size != 100)
    // {
    //     printf("Şu an sadece 100x100 boyutundaki karelerle çalışabiliyoruz. Lütfen kare kenarını 100 girin.\n");
    //     return 1;
    // }

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

    void *window = mlx_new_window(mlx, window_width, window_height, "Kare Grid - Resimli");
    if (!window)
    {
        printf("Pencere oluşturulamadı!\n");
        return 1;
    }

    // Resmi yükleme
    int img_width, img_height;
    void *image = mlx_xpm_file_to_image(mlx, "100new.xpm", &img_width, &img_height);
    if (!image)
    {
        printf("Resim yüklenemedi! Lütfen 'image.xpm' dosyasını kontrol edin.\n");
        return 1;
    }

    if (img_width != 100 || img_height != 100)
    {
        printf("Resim boyutu 100x100 değil! Lütfen 100x100 boyutunda bir .xpm dosyası kullanın.\n");
        return 1;
    }

    // Kare gridini çiz (her karenin içine resmi yerleştir)
    draw_grid_with_image(mlx, window, image, x, y, square_size);

    // Pencereyi açık tut
    mlx_loop(mlx);

    return 0;
}

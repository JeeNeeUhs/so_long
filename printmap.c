#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// Tek bir karenin içine resmi yerleştiren fonksiyon
void draw_image_to_cell(void *mlx, void *window, void *image, int i, int j, int square_size)
{
    int x = j * square_size; // Karenin X koordinatı
    int y = i * square_size; // Karenin Y koordinatı
    mlx_put_image_to_window(mlx, window, image, x, y); // Resmi belirtilen kareye yerleştir
}

void draw_transparent_image(void *mlx, void *win, void *img, int x, int y, int square_size)
{
    char *data;
    int bpp, size_line, endian;
    int i, j;
    int *pixel;

    x *= square_size;
    y *= square_size;

    data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
    for (j = 0; j < square_size; j++)
    {
        for (i = 0; i < square_size; i++)
        {
            pixel = (int *)(data + (j * size_line + i * (bpp / 8)));
            if ((*pixel & 0xFF000000) != 0xFF000000) // Siyah dışındaki piksel (şeffaflık varsayımı)
            {
                mlx_pixel_put(mlx, win, x + i, y + j - 20, *pixel);
            }
        }
    }
}

int main()
{
    int square_size = 100; // Her karenin boyutu (piksel)
    int x = 0, y = 0;

    // Harita dosyasını açma
    int file = open("map.ber", O_RDONLY);
    if (file < 0)
    {
        printf("Harita dosyası açılamadı! Lütfen 'map.ber' dosyasını kontrol edin.\n");
        return 1;
    }

    // Haritanın boyutlarını belirleme
    char *line;
    while ((line = get_next_line(file)) != NULL)
    {
        if (y == 0)
            x = strlen(line) - 1; // Satır uzunluğunu belirleme (newline karakteri hariç)
        y++;
        free(line);
    }
    close(file);

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

    void *window = mlx_new_window(mlx, window_width, window_height, "Kare Grid - Harita");
    if (!window)
    {
        printf("Pencere oluşturulamadı!\n");
        return 1;
    }

    // Resimleri yükleme
    int img_width, img_height;
    void *tile = mlx_xpm_file_to_image(mlx, "greensea.xpm", &img_width, &img_height);
    if (!tile)
    {
        printf("Tile resmi yüklenemedi! Lütfen 'tile.xpm' dosyasını kontrol edin.\n");
        return 1;
    }

    void *sea = mlx_xpm_file_to_image(mlx, "sea.xpm", &img_width, &img_height);
    if (!sea)
    {
        printf("Sea resmi yüklenemedi! Lütfen 'sea.xpm' dosyasını kontrol edin.\n");
        return 1;
    }

    void *character = mlx_xpm_file_to_image(mlx, "character.xpm", &img_width, &img_height);
    if (!character)
    {
        printf("Character resmi yüklenemedi! Lütfen 'character.xpm' dosyasını kontrol edin.\n");
        return 1;
    }

    // Haritayı çizme
    file = open("map.ber", O_RDONLY);
    if (file < 0)
    {
        printf("Harita dosyası açılamadı! Lütfen 'map.ber' dosyasını kontrol edin.\n");
        return 1;
    }

    for (int i = 0; i < y; i++)
    {
        line = get_next_line(file);
        if (!line)
            break;

        for (int j = 0; j < x; j++)
        {
            if (line[j] == '1') // Deniz
                draw_image_to_cell(mlx, window, sea, i, j, square_size);
            else if (line[j] == '0') // Zemin
                draw_image_to_cell(mlx, window, tile, i, j, square_size);
            else if (line[j] == 'P') // Karakter
            {
                draw_image_to_cell(mlx, window, tile, i, j, square_size);
                draw_transparent_image(mlx, window, character, i, j, square_size);
            }
            else if (line[j] == 'E') // Çıkış
            {
                draw_image_to_cell(mlx, window, tile, i, j, square_size);
            }
            else if (line[j] == 'C') // Kasa
            {
                draw_image_to_cell(mlx, window, tile, i, j, square_size);
            }
        }
        free(line);
    }
    close(file);

    // draw_transparent_image(mlx, window, character, 3, 3, square_size);

    // Pencereyi açık tut
    mlx_loop(mlx);



    return 0;
}
// gcc printmap.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c -lmlx -L./minilibx-linux -L./get_next_line -lXext -lX11 -lm -lz && ./a.out
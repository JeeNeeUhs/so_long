#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

void draw_transparent_image(void *mlx, void *win, void *img, int img_width, int img_height, int x, int y)
{
    char *data;
    int bpp, size_line, endian;
    int i, j;
    int *pixel;

    data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
    for (j = 0; j < img_height; j++)
    {
        for (i = 0; i < img_width; i++)
        {
            pixel = (int *)(data + (j * size_line + i * (bpp / 8)));
            if ((*pixel & 0xFF000000) != 0xFF000000) // Siyah dışındaki piksel (şeffaflık varsayımı)
            {
                mlx_pixel_put(mlx, win, x + i, y + j, *pixel);
            }
        }
    }
}


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

// Karakteri belirli bir koordinata yerleştiren fonksiyon
void place_character_on_grid(void *mlx, void *window, void *character, int x_pos, int y_pos, int square_size)
{
	int x = x_pos * square_size; // X koordinatını hesapla
	int y = y_pos * square_size; // Y koordinatını hesapla
	// mlx_put_image_to_window(mlx, window, character, x, y); // Karakteri belirtilen koordinata yerleştir
	draw_transparent_image(mlx, window, character, square_size, square_size, x, y - 25);
}

int main()
{
	int x, y, square_size;

	// Kullanıcıdan X girdisini alma ve doğrulama (X 10 ve üzeri olmalı)
	printf("X (kare sayısı yatayda, 10 ve üzeri olmalı): ");
	scanf("%d", &x);
	if (x < 10)  // Eğer X 10'dan küçükse hata mesajı ver
	{
		printf("Hata! X değeri 10 ve üzeri olmalı.\n");
		return 1; // Hatalı giriş, programı sonlandır
	}

	// Kullanıcıdan Y girdisini alma ve doğrulama (Y 5 ve üzeri olmalı)
	printf("Y (kare sayısı dikeyde, 5 ve üzeri olmalı): ");
	scanf("%d", &y);
	if (y < 5)  // Eğer Y 5'ten küçükse hata mesajı ver
	{
		printf("Hata! Y değeri 5 ve üzeri olmalı.\n");
		return 1; // Hatalı giriş, programı sonlandır
	}

	// Kullanıcıdan kare kenar uzunluğunu alma ve doğrulama (100 ve üzeri olmalı)
	printf("Kare kenar uzunluğu (piksel, 100 ve üzeri olmalı): ");
	scanf("%d", &square_size);
	if (square_size < 100)  // Eğer kare kenarı 100'den küçükse hata mesajı ver
	{
		printf("Hata! Kare kenar uzunluğu 100 ve üzeri olmalı.\n");
		return 1; // Hatalı giriş, programı sonlandır
	}

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

	// Arka plan resmini yükleme
	int img_width, img_height;
	void *background = mlx_xpm_file_to_image(mlx, "greensea.xpm", &img_width, &img_height);
	if (!background)
	{
		printf("Arka plan resmi yüklenemedi! Lütfen '100new.xpm' dosyasını kontrol edin.\n");
		return 1;
	}

	// Karakter resmini yükleme
	void *character = mlx_xpm_file_to_image(mlx, "character.xpm", &img_width, &img_height);
	if (!character)
	{
		printf("Karakter resmi yüklenemedi! Lütfen 'character.xpm' dosyasını kontrol edin.\n");
		return 1;
	}

	void *sea = mlx_xpm_file_to_image(mlx, "sea.xpm", &img_width, &img_height);
	if (!sea)
	{
		printf("Karakter resmi yüklenemedi! Lütfen 'sea.xpm' dosyasını kontrol edin.\n");
		return 1;
	}

	// Arka planı pencereye yerleştir
	draw_grid_with_image(mlx, window, background, x, y, square_size);




	place_character_on_grid(mlx, window, character, 4, 4, square_size);

	// 4. Yatay ve 3. Dikey karede karakteri yerleştir
	// place_character_on_grid(mlx, window, character, 4, 4, square_size);

	// Pencereyi açık tut
	mlx_loop(mlx);

	return 0;
}


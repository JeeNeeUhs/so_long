#include "minilibx-linux/mlx.h"
#include <stdio.h>

#define ESC 65307
#define W_KEY 119

// Tuş basımı olayını işleyen fonksiyon
int key_hook(int keycode, void *param)
{
	if (keycode == W_KEY) // 'W' tuşuna basıldıysa
	{
		printf("1\n");
	}
	else if (keycode == ESC) // ESC tuşuna basıldıysa
	{
		printf("Çıkılıyor...\n");
		exit(0); // Çıkış yap
	}
	return (0);
}

int main()
{
	void *mlx;
	void *window;

	// MiniLibX başlatma
	mlx = mlx_init();
	if (!mlx)
	{
		printf("MiniLibX başlatılamadı!\n");
		return (1);
	}

	window = mlx_new_window(mlx, 800, 600, "Klavye Tuşlarını Yakalama");
	if (!window)
	{
		printf("Pencere oluşturulamadı!\n");
		return (1);
	}

	// Klavye tuşlarını yakalamak için hook ekliyoruz
	mlx_key_hook(window, key_hook, NULL);

	// Pencereyi açık tut
	mlx_loop(mlx);

	return (0);
}

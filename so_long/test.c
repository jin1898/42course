#include "./mlx/mlx.h"

int main()
{
    void* mlx = mlx_init();

    void* win = mlx_new_window(mlx, 128, 128, "test");

    (void)win;
    mlx_loop(mlx);
    return 0;
}
### Alteracao em `del_mlx`

```c
void	del_mlx(t_mlx *mlx)
```

Antes, a funcao assumia que contexto, janela, imagem e screen sempre existiam.
Uma falha durante `configure_game` poderia causar acesso a um ponteiro nulo.

Agora o fluxo e defensivo.

Primeira protecao:

```c
if (!mlx)
	return ;
```

Destruicao da imagem:

```c
if (mlx->mlx && mlx->screen && mlx->screen->img)
	mlx_destroy_image(mlx->mlx, mlx->screen->img);
```

A imagem so pode ser destruida quando:

- existe um contexto MiniLibX
- existe a estrutura `screen`
- existe uma imagem

Destruicao da janela:

```c
if (mlx->mlx && mlx->window)
	mlx_destroy_window(mlx->mlx, mlx->window);
```

A janela so e destruida quando contexto e janela existem.

Destruicao do display:

```c
if (mlx->mlx)
{
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}
```

O display e destruido antes de liberar o ponteiro retornado por `mlx_init`.

Por ultimo:

```c
free(mlx->screen);
free(mlx);
```

As estruturas C sao liberadas mesmo quando os recursos nativos nao chegaram a
ser criados.
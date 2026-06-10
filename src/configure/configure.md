Esse arquivo foi reorganizado para verificar cada etapa da MiniLibX e permitir
uma limpeza segura em caso de falha parcial.

### `alloc_mlx_data`

```c
static int	alloc_mlx_data(t_game *game)
```

Responsabilidade: alocar somente as estruturas C usadas para guardar os
recursos da MiniLibX.

Fluxo:

1. Aloca `t_mlx` com `ft_calloc`.
2. Aloca `t_img` com `ft_calloc`.
3. Verifica se alguma alocacao falhou.
4. Em caso de falha, exibe uma mensagem.
5. Libera as estruturas que eventualmente foram alocadas.
6. Retorna `1`.
7. Em caso de sucesso, associa `screen` a `mlx->screen`.
8. Associa `mlx` a `game->mlx`.
9. Retorna `0`.

As associacoes com `game` sao feitas antes de criar os recursos nativos. Dessa
forma, `del_game` consegue acessar e liberar uma inicializacao parcial.

### `create_mlx_window`

```c
static int	create_mlx_window(t_mlx *mlx)
```

Responsabilidade: criar o contexto da MiniLibX e a janela.

Primeiro executa:

```c
mlx->mlx = mlx_init();
```

Se `mlx_init` retornar `NULL`, a funcao:

- nao tenta criar a janela
- exibe `Error: mlx_init failed`
- retorna `1`

Depois executa:

```c
mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Cub3d");
```

Se a janela falhar:

- o contexto `mlx->mlx` continua registrado
- a funcao exibe `Error: window creation failed`
- retorna `1`
- `del_mlx` podera destruir o contexto existente

Antes dessa alteracao, `mlx_new_window` era chamado mesmo sem confirmar o
retorno de `mlx_init`.

### `create_screen_image`

```c
static int	create_screen_image(t_mlx *mlx)
```

Responsabilidade: criar a imagem usada para desenhar cada frame.

Primeiro recupera:

```c
screen = mlx->screen;
```

Depois cria a imagem:

```c
screen->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
```

Se a criacao falhar, exibe erro e retorna `1`.

Quando a imagem existe, busca o buffer:

```c
screen->addr = mlx_get_data_addr(screen->img, &screen->bpp,
		&screen->line_length, &screen->endian);
```

A MiniLibX preenche:

- `addr`
- `bpp`
- `line_length`
- `endian`

Se `addr` for `NULL`, a funcao exibe erro e retorna `1`. A imagem ja criada
continua registrada e sera destruida por `del_mlx`.

### `config_mlx`

```c
static int	config_mlx(t_game *game)
```

Coordena as tres etapas na ordem de dependencia:

1. `alloc_mlx_data`
2. `create_mlx_window`
3. `create_screen_image`

Cada chamada e verificada antes de continuar. A funcao retorna no primeiro
erro, evitando usar um recurso que nao foi criado.

### Alteracao em `configure_game`

```c
int	configure_game(t_game *game)
```

A ordem continua sendo:

1. configurar a MiniLibX
2. configurar o player

Se qualquer uma falhar, retorna `1`. O `main` passou a tratar esse retorno como
erro.
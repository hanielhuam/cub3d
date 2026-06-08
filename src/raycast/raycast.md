# Step 02 - Funcoes do raycasting


## `init_ray.c`

### `init_step_x`

```c
static void	init_step_x(t_ray *ray, t_player *player)
```

Calcula a direcao do passo no eixo X e a primeira distancia lateral em X.

Quando `ray->dir_x < 0`, o raio esta olhando para a esquerda no mapa:

- `step_x` recebe `-1`
- `side_dist_x` mede a distancia entre a posicao do player e a borda esquerda
  da celula atual

Quando `ray->dir_x >= 0`, o raio esta olhando para a direita:

- `step_x` recebe `1`
- `side_dist_x` mede a distancia ate a borda direita da celula atual

Essa funcao prepara o DDA para saber em qual direcao andar no grid.

### `init_step_y`

```c
static void	init_step_y(t_ray *ray, t_player *player)
```

Faz a mesma coisa que `init_step_x`, mas no eixo Y.

Quando `ray->dir_y < 0`, o raio sobe no mapa:

- `step_y` recebe `-1`
- `side_dist_y` mede a distancia ate a borda superior da celula

Quando `ray->dir_y >= 0`, o raio desce no mapa:

- `step_y` recebe `1`
- `side_dist_y` mede a distancia ate a borda inferior da celula

### `init_ray_steps`

```c
static void	init_ray_steps(t_ray *ray, t_player *player)
```

Funcao auxiliar que chama:

- `init_step_x`
- `init_step_y`

Ela deixa `init_ray` menor e separa a logica de preparacao do DDA.

### `init_ray`

```c
void	init_ray(t_ray *ray, t_player *player, int x)
```

Inicializa um raio para uma coluna especifica da tela.

Fluxo:

1. Calcula `camera_x`, que transforma a coluna da tela em uma posicao no plano
   da camera.
2. Calcula `dir_x` e `dir_y`, que sao a direcao do raio.
3. Define `map_x` e `map_y` como a celula atual do player.
4. Calcula `delta_dist_x`, distancia necessaria para cruzar uma celula em X.
5. Calcula `delta_dist_y`, distancia necessaria para cruzar uma celula em Y.
6. Inicializa `side` com `0`.
7. Chama `init_ray_steps` para preparar `step_x`, `step_y`, `side_dist_x` e
   `side_dist_y`.

Essa funcao representa a primeira parte do algoritmo do Lode para cada coluna
da tela.

## `dda.c`

### `is_wall`

```c
static int	is_wall(char **board, int x, int y)
```

Verifica se uma celula bloqueia o raio.

Retorna verdadeiro quando:

- `y` e menor que zero
- `x` e menor que zero
- a linha `board[y]` nao existe
- `x` passa do tamanho da linha
- a celula e parede `1`
- a celula e espaco `' '`

Esse cuidado evita acesso fora do mapa, especialmente em mapas com linhas de
tamanhos diferentes.

### `run_dda`

```c
void	run_dda(t_ray *ray, char **board)
```

Executa o DDA ate o raio bater em uma parede.

Fluxo:

1. Enquanto a celula atual nao for parede, o raio continua andando.
2. Compara `side_dist_x` e `side_dist_y`.
3. Se `side_dist_x` for menor, avanca uma celula no eixo X.
4. Se `side_dist_y` for menor ou igual, avanca uma celula no eixo Y.
5. Guarda em `side` qual eixo foi usado no impacto.
6. Quando encontra parede, calcula `perp_dist`.

`perp_dist` e a distancia perpendicular da parede. Ela evita o efeito de olho de
peixe e sera usada para calcular a altura da coluna na tela.

## `render_raycast.c`

### `wall_color`

```c
static int	wall_color(t_ray *ray)
```

Escolhe uma cor temporaria para a parede.

Nesta etapa ainda nao ha textura, entao usamos cores diferentes para ajudar no
debug:

- impacto em Y subindo
- impacto em Y descendo
- impacto em X indo para esquerda
- impacto em X indo para direita

Isso ajuda a visualizar se o DDA esta identificando lados diferentes do mapa.

### `get_wall_line`

```c
static void	get_wall_line(t_ray *ray, int *start, int *end)
```

Transforma a distancia da parede em uma coluna vertical na tela.

Fluxo:

1. Protege contra distancia menor ou igual a zero.
2. Calcula `line_height` usando:

```c
TOP_SCREEN_HEIGHT / ray->perp_dist
```

3. Calcula o inicio da coluna:

```c
-line_height / 2 + TOP_SCREEN_HEIGHT / 2
```

4. Calcula o fim da coluna:

```c
line_height / 2 + TOP_SCREEN_HEIGHT / 2
```

5. Limita `start` e `end` para ficarem dentro da tela de cima.

Essa funcao e responsavel por fazer paredes proximas ficarem grandes e paredes
distantes ficarem pequenas.

### `draw_wall_column`

```c
static void	draw_wall_column(t_game *game, t_ray *ray, int x, int *line)
```

Desenha uma coluna vertical de parede em uma coluna `x` da tela.

Fluxo:

1. Escolhe a cor usando `wall_color`.
2. Comeca em `line[0]`.
3. Vai ate `line[1]`.
4. Pinta cada pixel da coluna usando `put_pixel`.

Essa funcao ainda desenha cor solida. Depois ela sera substituida ou expandida
para buscar pixels da textura.

### `render_raycast`

```c
void	render_raycast(t_game *game)
```

Funcao principal do raycasting sem textura.

Fluxo:

1. Comeca na coluna `x = 1`, para nao passar por cima da borda do wireframe.
2. Para cada coluna ate `WIDITH - 1`:
   - inicializa o raio com `init_ray`
   - executa o DDA com `run_dda`
   - calcula a coluna da parede com `get_wall_line`
   - desenha a coluna com `draw_wall_column`
3. Repete ate preencher toda a tela de cima.

Esse e o checkpoint onde o jogo ja deve parecer 3D, mesmo sem texturas.

## `render_frame.c`

### Alteracao em `render_frame`

```c
render_raycast(game);
```

Foi adicionada antes dos wireframes e do minimapa.

Ordem atual:

1. Limpa a tela.
2. Renderiza as paredes 3D sem textura.
3. Desenha os wireframes por cima.
4. Desenha o minimapa.
5. Envia a imagem para a janela.

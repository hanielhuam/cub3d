# Funcoes de render implementadas

## `render_utils.c`

### `put_pixel`

```c
void	put_pixel(t_img *img, int x, int y, int color)
```

Escreve um pixel dentro da imagem da MiniLibX.

Fluxo:

1. Recebe a imagem, a coordenada `x`, a coordenada `y` e a cor.
2. Verifica se o pixel esta dentro da janela.
3. Calcula o endereco exato do pixel no buffer da imagem.
4. Escreve a cor nesse endereco.

Ela e a funcao mais basica do render. Todas as outras funcoes de desenho usam
`put_pixel` por baixo.

### `clear_screen`

```c
void	clear_screen(t_img *img, int color)
```

Pinta a tela inteira com uma unica cor.

Fluxo:

1. Comeca em `y = 0`.
2. Para cada linha, percorre todos os pixels de `x = 0` ate `WIDITH`.
3. Chama `put_pixel` para pintar cada pixel.
4. Repete ate chegar em `HEIGHT`.

Nesta etapa ela limpa a tela antes de desenhar os wireframes e o minimapa.

### `draw_rect`

```c
void	draw_rect(t_img *img, int *pos, int *size, int color)
```

Desenha um retangulo preenchido.

Parametros:

- `pos[0]`: posicao inicial em `x`
- `pos[1]`: posicao inicial em `y`
- `size[0]`: largura
- `size[1]`: altura

Fluxo:

1. Percorre a altura do retangulo.
2. Para cada linha, percorre a largura.
3. Pinta cada pixel usando `put_pixel`.

No minimapa, cada tile do mapa e desenhado como um pequeno retangulo.

### `draw_wireframe`

```c
void	draw_wireframe(t_img *img, int *pos, int *size, int color)
```

Desenha somente a borda de um retangulo.

Fluxo:

1. Percorre a largura para pintar a borda superior.
2. Percorre a largura para pintar a borda inferior.
3. Percorre a altura para pintar a borda esquerda.
4. Percorre a altura para pintar a borda direita.

Nesta etapa usamos essa funcao para marcar visualmente:

- a tela de cima, reservada para o futuro 3D
- a tela de baixo, reservada para o minimapa

## `render_frame.c`

### `render_wireframes`

```c
static void	render_wireframes(t_game *game)
```

Desenha os dois wireframes principais da janela.

Fluxo:

1. Cria um retangulo começando em `(0, 0)`.
2. Define sua largura como `WIDITH`.
3. Define sua altura como `TOP_SCREEN_HEIGHT`.
4. Desenha a borda da tela de cima.
5. Move o segundo retangulo para começar em `TOP_SCREEN_HEIGHT`.
6. Define sua altura como `HEIGHT - TOP_SCREEN_HEIGHT`.
7. Desenha a borda da tela de baixo.

Ela e `static` porque so precisa ser usada dentro de `render_frame.c`.

### `render_frame`

```c
int	render_frame(t_game *game)
```

Renderiza um frame completo.

Fluxo:

1. Limpa a imagem com `clear_screen`.
2. Desenha os wireframes com `render_wireframes`.
3. Desenha o minimapa com `render_minimap`.
4. Envia a imagem final para a janela com `mlx_put_image_to_window`.
5. Retorna `0`, como esperado pelo hook da MiniLibX.

Essa funcao e chamada continuamente pelo `mlx_loop_hook`.

## `render_minimap.c`

### `map_width`

```c
static int	map_width(char **board)
```

Calcula a largura da maior linha do mapa.

Isso e necessario porque o mapa pode ter linhas de tamanhos diferentes.
Para centralizar o minimapa corretamente, usamos a maior linha como largura
total.

### `map_height`

```c
static int	map_height(char **board)
```

Conta quantas linhas existem no mapa.

Essa altura e usada para calcular o tamanho final do minimapa em pixels.

### `tile_color`

```c
static int	tile_color(char tile)
```

Escolhe a cor de cada celula do minimapa.

Regras atuais:

- `1`: parede, cinza escuro
- `0`: chao, verde claro
- `N`, `S`, `W`, `E`: player, vermelho
- qualquer outro caractere: fundo escuro

### `draw_map_tiles`

```c
static void	draw_map_tiles(t_game *game, int offset_x, int offset_y)
```

Desenha todos os tiles do mapa.

Fluxo:

1. Define o tamanho de cada tile como `MINIMAP_SCALE - 1`.
2. Percorre cada linha do mapa.
3. Percorre cada caractere da linha.
4. Calcula a posicao do tile usando `offset_x` e `offset_y`.
5. Desenha o tile com `draw_rect`.

O `-1` no tamanho cria uma pequena separacao visual entre os tiles.

### `render_minimap`

```c
void	render_minimap(t_game *game)
```

Centraliza e desenha o minimapa na tela de baixo.

## Resultado da etapa

Depois dessas alteracoes:

1. Calcula a largura do mapa em pixels.
2. Calcula a altura do mapa em pixels.
3. Calcula a altura disponivel na tela de baixo.
4. Calcula `offset_x` para centralizar horizontalmente.
5. Calcula `offset_y` para centralizar verticalmente na tela de baixo.
6. Chama `draw_map_tiles` usando esses offsets.

-----------------------------atualizacao 1.0

## `src/render/render_utils.c`

Esse arquivo recebeu duas renomeacoes e um novo helper.

### Alteracao em `put_pixel`

Limite horizontal antes:

```c
x >= WIDITH
```

Limite horizontal depois:

```c
x >= WIDTH
```

Calculo do endereco antes:

```c
y * img->line_lenght
```

Calculo do endereco depois:

```c
y * img->line_length
```

Formula completa:

```c
dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
```

Significado:

- `y * line_length`: avanca ate a linha correta.
- `x * (bpp / 8)`: avanca ate o pixel correto da linha.
- `dst`: endereco final do pixel.

### Alteracao em `clear_screen`

Antes:

```c
while (x < WIDITH)
```

Depois:

```c
while (x < WIDTH)
```

O comportamento continua sendo pintar todos os pixels da janela.

### `draw_vertical_line`

```c
void	draw_vertical_line(t_img *img, int x, int *limits, int color)
```

Parametros:

- `img`: imagem de destino.
- `x`: coluna que sera desenhada.
- `limits[0]`: inicio vertical.
- `limits[1]`: fim vertical.
- `color`: cor da linha.

Embora existam cinco valores logicos, inicio e fim foram agrupados em um vetor.
Assim a funcao possui quatro parametros e respeita a Norm.

Primeiro copia os limites:

```c
y = limits[0];
end = limits[1];
```

Depois limita o inicio:

```c
if (y < 0)
	y = 0;
```

Limita o fim:

```c
if (end >= HEIGHT)
	end = HEIGHT - 1;
```

Por fim desenha:

```c
while (y <= end)
	put_pixel(img, x, y++, color);
```

`put_pixel` ainda protege o valor de `x`. Portanto, uma coluna horizontalmente
invalida nao escreve fora da imagem.
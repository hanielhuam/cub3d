# Correcoes de leitura e validacao

Este arquivo explica somente as funcoes alteradas:

- ultima linha do arquivo sem `\n`
- arquivos com final de linha `\r\n`
- linha vazia dentro do mapa
- conteudo depois do mapa
- mapas abertos ou com linhas de tamanhos diferentes
- cores com espacos
- preparacao automatica da MiniLibX pelo `Makefile`

## `create_token_by_line.c`

### `remove_line_end`

```c
static void	remove_line_end(char *line)
```

Remove os caracteres usados para finalizar uma linha.

Fluxo:

1. Calcula o tamanho da string.
2. Verifica se o ultimo caractere e `\n`.
3. Remove o `\n` somente quando ele realmente existe.
4. Verifica novamente o final da string.
5. Remove `\r`, caso o arquivo use o formato de linha do Windows.

Antes dessa funcao, o codigo removia sempre o ultimo caractere da linha.
Quando a ultima linha do arquivo nao terminava com `\n`, um caractere valido
do mapa ou da configuracao era apagado.

Exemplo:

```text
11111
10001
11111
```

Se a ultima linha nao tivesse `\n`, ela poderia virar `1111`. Agora seu
conteudo e preservado.

### Alteracao em `create_token_by_line`

```c
t_token	*create_token_by_line(char *line)
```

Essa funcao continua criando um token para cada linha lida do arquivo.

O fluxo atual e:

1. Aloca a estrutura `t_token`.
2. Chama `remove_line_end`.
3. Duplica a linha ja normalizada.
4. Identifica o tipo da linha com `compare_token`.
5. Retorna o novo token.

A mudanca importante foi substituir a remocao direta do ultimo caractere por
uma chamada segura a `remove_line_end`.

## `validate_token_list.c`

### Alteracao em `validate_token_order`

```c
static int	validate_token_order(t_list *tokens)
```

Confirma que o mapa e o ultimo bloco util do arquivo `.cub`.

Fluxo:

1. Avanca pela lista ate encontrar o primeiro token `TK_MAP`.
2. Consome todas as linhas consecutivas do mapa.
3. Permite tokens `TK_NL` somente depois que o mapa terminou.
4. Rejeita qualquer outro token restante.

Uma linha vazia dentro do mapa interrompe a sequencia de tokens `TK_MAP`.
Se outra linha de mapa aparecer depois dela, ainda existira conteudo depois
dos `TK_NL`, e a validacao retornara erro.

Exemplo rejeitado:

```text
11111
10001

11111
```

Linhas vazias no final do arquivo continuam permitidas, pois nao dividem o
bloco do mapa.

## `color_validation.c`

### `skip_spaces`

```c
static void	skip_spaces(char *line, int *index)
```

Avanca o indice enquanto o caractere atual for um espaco reconhecido por
`ft_isspace`.

Ela e usada antes e depois de cada componente da cor. Isso permite formatos
como:

```text
F 220, 100, 0
C   10 , 20 , 30
```

### `read_component`

```c
static int	read_component(char *line, int *index)
```

Le um unico componente numerico da cor.

Fluxo:

1. Ignora espacos antes do numero.
2. Conta todos os digitos consecutivos.
3. Ignora espacos depois do numero.
4. Retorna verdadeiro somente se encontrou pelo menos um digito.

Essa verificacao impede componentes vazios, como:

```text
F 10,,30
```

A verificacao do intervalo entre `0` e `255` continua sendo feita durante a
extracao das cores.

### `valid_color_format`

```c
static int	valid_color_format(char *line)
```

Valida a estrutura completa de uma configuracao de cor.

Fluxo:

1. Ignora espacos no inicio da linha.
2. Confirma que o identificador e `F` ou `C`.
3. Le exatamente tres componentes numericos.
4. Exige uma virgula entre cada componente.
5. Confirma que nao existe conteudo extra no final.

Exemplos validos:

```text
F 220,100,0
C 225, 30, 0
   F   1 , 2 , 3
```

Exemplos invalidos:

```text
F 1,,2,3
F 1,2,
F 1,2,3x
```

### Alteracao em `color_validation`

```c
int	color_validation(char *line)
```

Essa e a funcao publica usada antes de construir a cor.

Ela chama `valid_color_format` e:

- retorna `0` quando o formato e valido
- exibe uma mensagem e retorna `1` quando o formato e invalido

## `extract_colors.c`

### `skip_color_id`

```c
static char	*skip_color_id(char *line)
```

Localiza o inicio dos valores numericos da cor.

Fluxo:

1. Ignora espacos antes do identificador.
2. Avanca sobre `F` ou `C`.
3. Ignora os espacos entre o identificador e o primeiro numero.
4. Retorna um ponteiro para o primeiro componente.

Essa funcao substitui o antigo `line += 2`, que dependia de o identificador
estar obrigatoriamente no primeiro caractere e possuir exatamente um espaco.

### Alteracao em `extract_colors`

```c
unsigned char	*extract_colors(char *line)
```

Extrai os tres componentes RGB depois que a linha foi validada.

Fluxo atual:

1. Valida o formato com `color_validation`.
2. Aloca um vetor para os tres componentes.
3. Chama `skip_color_id` para encontrar o primeiro numero.
4. Separa e converte os componentes.
5. Confirma que cada valor esta entre `0` e `255`.
6. Libera a memoria e retorna `NULL` em caso de erro.

## `board_validator.c`

### `check_player`

```c
static int	check_player(char **board)
```

Percorre o mapa inteiro e conta os caracteres `N`, `S`, `E` e `W`.

O mapa e aceito somente quando existe exatamente um jogador. A funcao retorna
erro quando o jogador esta ausente ou aparece mais de uma vez.

### `map_at`

```c
static char	map_at(char **board, int x, int y)
```

Le uma coordenada do mapa de forma segura.

Ela retorna um espaco quando:

- `x` ou `y` sao negativos
- a linha solicitada nao existe
- `x` ultrapassa o tamanho da linha

Isso permite validar mapas irregulares sem acessar memoria fora do vetor.
Para a validacao estrutural, um espaco representa uma area externa ao mapa.

### `has_open_neighbor`

```c
static int	has_open_neighbor(char **board, int x, int y)
```

Verifica os quatro vizinhos diretos de uma celula caminhavel:

- direita
- esquerda
- baixo
- cima

Se algum vizinho for um espaco ou estiver fora do mapa, a celula esta exposta
ao exterior e o mapa e considerado aberto.

### `check_closed`

```c
static int	check_closed(char **board)
```

Percorre todas as celulas do mapa e procura areas caminhaveis abertas.

Os caracteres considerados caminhaveis sao:

```text
0 N S E W
```

Para cada um deles, chama `has_open_neighbor`. Uma unica celula exposta ja e
suficiente para rejeitar o mapa.

Paredes `1` e espacos nao precisam ser testados como posicoes caminhaveis.

### Alteracao em `board_validator`

```c
int	board_validator(char **board)
```

Coordena as duas validacoes estruturais principais:

1. Chama `check_player`.
2. Chama `check_closed`.
3. Exibe uma mensagem especifica quando o mapa esta aberto.
4. Retorna `0` apenas quando as duas verificacoes passam.

Essa implementacao evita depender de uma leitura retangular do grid e funciona
com linhas de tamanhos diferentes.

## Alteracoes no `Makefile`

O `Makefile` tambem foi alterado nesta etapa.

Foram adicionadas as variaveis:

```makefile
MLX_DIR = mlx
MLX = ${MLX_DIR}/libmlx_Linux.a
```

O executavel `cub3D` agora depende da biblioteca da MiniLibX:

```makefile
$(NAME): ${LIBFT} ${MLX} ${OBJS}
```

Quando a biblioteca ainda nao existe, o `Makefile` executa:

```makefile
make -C ${MLX_DIR}
```

Essa alteracao prepara o projeto para compilar a MLX automaticamente no Linux.

## Resultado da etapa

Depois dessas alteracoes:

- a ultima linha sem `\n` nao perde caracteres
- arquivos com `\r\n` sao normalizados
- linhas vazias dentro do mapa sao rejeitadas
- conteudo depois do mapa e rejeitado
- mapas abertos e irregulares sao lidos com seguranca
- configuracoes de cor aceitam espacos controlados
- componentes vazios e conteudo extra nas cores sao rejeitados
- a MiniLibX passa a fazer parte das dependencias do build
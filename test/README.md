# Validation tester

This tester builds a small executable that only runs the `.cub` parsing and
validation path. It does not open the MLX window, so valid maps can be tested
without entering `mlx_loop`.

Run inside Linux/WSL from the project root:

```sh
make -C tests
```

The cases are generated in `tests/tmp_validation` and cover:

- valid minimal map
- open map
- missing player
- duplicated player
- empty line inside map
- RGB colors with spaces
- RGB value out of range
- missing texture file
- final line without `\n`

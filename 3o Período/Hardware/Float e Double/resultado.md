# Resultados do Teste

Float: 100958.343750 | Diferença: -958.343750\
Double: 100000.000001 | Diferença: -0.000001

# Explicação

A mantissa guarda o número de dígitos signficativos de um número em binário. Quanto mais bits ela tem, maior a precisão. Float tem 32 bits e mantissa 23, enquanto double tem 64 bits e mantissa 52.

Como o número 0.1 em binário é uma dízima periódica infinita, esse valor é arredondado. Assim, cada soma de 0.1 gera um pequeno erro de arredondamento que se acumula a cada incremento. Por ter uma mantissa mais curta, o erro de representação aparece mais cedo no float do que no double. 
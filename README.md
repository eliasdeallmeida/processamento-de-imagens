# Processamento de Imagens
Esse projeto sobre Processamento de Imagens na Linguagem C foi atribuído como Trabalho Final da disciplina de Laboratório de Programação.

Inicialmente, o programa pedirá que o usuário informe o **Nível de Quantização** desejada. Em seguida, realizará a leitura de duas imagens simultaneamente, sendo uma original e outra filtrada (identificada pela terminação "mean"). Durante o processamento, será feito a quantização das imagens para, então, ser calculada a **Matriz de Co-ocorrência Estrutural (Structural Co-ocurrence Matrix)**. Ao final do processo, essa matriz será vetorizada em um arquivo .txt juntamente ao rótulo de identificação das imagens quantizadas.

## Windows
Compilar:
```
mingw32-make
```
Executar:
```
prog.e
```

## Linux
Compilar:
```
make
```
Executar:
```
./prog.e
```

## MacOS
Compilar:
```
make
```
Executar:
```
./prog.e
```

## Arquivos Gerados
Ao fim da execução, o programa criará:
- Imagens quantizadas na pasta **quantized-images**.
- Arquivo nomeado com o padrão **level-numero.txt** que contém as matrizes de co-ocorrẽncia vetorizadas com seu rótulo.
- Arquivo **images-read.txt** contendo os nomes das imagens processadas em ordem.

## Colaboradores
- Chrislan Machado
- Elias de Almeida
- João Pedro Lopes
- Rai Ferreira

## Licença
[MIT License](https://choosealicense.com/licenses/mit/)

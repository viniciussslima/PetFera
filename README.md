# PetFera

## Autores: 
	Hudson Bruno Macedo Alves
	João Vitor Kobata
	Vinicius Santos Silva de Lima

## Objetivo:

O objetivo deste trabalho é implementar um programa de cadastro de animais para a loja de animais silvestres Pet Fera utilizando a biblioteca de interface gráfica gtkmm.

## Instruções:

Para compilar é necessario ter instalado o gtkmm 3

Caso não tenha, acesse:	https://www.gtkmm.org/pt_BR/download.html

### Para compilar:

	make

### Para recompilar:

	make remake

### Para limpar os arquivos auxiliares:

    make clean

### Para limpar os arquivos auxiliares e executáveis:

    make cleanall
    
### Para rodar o PetFera(após compilar):
    make run

### Para Exportar informações:
    ./bin/exportar -c <classe> -v <ID do veterinario> -t <ID do tratador>

### Para gerar a documentação Doxygen:
    doxygen
    

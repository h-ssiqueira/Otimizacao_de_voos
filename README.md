# Otimização_de_vôos
![GitHub Repository Size](https://img.shields.io/github/repo-size/h-ssiqueira/Otimizacao_de_voos?label=Repository%20Size&style=for-the-badge)

![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)

![VS Code](https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white)

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

## Descrição do projeto
O projeto foi realizado para a disciplina de [Estrutura e Recuperação de Dados B](https://github.com/h-ssiqueira/ProgramsCOLLEGE#ERD-B). O [projeto](ERDB-Projeto2.pdf) tem o objetivo de demonstrar as rotas e conexões de vôos entre aeroportos, utilizando um grafo dirigido, apontando os destinos, conexões e menores custos, processados a partir de um arquivo (.txt) que contêm as informações de vôos e aeroportos, juntamente com os custos de viagem. Para mais informações consulte o [relatório do projeto](Relatório%20projeto%202.pdf).

## Como executar
É necessário executar o comando ```make``` no terminal para que seja compilado o programa. Entretanto há possibilidade de inserção de outros comandos para manipulação:
Comando | Descrição
:---: | :---:
```make clean``` | Remove todos os arquivos objeto (.o)
```make rmproper``` | Remove todos os arquivos gerados na compilação

Para executar o programa propriamente dito, é necessário executar ```./proj2 <arquivo>.txt <inicial>``` no terminal, onde "arquivo" é o nome do arquivo que contém as informações dos aeroportos (neste repositório: [voos](Voos.txt), [teste](teste.txt) e [cíclico](GCiclico.txt)), e "inicial" é o nome (representado por 3 letras) do aeroporto de início.

## Autores
- [Alcides Beato](https://github.com/alcidesbeato)
- [Henrique Siqueira](https://github.com/h-ssiqueira)
- [Rafael Barbon](https://github.com/RafaelBarbon)
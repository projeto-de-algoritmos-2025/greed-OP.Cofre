# greed-OP.Cofre
## Alunos
|Matrícula | Aluno |
| -- | -- |
| 22/2006383 | Rafael Melo Matuda |
| 22/1021868 | Caio Falcão Habibi Costa |

#  Operação Cofre: Logística da Fortuna

##  Descrição do Projeto

Durante uma crise nacional, você assume o papel de um especialista em logística de alto nível, contratado para extrair os bens mais valiosos de cofres de bancos e organizá-los de forma eficiente e segura para transporte.  

O sistema simula essa missão em três etapas principais:

1. **Seleção estratégica dos bens com base no valor e peso**.
2. **Coordenação da saída dos caminhões para evitar conflitos logísticos**.
3. **Compressão e proteção da lista de bens transportados**.

---

## ⚙ Algoritmos Utilizados

### 1. Knapsack Fracionário
- **Objetivo**: Selecionar os itens mais valiosos proporcionalmente ao peso, respeitando a capacidade máxima de carga do caminhão.
- **Funcionamento**: Os itens são ordenados pela razão valor/peso e incluídos integral ou parcialmente até atingir o limite de capacidade.

### 2. Interval Partitioning
- **Objetivo**: Organizar os horários de saída dos caminhões blindados, minimizando o número de pistas utilizadas.
- **Funcionamento**: Cada intervalo (início e fim de carregamento) é alocado a uma "pista" de forma que não haja sobreposição de horários no mesmo recurso.

### 3. Codificação de Huffman
- **Objetivo**: Comprimir e proteger a lista de bens transportados para comunicação segura.
- **Funcionamento**: A partir da frequência dos caracteres, o algoritmo constrói uma árvore de codificação eficiente e gera um texto binário compactado.

---



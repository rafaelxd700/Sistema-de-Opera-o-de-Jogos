🎮 GameOps — Sistema de Operação de Jogos
1. Descrição do Sistema

O GameOps – Sistema de Operação de Jogos é um sistema desenvolvido em C++ com o objetivo de gerenciar jogadores, organizar filas de espera, controlar partidas e registrar ações realizadas durante a utilização do programa.

O sistema permite cadastrar jogadores, armazenar suas informações, realizar buscas por ID, listar jogadores cadastrados, ordenar pontuações e comparar algoritmos de busca.

Além disso, possibilita organizar jogadores em uma fila de espera, criar e remover partidas e manter um histórico de ações que podem ser desfeitas.

O projeto foi desenvolvido utilizando estruturas de dados dinâmicas, ponteiros, alocação e liberação de memória.

2. Tema Escolhido

O tema escolhido foi Gerenciamento e Organização de Jogadores em Partidas de Jogos.

A proposta é simular um sistema de gerenciamento no qual jogadores podem ser cadastrados, organizados e encaminhados para partidas, respeitando a ordem de chegada na fila de espera.

O sistema também permite acompanhar informações dos jogadores, como nível e pontuação, além de registrar partidas e ações realizadas.

3. Estruturas de Dados Utilizadas

O projeto utiliza diferentes estruturas de dados para organizar e manipular as informações.

3.1 Árvore Binária de Busca (ABB)

A Árvore Binária de Busca é utilizada para armazenar os jogadores, organizando-os de acordo com seus IDs.

Cada jogador possui um ID único, utilizado como chave de organização.

IDs menores são armazenados à esquerda.
IDs maiores são armazenados à direita.
Permite realizar buscas recursivas por ID.
Permite listar os jogadores em ordem crescente de ID por meio do percurso in-order.
3.2 Fila FIFO

A fila é utilizada para organizar os jogadores que aguardam atendimento para entrar em uma partida.

FIFO significa First In, First Out (primeiro a entrar, primeiro a sair).

Novos jogadores são adicionados ao final da fila.
O atendimento acontece pela frente da fila.
O primeiro jogador que entra é o primeiro a ser atendido.
3.3 Pilha LIFO

A pilha é utilizada para armazenar o histórico de ações realizadas no sistema.

LIFO significa Last In, First Out (último a entrar, primeiro a sair).

Novas ações são adicionadas ao topo da pilha.
A última ação registrada é a primeira a ser removida.
Permite consultar o histórico de ações.
Permite desfazer a última ação registrada.
3.4 Lista Simplesmente Encadeada

A lista simplesmente encadeada é utilizada para armazenar o histórico de partidas criadas no sistema.

Cada elemento contém informações sobre a partida e um ponteiro para o próximo elemento.

Permite cadastrar novas partidas.
Permite listar todas as partidas cadastradas.
Permite remover partidas utilizando seu ID.
Os elementos são armazenados dinamicamente.
4. Diagrama das Estruturas de Dados
text
                 GAMEOPS
                    |
       +------------+-------------+
       |            |             |
       ABB         FILA          PILHA
       |            |             |
   Jogadores     Espera de     Histórico de
    por ID       jogadores       ações
       |            |             |
   Esquerda     Frente/Fim       Topo
   Direita
                    |
              LISTA ENCADEADA
                    |
             Histórico de partidas
                    |
             Inserção e remoção

5. Algoritmos Implementados
5.1 Bubble Sort

Foi implementado o algoritmo Bubble Sort para ordenar os jogadores de acordo com suas pontuações.

Primeiramente, os jogadores são copiados da árvore binária de busca para um vetor. Em seguida, o algoritmo compara os elementos vizinhos e realiza trocas quando necessário.

Complexidade:

Melhor caso: O(n²), considerando a implementação utilizada.
Caso médio: O(n²).
Pior caso: O(n²).
Espaço auxiliar: O(n), devido ao vetor utilizado.
5.2 Busca Sequencial

A busca sequencial percorre os elementos do vetor um por um até encontrar o ID procurado ou chegar ao final.

Complexidade:

Melhor caso: O(1).
Caso médio: O(n).
Pior caso: O(n).
5.3 Busca Binária

A busca binária utiliza um vetor ordenado por ID para encontrar um jogador.

O algoritmo compara o ID procurado com o elemento central e descarta metade dos elementos a cada iteração.

Complexidade:

Melhor caso: O(1).
Caso médio: O(log n).
Pior caso: O(log n).

O sistema também compara a quantidade de comparações realizadas pela busca sequencial e pela busca binária.

6. Divisão de Responsabilidades
Rafael Del Antonio
Desenvolvimento da estrutura de Árvore Binária de Busca.
Implementação do cadastro de jogadores.
Implementação da busca recursiva por ID.
Listagem dos jogadores cadastrados.
Leticia
Desenvolvimento da estrutura de Fila FIFO.
Implementação das operações de adicionar jogadores à fila.
Implementação do atendimento dos jogadores.
Implementação da listagem da fila.
Pierre
Apoio no desenvolvimento e integração do sistema.
Auxílio na implementação e organização das funcionalidades.
Testes e verificação do funcionamento das estruturas de dados.
7. Gerenciamento de Memória

O sistema utiliza alocação dinâmica de memória por meio dos operadores new e delete.

As estruturas de dados são construídas utilizando ponteiros, permitindo criar e remover elementos durante a execução do programa.

Para evitar vazamentos de memória, foram implementadas funções específicas para liberar os elementos alocados:

liberarArvore(): libera todos os nós da árvore binária de busca.
liberarFila(): libera todos os elementos da fila.
liberarPilha(): libera todos os elementos da pilha.
liberarPartidas(): libera todos os elementos da lista de partidas.

Essas funções são chamadas ao encerrar o programa, garantindo a liberação da memória dinâmica utilizada pelas estruturas.

8. Tecnologias Utilizadas
C++: linguagem utilizada no desenvolvimento do sistema.
Git: ferramenta utilizada para controle de versão.
GitHub: plataforma utilizada para armazenar e compartilhar o código-fonte.
Visual Studio Code: ambiente utilizado para desenvolvimento.
9. Como Executar o Projeto
Clone o repositório:
bash
git clone URL_DO_REPOSITORIO

Entre na pasta do projeto:
bash
cd GameOps

Compile o código:
bash
g++ main.cpp -o GameOps

Execute o programa:

No Windows:

bash
GameOps.exe


No Linux:

bash
./GameOps

10. Funcionalidades do Sistema

O GameOps possui as seguintes funcionalidades:

Cadastrar jogador.
Buscar jogador por ID.
Listar jogadores cadastrados.
Ordenar jogadores por pontuação.
Comparar busca sequencial e busca binária.
Adicionar jogador à fila de espera.
Atender próximo jogador.
Listar jogadores na fila.
Criar partida.
Listar partidas.
Remover partida.
Registrar ação.
Desfazer última ação.
Listar histórico de ações.
11. Considerações Finais

O desenvolvimento do GameOps permitiu aplicar na prática conceitos importantes de estruturas de dados e algoritmos utilizando a linguagem C++.

Durante o projeto, foram trabalhadas estruturas como árvore binária de busca, fila FIFO, pilha LIFO e lista simplesmente encadeada, além dos algoritmos Bubble Sort, busca sequencial e busca binária.

O projeto também proporcionou conhecimentos sobre ponteiros, alocação dinâmica de memória, organização de código, integração de funcionalidades e controle de versão com Git e GitHub.

Dessa forma, o sistema demonstra como diferentes estruturas de dados podem ser utilizadas em conjunto para desenvolver uma aplicação de gerenciamento de jogadores e partidas.

#include <iostream>
#include <string>
#include <limits>
#include <chrono>

using namespace std;

// ==========================================
// ESTRUTURA DO JOGADOR
// ==========================================

struct Jogador {
    int id;
    string nome;
    int nivel;
    int pontuacao;
};

// ==========================================
// R8 - ARVORE BINARIA DE BUSCA (ABB)
// ==========================================

struct NoArvore {
    Jogador jogador;
    NoArvore* esquerda;
    NoArvore* direita;
};

NoArvore* raiz = nullptr;

NoArvore* inserirJogador(NoArvore* no, Jogador jogador) {
    if (no == nullptr) {
        NoArvore* novo = new NoArvore;
        novo->jogador = jogador;
        novo->esquerda = nullptr;
        novo->direita = nullptr;
        return novo;
    }

    if (jogador.id < no->jogador.id) {
        no->esquerda = inserirJogador(no->esquerda, jogador);
    }
    else if (jogador.id > no->jogador.id) {
        no->direita = inserirJogador(no->direita, jogador);
    }
    else {
        cout << "ID ja cadastrado!\n";
    }

    return no;
}

// R3 - BUSCA RECURSIVA

NoArvore* buscarJogador(NoArvore* no, int id) {
    if (no == nullptr || no->jogador.id == id) {
        return no;
    }

    if (id < no->jogador.id) {
        return buscarJogador(no->esquerda, id);
    }

    return buscarJogador(no->direita, id);
}

// Percurso in-order recursivo

void listarJogadores(NoArvore* no) {
    if (no != nullptr) {
        listarJogadores(no->esquerda);

        cout << "ID: " << no->jogador.id
             << " | Nome: " << no->jogador.nome
             << " | Nivel: " << no->jogador.nivel
             << " | Pontuacao: " << no->jogador.pontuacao
             << endl;

        listarJogadores(no->direita);
    }
}

// Liberar memoria da arvore

void liberarArvore(NoArvore* no) {
    if (no != nullptr) {
        liberarArvore(no->esquerda);
        liberarArvore(no->direita);
        delete no;
    }
}

// ==========================================
// R7 - FILA FIFO
// ==========================================

struct NoFila {
    Jogador jogador;
    NoFila* proximo;
};

NoFila* frente = nullptr;
NoFila* fim = nullptr;

void adicionarFila(Jogador jogador) {
    NoFila* novo = new NoFila;
    novo->jogador = jogador;
    novo->proximo = nullptr;

    if (fim == nullptr) {
        frente = novo;
    }
    else {
        fim->proximo = novo;
    }

    fim = novo;

    cout << "Jogador adicionado a fila!\n";
}

void atenderFila() {
    if (frente == nullptr) {
        cout << "Fila vazia!\n";
        return;
    }

    NoFila* temp = frente;

    cout << "Jogador atendido: "
         << temp->jogador.nome << endl;

    frente = frente->proximo;

    if (frente == nullptr) {
        fim = nullptr;
    }

    delete temp;
}

void listarFila() {
    if (frente == nullptr) {
        cout << "Fila vazia!\n";
        return;
    }

    NoFila* atual = frente;

    cout << "\n--- FILA DE ESPERA ---\n";

    while (atual != nullptr) {
        cout << atual->jogador.nome << endl;
        atual = atual->proximo;
    }
}

void liberarFila() {
    while (frente != nullptr) {
        NoFila* temp = frente;
        frente = frente->proximo;
        delete temp;
    }

    fim = nullptr;
}

// ==========================================
// R6 - PILHA DE HISTORICO DE ACOES
// ==========================================

struct NoPilha {
    string acao;
    NoPilha* proximo;
};

NoPilha* topo = nullptr;

void registrarAcao(string acao) {
    NoPilha* novo = new NoPilha;

    novo->acao = acao;
    novo->proximo = topo;

    topo = novo;

    cout << "Acao registrada!\n";
}

void desfazerAcao() {
    if (topo == nullptr) {
        cout << "Nenhuma acao registrada!\n";
        return;
    }

    NoPilha* temp = topo;

    cout << "Ultima acao desfeita: "
         << temp->acao << endl;

    topo = topo->proximo;

    delete temp;
}

void listarAcoes() {
    if (topo == nullptr) {
        cout << "Historico vazio!\n";
        return;
    }

    NoPilha* atual = topo;

    cout << "\n--- HISTORICO DE ACOES ---\n";

    while (atual != nullptr) {
        cout << atual->acao << endl;
        atual = atual->proximo;
    }
}

void liberarPilha() {
    while (topo != nullptr) {
        NoPilha* temp = topo;
        topo = topo->proximo;
        delete temp;
    }
}

// ==========================================
// R5 - LISTA ENCADEADA DE PARTIDAS
// ==========================================

struct Partida {
    int id;
    string jogo;
    string data;
    int jogadores;
    Partida* proximo;
};

Partida* inicioPartidas = nullptr;

void criarPartida() {
    Partida* nova = new Partida;

    cout << "ID da partida: ";
    cin >> nova->id;

    cout << "Nome do jogo: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nova->jogo);

    cout << "Data da partida: ";
    getline(cin, nova->data);

    cout << "Quantidade de jogadores: ";
    cin >> nova->jogadores;

    nova->proximo = nullptr;

    if (inicioPartidas == nullptr) {
        inicioPartidas = nova;
    }
    else {
        Partida* atual = inicioPartidas;

        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }

        atual->proximo = nova;
    }

    cout << "Partida criada com sucesso!\n";
}

void listarPartidas() {
    Partida* atual = inicioPartidas;

    if (atual == nullptr) {
        cout << "Nenhuma partida cadastrada!\n";
        return;
    }

    cout << "\n--- HISTORICO DE PARTIDAS ---\n";

    while (atual != nullptr) {
        cout << "ID: " << atual->id
             << " | Jogo: " << atual->jogo
             << " | Data: " << atual->data
             << " | Jogadores: " << atual->jogadores
             << endl;

        atual = atual->proximo;
    }
}

void removerPartida() {
    int id;

    cout << "Digite o ID da partida: ";
    cin >> id;

    Partida* atual = inicioPartidas;
    Partida* anterior = nullptr;

    while (atual != nullptr && atual->id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == nullptr) {
        cout << "Partida nao encontrada!\n";
        return;
    }

    if (anterior == nullptr) {
        inicioPartidas = atual->proximo;
    }
    else {
        anterior->proximo = atual->proximo;
    }

    delete atual;

    cout << "Partida removida!\n";
}

void liberarPartidas() {
    while (inicioPartidas != nullptr) {
        Partida* temp = inicioPartidas;
        inicioPartidas = inicioPartidas->proximo;
        delete temp;
    }
}

// ==========================================
// R9 - ORDENACAO BUBBLE SORT
// ==========================================

void ordenarPontuacao() {
    Jogador vetor[1000];
    int quantidade = 0;

    // Copia os jogadores da ABB para o vetor
    // usando percurso in-order.

    NoArvore* pilha[1000];
    int topoPilha = 0;
    NoArvore* atual = raiz;

    while (atual != nullptr || topoPilha > 0) {
        while (atual != nullptr) {
            pilha[topoPilha++] = atual;
            atual = atual->esquerda;
        }

        atual = pilha[--topoPilha];

        if (quantidade < 1000) {
            vetor[quantidade++] = atual->jogador;
        }

        atual = atual->direita;
    }

    if (quantidade == 0) {
        cout << "Nenhum jogador cadastrado!\n";
        return;
    }

    // Bubble Sort por pontuacao

    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            if (vetor[j].pontuacao > vetor[j + 1].pontuacao) {
                Jogador temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    cout << "\n--- JOGADORES ORDENADOS POR PONTUACAO ---\n";

    for (int i = 0; i < quantidade; i++) {
        cout << vetor[i].nome
             << " - Pontuacao: "
             << vetor[i].pontuacao << endl;
    }
}

// ==========================================
// R10 - BUSCA SEQUENCIAL E BINARIA
// ==========================================

int obterVetorOrdenado(Jogador vetor[]) {
    int quantidade = 0;

    NoArvore* pilha[1000];
    int topoPilha = 0;
    NoArvore* atual = raiz;

    while (atual != nullptr || topoPilha > 0) {
        while (atual != nullptr) {
            pilha[topoPilha++] = atual;
            atual = atual->esquerda;
        }

        atual = pilha[--topoPilha];

        if (quantidade < 1000) {
            vetor[quantidade++] = atual->jogador;
        }

        atual = atual->direita;
    }

    return quantidade;
}

void compararBuscas() {
    Jogador vetor[1000];

    int quantidade = obterVetorOrdenado(vetor);

    if (quantidade == 0) {
        cout << "Nenhum jogador cadastrado!\n";
        return;
    }

    int id;

    cout << "Digite o ID que deseja buscar: ";
    cin >> id;

    int comparacoesSequencial = 0;
    int comparacoesBinaria = 0;

    int posicaoSequencial = -1;

    // Busca sequencial

    for (int i = 0; i < quantidade; i++) {
        comparacoesSequencial++;

        if (vetor[i].id == id) {
            posicaoSequencial = i;
            break;
        }
    }

    // Busca binaria

    int inicio = 0;
    int fimBusca = quantidade - 1;
    int posicaoBinaria = -1;

    while (inicio <= fimBusca) {
        comparacoesBinaria++;

        int meio = (inicio + fimBusca) / 2;

        if (vetor[meio].id == id) {
            posicaoBinaria = meio;
            break;
        }
        else if (id < vetor[meio].id) {
            fimBusca = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }

    cout << "\n--- RESULTADO DAS BUSCAS ---\n";

    if (posicaoSequencial != -1) {
        cout << "Jogador encontrado: "
             << vetor[posicaoSequencial].nome << endl;
    }
    else {
        cout << "Jogador nao encontrado!\n";
    }

    cout << "\nBusca sequencial: "
         << comparacoesSequencial << " comparacoes\n";

    cout << "Busca binaria: "
         << comparacoesBinaria << " comparacoes\n";
}

// ==========================================
// R1 - CADASTRAR JOGADOR
// ==========================================

void cadastrarJogador() {
    Jogador jogador;

    cout << "ID do jogador: ";
    cin >> jogador.id;

    if (buscarJogador(raiz, jogador.id) != nullptr) {
        cout << "Esse ID ja existe!\n";
        return;
    }

    cout << "Nome: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, jogador.nome);

    cout << "Nivel: ";
    cin >> jogador.nivel;

    cout << "Pontuacao: ";
    cin >> jogador.pontuacao;

    raiz = inserirJogador(raiz, jogador);

    cout << "Jogador cadastrado com sucesso!\n";
}

// ==========================================
// MENU PRINCIPAL
// ==========================================

void menu() {
    int opcao;

    do {
        cout << "\n====================================\n";
        cout << "       GAMEOPS - SISTEMA DE JOGOS\n";
        cout << "====================================\n";

        cout << "1  - Cadastrar jogador\n";
        cout << "2  - Buscar jogador por ID\n";
        cout << "3  - Listar jogadores\n";
        cout << "4  - Ordenar por pontuacao\n";
        cout << "5  - Comparar buscas\n";
        cout << "6  - Adicionar jogador a fila\n";
        cout << "7  - Atender proximo jogador\n";
        cout << "8  - Listar fila\n";
        cout << "9  - Criar partida\n";
        cout << "10 - Listar partidas\n";
        cout << "11 - Remover partida\n";
        cout << "12 - Registrar acao\n";
        cout << "13 - Desfazer ultima acao\n";
        cout << "14 - Listar historico de acoes\n";
        cout << "0  - Sair\n";

        cout << "====================================\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1:
                cadastrarJogador();
                break;

            case 2: {
                int id;

                cout << "Digite o ID: ";
                cin >> id;

                NoArvore* encontrado = buscarJogador(raiz, id);

                if (encontrado != nullptr) {
                    cout << "Jogador: "
                         << encontrado->jogador.nome
                         << " | Nivel: "
                         << encontrado->jogador.nivel
                         << " | Pontuacao: "
                         << encontrado->jogador.pontuacao
                         << endl;
                }
                else {
                    cout << "Jogador nao encontrado!\n";
                }

                break;
            }

            case 3:
                listarJogadores(raiz);
                break;

            case 4:
                ordenarPontuacao();
                break;

            case 5:
                compararBuscas();
                break;

            case 6: {
                int id;

                cout << "ID do jogador: ";
                cin >> id;

                NoArvore* jogador = buscarJogador(raiz, id);

                if (jogador != nullptr) {
                    adicionarFila(jogador->jogador);
                }
                else {
                    cout << "Jogador nao encontrado!\n";
                }

                break;
            }

            case 7:
                atenderFila();
                break;

            case 8:
                listarFila();
                break;

            case 9:
                criarPartida();
                break;

            case 10:
                listarPartidas();
                break;

            case 11:
                removerPartida();
                break;

            case 12: {
                string acao;

                cout << "Descreva a acao realizada: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, acao);

                registrarAcao(acao);
                break;
            }

            case 13:
                desfazerAcao();
                break;

            case 14:
                listarAcoes();
                break;

            case 0:
                cout << "Encerrando GameOps...\n";
                break;

            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);
}

// ==========================================
// MAIN
// ==========================================

int main() {
    cout << "Bem-vindo ao GameOps!\n";

    menu();

    // Liberacao de toda memoria dinamica

    liberarArvore(raiz);
    liberarFila();
    liberarPilha();
    liberarPartidas();

    cout << "Memoria liberada com sucesso!\n";

    return 0;
}

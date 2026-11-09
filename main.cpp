#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// ================= JOGADORES: ARVORE BINARIA DE BUSCA =================

struct Jogador {
    int id;
    string nome;
    int nivel;
    int pontuacao;
    Jogador* esquerda;
    Jogador* direita;
};

class ArvoreJogadores {
private:
    Jogador* raiz;

    Jogador* inserir(Jogador* no, int id, const string& nome, int nivel, int pontuacao) {
        if (no == nullptr) {
            Jogador* novo = new Jogador{id, nome, nivel, pontuacao, nullptr, nullptr};
            return novo;
        }

        if (id < no->id)
            no->esquerda = inserir(no->esquerda, id, nome, nivel, pontuacao);
        else if (id > no->id)
            no->direita = inserir(no->direita, id, nome, nivel, pontuacao);

        return no;
    }

    Jogador* buscar(Jogador* no, int id) const {
        if (no == nullptr || no->id == id)
            return no;

        if (id < no->id)
            return buscar(no->esquerda, id);

        return buscar(no->direita, id);
    }

    void listarEmOrdem(Jogador* no) const {
        if (no == nullptr) return;

        listarEmOrdem(no->esquerda);

        cout << "ID: " << no->id
             << " | Nome: " << no->nome
             << " | Nivel: " << no->nivel
             << " | Pontuacao: " << no->pontuacao << '\n';

        listarEmOrdem(no->direita);
    }

    void copiarParaVetor(Jogador* no, vector<Jogador>& vetor) const {
        if (no == nullptr) return;

        copiarParaVetor(no->esquerda, vetor);
        vetor.push_back(*no);
        copiarParaVetor(no->direita, vetor);
    }

    void liberar(Jogador* no) {
        if (no == nullptr) return;

        liberar(no->esquerda);
        liberar(no->direita);
        delete no;
    }

public:
    ArvoreJogadores() : raiz(nullptr) {}

    ~ArvoreJogadores() {
        liberar(raiz);
    }

    bool cadastrar(int id, const string& nome, int nivel, int pontuacao) {
        if (buscar(raiz, id) != nullptr)
            return false;

        raiz = inserir(raiz, id, nome, nivel, pontuacao);
        return true;
    }

    Jogador* buscarJogador(int id) const {
        return buscar(raiz, id);
    }

    void listar() const {
        if (raiz == nullptr) {
            cout << "Nenhum jogador cadastrado.\n";
            return;
        }

        cout << "\n--- JOGADORES (ordem crescente de ID) ---\n";
        listarEmOrdem(raiz);
    }

    vector<Jogador> obterVetor() const {
        vector<Jogador> vetor;
        copiarParaVetor(raiz, vetor);
        return vetor;
    }
};

// ================= FILA: JOGADORES AGUARDANDO (FIFO) =================

struct NoFila {
    int id;
    string nome;
    NoFila* proximo;
};

class Fila {
private:
    NoFila* frente;
    NoFila* fim;

public:
    Fila() : frente(nullptr), fim(nullptr) {}

    ~Fila() {
        while (frente != nullptr) {
            NoFila* auxiliar = frente;
            frente = frente->proximo;
            delete auxiliar;
        }
    }

    void adicionar(int id, const string& nome) {
        NoFila* novo = new NoFila{id, nome, nullptr};

        if (fim == nullptr)
            frente = novo;
        else
            fim->proximo = novo;

        fim = novo;
        cout << "Jogador adicionado a fila.\n";
    }

    void atender() {
        if (frente == nullptr) {
            cout << "A fila esta vazia.\n";
            return;
        }

        NoFila* auxiliar = frente;

        cout << "Entrou na partida: " << auxiliar->nome
             << " (ID " << auxiliar->id << ")\n";

        frente = frente->proximo;

        if (frente == nullptr)
            fim = nullptr;

        delete auxiliar;
    }

    void listar() const {
        if (frente == nullptr) {
            cout << "Fila vazia.\n";
            return;
        }

        cout << "Frente -> ";

        NoFila* atual = frente;

        while (atual != nullptr) {
            cout << atual->nome << " -> ";
            atual = atual->proximo;
        }

        cout << "FIM\n";
    }
};
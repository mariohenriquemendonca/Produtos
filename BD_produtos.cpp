#include <iostream>
#include <fstream>


using namespace std;

struct produto {
    int Id;
    string nome;
    float preco;
    int quantidade;
    char status; 
};

void adicionarProduto(produto produtos[], int& quantidadeAtual) {
    produtos[quantidadeAtual].Id = quantidadeAtual + 1;  
    cout << "Nome do produto: ";
    cin >> produtos[quantidadeAtual].nome;
    cout << "Preço do produto: ";
    cin >> produtos[quantidadeAtual].preco;
    cout << "Quantidade em stock: ";
    cin >> produtos[quantidadeAtual].quantidade;
    produtos[quantidadeAtual].status = 'A';  
    quantidadeAtual++;
}

void exibirProdutos(const produto produtos[], int quantidadeAtual) {
    for (int i = 0; i < quantidadeAtual; i++) {
        if (produtos[i].status == 'A') {  
            cout << "Produto " << i + 1 << ":" << endl;
            cout << "ID: " << produtos[i].Id << endl;
            cout << "Nome: " << produtos[i].nome << endl;
            cout << "Preço: " << produtos[i].preco << endl;
            cout << "Quantidade: " << produtos[i].quantidade << endl;
            cout << "Status: " << (produtos[i].status == 'A' ? "Ativo" : "Eliminado") << endl;
            cout << "-------------------------" << endl;
        }
    }
}

void salvarProdutos(const produto produtos[], int quantidadeAtual) {
    ofstream file("produtos.csv");

    for (int i = 0; i < quantidadeAtual; i++) {
        file << produtos[i].Id << "," << produtos[i].nome << "," << produtos[i].quantidade << ",";
        file << produtos[i].preco << "," << produtos[i].status << endl;
    }

    file.close();
    cout << "Produtos salvos" << endl;
}

float calcularValorTotal(const produto produtos[], int quantidadeAtual) {
    float valorTotal = 0.0;
    for (int i = 0; i < quantidadeAtual; i++) {
        if (produtos[i].status == 'A') {  
            valorTotal += produtos[i].preco * produtos[i].quantidade;
        }
    }
    return valorTotal;
}

void alterarProduto(produto produtos[], int quantidadeAtual) {
    int id;
    cout << "ID do produto que deseja alterar: ";
    cin >> id;

    for (int i = 0; i < quantidadeAtual; i++) {
        if (produtos[i].Id == id && produtos[i].status == 'A') {
            cout << "Nome atual: " << produtos[i].nome << endl;
            cout << "Novo: ";
            cin >> produtos[i].nome;
            cout << "Preço atual: " << produtos[i].preco << endl;
            cout << "Novo: ";
            cin >> produtos[i].preco;
            cout << "Quantidade atual: " << produtos[i].quantidade << endl;
            cout << "Nova: ";
            cin >> produtos[i].quantidade;
            cout << "Produto alterado" << endl;
            return;
        }
    }
    cout << "Produto não encontrado ou está eliminado." << endl;
}

void eliminarProduto(produto produtos[], int quantidadeAtual) {
    int id;
    cout << "Digite o ID do produto que deseja eliminar: ";
    cin >> id;

    for (int i = 0; i < quantidadeAtual; i++) {
        if (produtos[i].Id == id && produtos[i].status == 'A') {
            produtos[i].status = 'D';  
            cout << "Produto eliminado" << endl;
            return;
        }
    }
    cout << "Produto não encontrado ou já está eliminado." << endl;
}

int main() {
    produto maxProdutos[100];
    int quantidadeAtual = 0;
    int escolhas;

    do {
        cout << "Escolha uma opção:" << endl;
        cout << "1 Adicionar Produto" << endl;
        cout << "2 Exibir Produtos" << endl;
        cout << "3 Calcular Valor Total do stock" << endl;
        cout << "4 Salvar Produtos" << endl;
        cout << "5 Alterar" << endl;
        cout << "6 Eliminar" << endl;
        cout << "0 Sair" << endl;
        cin >> escolhas;

        switch (escolhas) {
            case 1:
                adicionarProduto(maxProdutos, quantidadeAtual);
                break;
            case 2:
                exibirProdutos(maxProdutos, quantidadeAtual);
                break;
            case 3:
                cout << "Valor do stock: " << calcularValorTotal(maxProdutos, quantidadeAtual) << endl;
                break;
            case 4:
                salvarProdutos(maxProdutos, quantidadeAtual);
                break;
            case 5:
                alterarProduto(maxProdutos, quantidadeAtual);
                break;
            case 6:
                eliminarProduto(maxProdutos, quantidadeAtual);
                break;
            case 0:
                cout << "Saindo" << endl;
                break;
            default:
                cout << "Escolha outra opcao." << endl;
        }
    } while (escolhas != 0);

    return 0;
}

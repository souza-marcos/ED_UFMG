#include "Set.hpp"

int StringSet::Hash(string s){
    int hash = 0;
    for(int i = 0; i < s.size(); i++){
        hash += s[i] * (i + 1); // Tratamento de anagramas
    }
    return hash % tamanhoTabela;
}

StringSet::StringSet(int tamanho) : 
    tamanhoOriginal(tamanho),
    tamanhoTabela(tamanho),
    tamanhoConjunto(0)
{
    tabela = new ElementoTabela[tamanhoTabela];
    for(int i = 0; i < tamanhoTabela; i++){
        tabela[i].vazio = true;
        tabela[i].retirada = false;
    }

}

StringSet::~StringSet(){
    delete[] tabela;
}

bool StringSet::Pertence(string s){
    int pos = Hash(s);
    int i = 0;

    while(i < tamanhoTabela // Não percorreu toda a tabela
        and !tabela[(pos + i) % tamanhoTabela].vazio // Não eh uma posicao vazia
        and tabela[(pos + i) % tamanhoTabela].dado != s){ 
    
        i ++;
    }

    if(tabela[(pos + i) % tamanhoTabela].dado == s 
        and !tabela[(pos + i) % tamanhoTabela].retirada){ // Nao tiver sido retirado
        return true;
    }
    return false;
}

void StringSet::Inserir(string s){

    // Resize se a tabela estiver na metade da capacidade
    if(tamanhoConjunto >= tamanhoTabela / 2){
        Resize(tamanhoTabela * 2);
    }

    int pos = Hash(s);
    int i = 0;
    
    // Procurando o elemento na tabela
    while(i < tamanhoTabela // Não percorreu toda a tabela
        and !tabela[(pos + i) % tamanhoTabela].vazio // Não eh uma posicao vazia
        and tabela[(pos + i) % tamanhoTabela].dado != s){ 
    
        i ++;
    }

    // if(i == tamanhoTabela) return; // Tabela Cheia

    if(tabela[(pos + i) % tamanhoTabela].dado == s 
        and !tabela[(pos + i) % tamanhoTabela].retirada){ // Nao tiver sido retirado
        return; // Elemento esta na tabela
    }

    tabela[(pos + i) % tamanhoTabela].dado = s;
    tabela[(pos + i) % tamanhoTabela].vazio = false;
    tabela[(pos + i) % tamanhoTabela].retirada = false;
    tamanhoConjunto++;
}

void StringSet::Remover(string s){
    int pos = Hash(s);
    int i = 0;
   

    // Procurando o elemento na tabela
    while(i < tamanhoTabela // Não percorreu toda a tabela
        and !tabela[(pos + i) % tamanhoTabela].vazio // Não eh uma posicao vazia
        and tabela[(pos + i) % tamanhoTabela].dado != s){ 
    
        i ++;
    }

    // if(i == tamanhoTabela) return; // Tabela Cheia

    if(tabela[(pos + i) % tamanhoTabela].dado == s 
        and !tabela[(pos + i) % tamanhoTabela].retirada){ // Nao tiver sido retirado
        
        tabela[(pos + i) % tamanhoTabela].retirada = true;
    }
}

void StringSet::Imprimir(){
    for(int i = 0; i < tamanhoTabela; i++){
        if(!tabela[i].vazio && !tabela[i].retirada)
            std::cout << tabela[i].dado << " ";
    }
}

void StringSet::Rehash(int pos){
  
}

void StringSet::Resize(size_t tamanho){
    ElementoTabela* novaTabela = new ElementoTabela[tamanho];
    for(int i = 0; i < tamanho; i++){
        novaTabela[i].vazio = true;
        novaTabela[i].retirada = false;
    }

    ElementoTabela* aux = tabela;
    tabela = novaTabela;
    tamanhoTabela = tamanho;
    tamanhoConjunto = 0;

    for(int i = 0; i < tamanhoOriginal; i++){
        if(!aux[i].vazio && !aux[i].retirada){
            Inserir(aux[i].dado);
        }
    }

    tamanhoOriginal = tamanho;
    delete[] aux;
}

StringSet* StringSet::Uniao(StringSet* S){
    StringSet* U = new StringSet(tamanhoTabela + S->tamanhoTabela);
    for(int i = 0; i < tamanhoTabela; i++){
        if(!tabela[i].vazio && !tabela[i].retirada){
            U->Inserir(tabela[i].dado);
        }
    }
    for(int i = 0; i < S->tamanhoTabela; i++){
        if(!S->tabela[i].vazio && !S->tabela[i].retirada){
            U->Inserir(S->tabela[i].dado);
        }
    }
    return U;
}

StringSet* StringSet::Intersecao(StringSet* S){
    StringSet* I = new StringSet(tamanhoTabela + S->tamanhoTabela);

    for(int i = 0; i < tamanhoTabela; i++){
        if(!tabela[i].vazio && !tabela[i].retirada){
            if(S->Pertence(tabela[i].dado)){
                I->Inserir(tabela[i].dado);
            }
        }
    }
    return I;
}

StringSet* StringSet::DiferencaSimetrica(StringSet* S){
    StringSet* D = new StringSet(tamanhoTabela + S->tamanhoTabela);

    StringSet* U = Uniao(S);
    StringSet* I = Intersecao(S);

    for(int i = 0; i < U->tamanhoTabela; i++){
        if(!U->tabela[i].vazio && !U->tabela[i].retirada){
            if(!I->Pertence(U->tabela[i].dado)){
                D->Inserir(U->tabela[i].dado);
            }
        }
    }
    
    return D;
}
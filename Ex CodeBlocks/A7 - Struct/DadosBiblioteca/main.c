//Nome e RA dos integrantes da equipe:
//Henrique Fortuna Accorinti          RA:20.00080-4
//Carlos Alberto Matias da Costa      RA:20.01308-6
//Henrique Estrella Pelicia Pressutti RA:19.02147-0
//Gustavo Henrique Aivazoglou         RA:20.01758-8

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING 200

//Estrutura
typedef struct {
    char titulo[MAX_STRING];
    int paginas;
    char autor[MAX_STRING];
} Livro;

//Prot�tipos das mensagens
//Mostrar uma estrutura Livro
void mostrarLivro(Livro livro);
//Compara duas estruturas Livro
int comparar(Livro l1, Livro l2);
//Troca dois elementos em um vetor
void trocar(Livro livros[], int posicao);
//Aplica o algoritmo de Bubble Sort
void bubble_sort(Livro livros[], int tamanho);
//Exibir tabela com os livros
void exibirLivrosComoTabela(Livro livros[], int tamanho);


//Programa principal
int main(){
    //Vetor de Livros que deve ser ordenado
    Livro livros[55] = {{"Harry Potter and the Half-Blood Prince ",652,"J.K. Rowling"},
{"Harry Potter and the Order of the Phoenix",870,"J.K. Rowling"},
{"Harry Potter and the Chamber of Secrets",352,"J.K. Rowling"},
{"Harry Potter and the Prisoner of Azkaban",435,"J.K. Rowling"},
{"Harry Potter Collection (Harry Potter  #1-6)",3342,"J.K. Rowling"},
{"The Ultimate Hitchhiker's Guide: Five Complete Novels and One Story",815,"Douglas Adams"},
{"The Ultimate Hitchhiker's Guide to the Galaxy ",815,"Douglas Adams"},
{"A Short History of Nearly Everything",544,"Bill Bryson"},
{"Bill Bryson's African Diary",55,"Bill Bryson"},
{"Bryson's Dictionary of Troublesome Words: A Writer's Guide to Getting It Right",256,"Bill Bryson"},
{"In a Sunburned Country",335,"Bill Bryson"},
{"I'm a Stranger Here Myself: Notes on Returning to America After Twenty Years Away",304,"Bill Bryson"},
{"The Lost Continent: Travels in Small Town America",299,"Bill Bryson"},
{"Neither Here nor There: Travels in Europe",254,"Bill Bryson"},
{"Notes from a Small Island",324,"Bill Bryson"},
{"The Mother Tongue: English and How It Got That Way",270,"Bill Bryson"},
{"J.R.R. Tolkien 4-Book Boxed Set: The Hobbit and The Lord of the Rings",1728,"J.R.R. Tolkien"},
{"The Lord of the Rings (The Lord of the Rings  #1-3)",1184,"J.R.R. Tolkien"},
{"The Fellowship of the Ring (The Lord of the Rings  #1)",398,"J.R.R. Tolkien"},
{"The Lord of the Rings (The Lord of the Rings  #1-3)",1216,"J.R.R. Tolkien/Alan  Lee"},
{"The Lord of the Rings: Weapons and Warfare",218,"Chris   Smith/Christopher  Lee/Richard Taylor"},
{"The Lord of the Rings: Complete Visual Companion",224,"Jude Fisher"},
{"Agile Web Development with Rails: A Pragmatic Guide",558,"Dave Thomas/David Heinemeier Hansson/Leon Breedt/Mike Clark/Thomas  Fuchs/Andreas  Schwarz"},
{"Hatchet (Brian's Saga  #1)",208,"Gary Paulsen"},
{"Guts: The True Stories behind Hatchet and the Brian Books",144,"Gary Paulsen"},
{"Molly Hatchet - 5 of the Best",56,"Molly Hatchet"},
{"Hatchet Jobs: Writings on Contemporary Fiction",228,"Dale Peck"},
{"A Changeling for All Seasons (Changeling Seasons #1)",304,"Angela Knight/Sahara Kelly/Judy Mays/Marteeka Karland/Kate Douglas/Shelby Morgen/Lacey Savage/Kate Hill/Willa Okati"},
{"Changeling (Changeling  #1)",256,"Delia Sherman"},
{"The Changeling Sea",137,"Patricia A. McKillip"},
{"The Changeling",228,"Zilpha Keatley Snyder"},
{"The Changeling",339,"Kate Horsley"},
{"The Changeling (Daughters of England  #15)",369,"Philippa Carr"},
{"The Known World",388,"Edward P. Jones"},
{"The Known World",14,"Edward P. Jones/Kevin R. Free"},
{"The Known World",576,"Edward P. Jones"},
{"Traders  Guns & Money: Knowns and Unknowns in the Dazzling World of Derivatives",334,"Satyajit Das"},
{"Artesia: Adventures in the Known World",352,"Mark Smylie"},
{"The John McPhee Reader (John McPhee Reader  #1)",416,"John McPhee/William Howarth"},
{"Uncommon Carriers",248,"John McPhee"},
{"Heirs of General Practice",128,"John McPhee"},
{"The Control of Nature",288,"John McPhee"},
{"Annals of the Former World",720,"John McPhee"},
{"Coming Into the Country",448,"John McPhee"},
{"La Place de la Concorde Suisse",160,"John McPhee"},
{"Giving Good Weight",288,"John McPhee"},
{"Rising from the Plains",208,"John McPhee"},
{"The Heidi Chronicles",81,"Wendy Wasserstein"},
{"The Heidi Chronicles: Uncommon Women and Others & Isn't It Romantic",249,"Wendy Wasserstein"},
{"Active Literacy Across the Curriculum: Strategies for Reading  Writing  Speaking  and Listening",138,"Heidi Hayes Jacobs"},
{"Simply Beautiful Beaded Jewelry",128,"Heidi Boyd"},
{"Always Enough: God's Miraculous Provision Among the Poorest Children on Earth",192,"Heidi Baker/Rolland Baker"},
{"Mapping the Big Picture: Integrating Curriculum & Assessment K-12",108,"Heidi Hayes Jacobs"},
{"Heidi (Heidi  #1-2)",352,"Johanna Spyri/Beverly Cleary/Angelo  Rinaldi"}};

    printf("Livros fora de ordem:");
    exibirLivrosComoTabela(livros, 54);

    //Chama o m�todo Bubble Sort para ordenar o vetor de livros
    bubble_sort(livros, 54);

    printf("\n\n\nLivros ordenados:");
    exibirLivrosComoTabela(livros, 54);

    return 0;
}

//Defini��es das fun��es

//Mostrar uma estrutura Livro
void mostrarLivro(Livro livro){
    //Utilize: 50 espa�os para o nome, 4 espa�os para a quantidade de p�ginas e 40 espa�os para o(s) nome(s) do(s) autor(es)
    printf("%-100s\t", livro.titulo);
    printf("%4i\t", livro.paginas);
    printf("%-40s\t", livro.autor);
    printf("\n");
}

//Compara duas estruturas Livro
int comparar(Livro l1, Livro l2){

    return strcmp(l1.titulo , l2.titulo);
}

//Troca dois elementos em um vetor
void trocar(Livro livros[], int posicao){
    Livro aux;

    aux = livros[posicao];
    livros[posicao] =  livros[posicao+1];
    livros[posicao+1] = aux;
}

//Aplica o algoritmo de Bubble Sort
void bubble_sort(Livro livros[], int tamanho){
    int i,j;

    for(i=(tamanho); i>=1; i--){
        for(j=0; j<(i-1); j++){
            if(comparar(livros[j], livros[j+1])==1){
                trocar(livros, j);
            }
        }
    }
}

//Exibir tabela com os livros
void exibirLivrosComoTabela(Livro livros[], int tamanho){
    int i;

    printf("\n\n");
    printf("Titulo\t\t\t\t\t\t\t\t\t\t\t\t\t ");
    printf("Pag\t");
    printf("Autor");
    printf("\n\n");

    for(i=0; i<tamanho; i++){
        mostrarLivro(livros[i]);
    }
}

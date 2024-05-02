/*
 * AritMix - Analisador de expressoes aritmeticas In-Fixas.
 * Prof.: Cleuton Sampaio
 * (ANSI C++ com C++ Standard Template Library)
 *
 * Versão atual: 1.0 - Marco 2003
 *
 * Operadores aritmeticos:
 *     "+" -> Soma
 *     "-" -> Subtracao
 *     "*" -> Multiplicao
 *     ":" -> Divisao
 *     "^" -> Exponenciao
 *
 * Aceita parentesis
 *
 * Casos de teste (ja� calculados):
 * 1+2 = 3
 * 1--3 = ERRO!
 * ((5-3) * (2*3) -1) = 11
 * 1:(5^(3-2)+1) = 0,166666667
 * 4^(1:2) = 2
 * ((1 + 2) * (6/2)) = ERRO!
 * (1+2)^((4-2) * (1+2)) = 729
 * -3 *(-2*5)^2 = -300
 *
 * Uso: aritmix [opcoes]
 * -d = debug: imprimir calculos e pilha
 * -t = executar os testes: roda as expressoes de teste acima.
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

bool debug = false;
bool runTests = false;

#define DEBUG(msg) if (debug) cout << endl << msg << endl;
#define ERRO(msg) cout << endl << "**** ERRO: " << msg << endl;



typedef struct elementoStruct {
        bool fim;
        bool erro;
        bool eOperando;
        double operando;
        bool eOperador;
        char operador;} TElemento;

stack <double> pilha;
vector <TElemento> listaPosFixa;
stack <char> pilhaOperadores;

void parseArgs(int qtde, char* args[]) {
     for (int x = 0; x < qtde; x++) {
         string arg (args[x]);
         if (arg == "-d") {
            debug = true;
         }
         if (arg == "-t") {
        	 runTests = true;
         }
     }
}

void posfixa ( double operando ) {
       pilha.push(operando);
}


void posfixa ( char operador ) {
       double op2 = pilha.top();
       pilha.pop();
       double op1 = pilha.top();
       pilha.pop();
       double resultado = 0.0;
       stringstream ss1;
       string msg;
       if (operador == '+') {
          resultado = op1 + op2;
       }
       else if (operador == '*') {
               resultado = op1 * op2;
            }
            else if (operador == ':' || operador == '/') {
                    resultado = op1 / op2;
                 }
                 else if (operador == '^') {
                         resultado = pow(op1,op2);
                      }
                      else  if (operador == '-') {
                               resultado = op1 - op2;
                            }
                            else if (operador == '^') {
                            		resultado = pow(op1,op2);
                            }
                            else {
                                 ERRO("**** Operador invalido: " + operador);
                                 return;
                            }
       ss1 << "CALCULAR: " << operador
                          << "(" << op1 << ", " << op2
                          << ")" << " = " << resultado;
       getline(ss1, msg);
       DEBUG(msg);

       pilha.push(resultado);
}

bool isOperador ( char pos ) {
     bool retorno = false;
     if (pos == '+' || pos == '-' || pos == '^' ||
         pos == '*' || pos == ':' || pos == '/' ||
         pos == '^' ||
         pos == '(' || pos == ')') {
         retorno = true;
     }
     return (retorno);
}

TElemento parse (string expressao, int &posicao) {
       TElemento elem = {false, false, false, 0.0, false, 0};
       string operando = "";

       stringstream stream;
       while (true) {
             if ((unsigned) posicao >= expressao.length()) {
                if (operando.length() > 0) {
                   stream << operando;
                   stream >> elem.operando;
                   elem.eOperando = true;
                   break;
                }
                elem.fim = true;
                break;
             }
             if (isdigit(expressao[posicao]) || expressao[posicao] == '.') {
                operando += expressao[posicao];
                posicao++;
             }
             else if (isOperador(expressao[posicao])) {

                     if (operando.length() > 0) {
                        // retorna o operando
                        stream << operando;
                        stream >> elem.operando;
                        elem.eOperando = true;
                        break;
                     }
                     else {
                          // retorna o operador
                          elem.eOperador = true;
                          elem.operador = expressao[posicao];
                          posicao++;
                          break;
                     }
                  }
                  else {
                       // é whitespace
                	  if (!isspace(expressao[posicao]) ) {
                		  cout << endl << "**** ERRO: caracter invalido na expressao: "
                		  	   << expressao[posicao] << " na posicao: " << posicao <<
                		  	   endl << "[[" << expressao << "]]";

                		  elem.erro = true;
                		  break;
                	  }
                	  posicao++;
                  }
       }
       return (elem);
}

int pegarPrecedencia (char op) {
    int resultado = 3;
    if (op == '^' || op == '(' || op == ')') {
           resultado = 1;
    }
    else if (op == '*' || op == ':' || op == '/') {
            resultado = 2;
         }

    return (resultado);
}

int compararPrecedencia (char op1, char op2) {

    int preced1 = pegarPrecedencia(op1);
    int preced2 = pegarPrecedencia(op2);
    return (preced1 - preced2);
}

double analisarInfixa (string expressao) {
       TElemento elem;
       int posic = 0;
       double resultado = 0.0;
       listaPosFixa.clear();
       while (!pilha.empty()) {
    	   pilha.pop();
       }
       while (!pilhaOperadores.empty()) {
    	   pilhaOperadores.pop();
       }
       char op = 0;
       TElemento temp;
       bool ultimoOperador = false;
       stringstream ss;
       string msg = "";
       bool inicioExpressao = true;
       bool inverterSinal = false;
       while (true) {
             elem = parse (expressao, posic);
             if (elem.erro) {
            	 return 0.0;
             }
             if (elem.fim) {
                break;
             }
             if (elem.eOperando) {
        		 inicioExpressao = false;
            	 if (inverterSinal) {
            		 elem.operando = -1 * elem.operando;
            		 inverterSinal = false;
            	 }
                listaPosFixa.push_back(elem);
                ultimoOperador = false;
             }
             else {
            	 // é um operador

            	 if (inicioExpressao) {
            		 // é um '-' no início de uma expressão?
            		 inicioExpressao = false;
            		 if (elem.operador == '-') {
            			 inverterSinal = true;
            			 continue;
            		 }
            	 }

            	 if (elem.operador == '(') {
            		 inicioExpressao = true;
            	 }

                  if (elem.operador != '(' && elem.operador != ')') {
                     if (ultimoOperador) {
                        ERRO("Dois operadores seguidos!");
                        return (0.0);
                     }
                     else {
                          ultimoOperador = true;
                     }
                  }

                  if (elem.operador == ')') {
                     // Retirar todos até encontrar um "("
                     while (true) {
                           if (!pilhaOperadores.empty()) {
                              op = pilhaOperadores.top();
                              pilhaOperadores.pop();
                              if (op == '(') {
                                     break;
                              }
                              temp.eOperador = true;
                              temp.eOperando = false;
                              temp.fim = false;
                              temp.operador = op;
                              temp.operando = 0.0;
                              listaPosFixa.push_back(temp);
                           }
                           else {
                                break;
                           }
                     }
                  }
                  else {
                       while ((!pilhaOperadores.empty()) &&
                             (compararPrecedencia(elem.operador, pilhaOperadores.top()) > 0) &&
                             (pilhaOperadores.top() != '(')) {
                             temp.eOperador = true;
                             temp.eOperando = false;
                             temp.fim = false;
                             temp.operador = pilhaOperadores.top();
                             temp.operando = 0.0;
                             listaPosFixa.push_back(temp);
                             pilhaOperadores.pop();

                       }
                       pilhaOperadores.push(elem.operador);
                  }
             }
       }

       // Descarrega a pilha de operadores
       while (true) {
          if (!pilhaOperadores.empty()) {
             op = pilhaOperadores.top();
             pilhaOperadores.pop();
             temp.eOperador = true;
             temp.eOperando = false;
             temp.fim = false;
             temp.operador = op;
             temp.operando = 0.0;
             listaPosFixa.push_back(temp);
          }
          else {
               break;
          }
       }

       // falta pegar cada elemento da listaPosFixa e chamar posfixa
       vector<TElemento>::iterator it;
       for ( it=listaPosFixa.begin() ; it < listaPosFixa.end(); it++ ) {
           if ((*it).eOperador) {
              DEBUG((*it).operador);
              if (pilha.size() < 2) {
                 ERRO("Menos de 2 operandos! Expressao invalida");
                 while (!pilha.empty()) {
                	 pilha.pop();
                 }
                 break;
              }
              posfixa ((*it).operador);
           }
           else {
                DEBUG((*it).operando);
                posfixa ((*it).operando);
           }
       }

       if (pilha.empty()) {
          ERRO("Pilha vazia - expressao invalida!");
          return (0.0);
       }
       else {
              resultado = pilha.top();
              pilha.pop();
              return (resultado);
       }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "* AritMix - Analisador de expressoes aritmeticas In-Fixas." << endl
                << "* Prof.: Cleuton Sampaio" << endl
                << "* (ANSI C++ com C++ Standard Template Library)" <<  endl
                << "*" << endl
                << "* Versão atual: 1.0 - Marco 2003" <<  endl
                << "*" << endl
                << "* Operadores aritmeticos:" <<  endl
                << "*     '+' -> Soma" <<  endl
                << "*     '-' -> Subtracao" <<  endl
                << "*     '*' -> Multiplicao" <<  endl
                << "*     ':' -> Divisao" <<  endl
                << "*     '^' -> Exponenciao" <<  endl
                << "*" <<  endl
                << "* Aceita parentesis" <<  endl
                << "*" <<  endl
                << "* Casos de teste (ja calculados):" <<  endl
                << "* 1+2 = 3" <<  endl
                << "* 1--3 = ERRO!" <<  endl
                << "* ((5-3) * (2*3) -1) = 11" <<  endl
                << "* 1:(5^(3-2)+1) = 0,166666667" <<  endl
                << "* 4^(1:2) = 2" <<  endl
                << "* ((1 + 2) * (6/2)) = ERRO!" <<  endl
                << "* (1+2)^((4-2) * (1+2)) = 729" <<  endl
                << "* -3 *(-2*5)^2 = -300" <<  endl
                << "*" <<  endl
                << "* Uso: aritmix <expressao_aritmetica>" << endl;
    } else {
        for(int i = 1; i < argc; i++) {
            std::string arg = argv[i];
            std::cout << "expressao: " << i << ": " << arg << std::endl;
            std::cout << "resultado: " << analisarInfixa(arg) << endl;
            break;
        }
    }
    return 0;
}

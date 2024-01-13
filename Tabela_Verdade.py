import itertools
import pandas as pd
import tkinter as tk

#Lendo a fórmula e guardando as variáveis e operadores lógicos em uma lista de tokens
def guarda_formula(formula):
    tokens = []
    i = 0
    while i < len(formula):
        char = formula[i]
        if char == 'v': tokens.append(['OPERADOR', 'OU'])
        elif char == '^': tokens.append(['OPERADOR', 'E'])
        elif char == '-': 
            if formula[i+1] == '>':#Verificando se o próximo caractere é o operador condicional 
                tokens.append(['OPERADOR', 'CONDICIONAL'])
                i += 1
        elif char == '=': tokens.append(['OPERADOR', 'BICONDICIONAL'])
        elif char == '~': tokens.append(['OPERADOR', 'NEGACAO'])
        elif char.isalpha(): tokens.append(['VARIAVEL', char])
        i += 1
    return tokens

#Função que recebe uma árvore e um dicionário com os valores das variáveis e retorna o resultado da fórmula
def calcular_valor(arvore, valores):
    if arvore[0] == 'VARIAVEL':
        return valores[arvore[1]]
    elif arvore[0] == 'OPERADOR':
        operador = arvore[1]
        if operador == 'NEGACAO':
            operando = calcular_valor(arvore[2], valores)
            return not operando
        else:
            esquerda = calcular_valor(arvore[2], valores)
            direita = calcular_valor(arvore[3], valores)
            if operador == 'E':
                return esquerda and direita
            elif operador == 'OU':
                return esquerda or direita
            elif operador == 'CONDICIONAL':
                return (not esquerda) or direita
            elif operador == 'BICONDICIONAL':
                return esquerda == direita
    else:
        raise ValueError(f"Token desconhecido: {arvore[0]}")


#Função para criar a árvore de expressão
def criaArvore(tokens):
    if len(tokens) == 1:
        return ['VARIAVEL', tokens[0][1]]  

    menor_precedencia = float('inf')
    operador_idx = -1

    for i, token in enumerate(tokens):
        if token[0] == 'OPERADOR':
            precedencia = obter_precedencia(token[1])
            if precedencia <= menor_precedencia: 
                menor_precedencia = precedencia
                operador_idx = i

    if operador_idx == -1:
        raise ValueError("Erro: Nenhum operador encontrado.")

    operador = tokens[operador_idx][1]

    if operador == 'NEGACAO':
        arvore_direita = criaArvore(tokens[operador_idx + 1:])
        return ['OPERADOR', operador, arvore_direita]
    else:
        arvore_esquerda = criaArvore(tokens[:operador_idx])
        arvore_direita = criaArvore(tokens[operador_idx + 1:])
        return ['OPERADOR', operador, arvore_esquerda, arvore_direita]

#Função para obter a precedência dos operadores
#Determina a ordem das operações na arvore de expressões

def obter_precedencia(operador):
    precedencia = {'NEGACAO': 5, 'E': 4, 'OU': 3, 'CONDICIONAL': 2, 'BICONDICIONAL': 1}
    return precedencia.get(operador, 0)

#interface gráfica
def processamento_interface():
    formula = entry.get()#recebe a formula logica do usuário
    tokens = guarda_formula(formula)#cria uma lista de tokens
    arvore = criaArvore(tokens)#cria a arvore de expressões a partir da lista de tokens
    variaveis_presentes = list(set([variavel[1] for variavel in tokens if variavel[0] == 'VARIAVEL']))
    valores_possiveis = list(itertools.product([False, True], repeat=len(variaveis_presentes)))
    cabecalho = sorted(variaveis_presentes) + ['Resultado']
    tabela_verdade = []
    resultados = []
    for valores in valores_possiveis:
        valores_dict = dict(zip(sorted(variaveis_presentes), valores))
        resultado = calcular_valor(arvore, valores_dict)
        resultados.append(resultado)
        tabela_verdade.append(list(valores) + [resultado])
    df = pd.DataFrame(tabela_verdade, columns=cabecalho)
    result_text.delete(1.0, tk.END)
    result_text.tag_configure("center", justify='center')
    result_text.insert(tk.END, df.to_string(index=False), "center")


    #Verificando se a fórmula é uma tautologia
    if all(resultados):
        result_text.insert(tk.END, "\n\nA fórmula é uma tautologia.", "center")
    else:
        result_text.insert(tk.END, "\n\nA fórmula não é uma tautologia.", "center")

#Abrindo a interface gráfica e configurando o botão de tela cheia
root = tk.Tk()
root.attributes('-fullscreen', True)
root.bind("<Escape>", lambda event: root.attributes("-fullscreen", False))
root.bind("<F11>", lambda event: root.attributes("-fullscreen", True))

#Configurando a interface gráfica com textos
#Título
title = tk.Label(root, text="Gerador de Tabela Verdade", font=("Arial", 20), pady=10, fg="hotpink")
title.pack()

#Instruções
instructions = tk.Label(root, text="Para gerar uma Tabela, insira abaixo uma fórmula lógica", font=("Arial", 14), pady=10)
instructions.pack()
operators = tk.Label(root, text="ATENÇÃO: use apenas os operadores informados a seguir:\n"
                                "Negação (~), Conjunção (^), Disjunção (v), Condicional (->), Bicondicional (<=>)",
                     font=("Arial", 14), pady=10)
operators.pack()

#Exemplos de fórmulas
examples = tk.Label(root, text="Exemplo de fórmula: (AvB)->C\n"
                               "Exemplo de fórmula: (A^B)<=>~C",
                    font=("Arial", 14), pady=10)
examples.pack()

#entrada da fórmula
entry = tk.Entry(root, font=("Arial", 14), width=50)
entry.pack(pady=10)

#botão para gerar a tabela verdade
button = tk.Button(root, text="Gerar Tabela", command=processamento_interface, font=("Arial", 12), bg="hotpink", fg="black")
button.pack(pady=10)

result_text = tk.Text(root, font=("Arial", 12))
result_text.pack(pady=10, expand=True, fill='both')
root.mainloop()

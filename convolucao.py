import cv2
import torch
import numpy as np
import matplotlib.pyplot as plt

#Função para receber uma imagem de escolha do usuário
#Recebe a imagem e a transforma em uma imagem em escalas de cinza
def recebe_imagem(imagem_usuario):
    imagem = cv2.imread(imagem_usuario, cv2.IMREAD_GRAYSCALE)
    return torch.tensor(imagem)

#Função apenas para manter a imagem colorida salva
def imagem_colorida(imagem_usuario):
    imagem_colorida = cv2.imread(imagem_usuario)
    return torch.tensor(imagem_colorida)

#Função para receber os aquivos de escolha do usuário, que contem os núcleos de convolução
def recebe_nucleo(nucleo_usuario):
    nucleo = []
    with open(nucleo_usuario) as arquivo:
        for linha in arquivo:
            nucleo.append([float(x) for x in linha.split()])
    return torch.tensor(nucleo)

#Função para aplicar a convolução na imagem de escolha do usuário
def convolucao(imagem, nucleo):
    #Pegando as dimensões da imagem e do núcleo de convolução
    imagem_h, imagem_w = imagem.shape
    nucleo_h, nucleo_w = nucleo.shape

    #Calculando a margem necessária para a largura e altura da imagem
    #Serve para que a imagem de saida possua o mesmo tamanho da de entrada, não havendo perca de informação
    pad_h = nucleo_h//2
    pad_w = nucleo_w//2

    #Aplicando o padding (margem) a imagem em escalas de cinza
    padded_imagem = torch.nn.functional.pad(imagem, (pad_w, pad_w, pad_h, pad_h))

    #Ajustando o tamanho da imagem de saída para corresponder ao tamanho da imagem de entrada após o padding
    imagem_saida = torch.zeros((imagem_h, imagem_w))

    #Aplicando a convolução na imagem de entrada 
    for i in range (pad_h, imagem_h + pad_h):
        for j in range (pad_w, imagem_w + pad_w):
            regiao = padded_imagem[i-pad_h:i+pad_h+1, j-pad_w:j+pad_w+1]#Calculando a região da imagem que será aplicada a convolução
            imagem_saida[i - pad_h, j - pad_w] = torch.sum(regiao*nucleo)#Aplicando a convolução na região da imagem
        

    return imagem_saida


#Função para mostrar a imagem na tela
def mostra_imagem(imagem_original, imagem_resultante):
    
    #Exibindo a imagem resultante
    fig, axes = plt.subplots(1, 2, figsize=(10, 5))#Cria uma figura com 1 linha e 2 colunas para os subplots
    axes[0].imshow(cv2.cvtColor(imagem_original, cv2.COLOR_BGR2RGB))  
    axes[0].set_title('Imagem Original')
    axes[0].axis('off')
    axes[1].imshow(imagem_resultante, cmap='gray', vmin=0, vmax=255) 
    axes[1].set_title('Imagem Resultante')
    axes[1].axis('off')
    plt.show(block=False)


#Função para salvar a imagem resultante da convolução em um arquivo .jpg
def salva_img(res_conv):
    print('Digite o nome do arquivo para salvar a imagem resultante da convolução:')
    nome_arq_novo = input()
    nome_arq_novo = nome_arq_novo + '.jpg'
    cv2.imwrite(nome_arq_novo, res_conv.numpy())

#Recebendo a imagem de escolha do usuário e passando para a função recebe_imagem
print('Digite o nome da imagem para realizar a convolução:')
nome_imagem = input()
img = recebe_imagem(nome_imagem)
print('Tensor da imagem:')
print(img)#Mostrando o tensor da imagem

#Recebendo o arquivo de escolha do usuário, que contem o núcleo de convolução e passando para a função recebe_nucleo
print('Digite o nome do arquivo que contem a matriz de convolução desejada:')
nome_nucleo = input()
nucl = recebe_nucleo(nome_nucleo)
print('Núcleo de convolução:')
print(nucl)#Mostrando o tensor do núcleo de convolução

#Aplicando a convolução na imagem de escolha do usuário e salvando a imagem resultante 
res_conv = convolucao(img,nucl)
print('Tensor da imagem resultante da convolução:')
print(res_conv)#Mostrando o tensor da imagem resultante


#Mostra a imagem resultante
mostra_imagem(imagem_colorida(nome_imagem).numpy(), res_conv.numpy())

#Espera até que a janela da imagem seja fechada
plt.waitforbuttonpress()

print('Deseja salvar a imagem resultante da convolução? (S/N)')
resposta = input()
if resposta == 'S' or resposta == 's':
    salva_img(res_conv)
    print('Imagem salva')
else:
    print('Imagem não salva')

import cv2
import torch
import numpy as np
import matplotlib.pyplot as plt

#Função para receber uma imagem de escolha do usuário
#Recebe a imagem e a transforma em uma imagem em escalas de cinza
def recebe_imagem(imagem_usuario):
    imagem = cv2.imread(imagem_usuario, cv2.IMREAD_GRAYSCALE)
    return torch.tensor(imagem)

#funcão para adicionar o ruido gaussiano, salt and pepper e speckle a imagem
def adiciona_ruido(imagem, tipo_ruido):
    #Cria uma cópia da imagem para adicionar o ruído
    imagem_ruido = imagem.clone()
    if tipo_ruido == 'gaussiano':
        ruido = torch.randn(imagem_ruido.size())*0.1
        imagem_ruido = imagem_ruido + ruido
    elif tipo_ruido == 'salt and pepper':
        ruido = torch.rand(imagem_ruido.size())
        imagem_ruido[ruido < 0.05] = 0
        imagem_ruido[ruido > 0.95] = 255
    elif tipo_ruido == 'speckle':
        ruido = torch.randn(imagem_ruido.size())*0.1
        imagem_ruido = imagem_ruido + imagem_ruido*ruido
    else:
        raise ValueError("Tipo de ruído desconhecido. Escolha entre: 'gaussiano', 'salt_and_pepper' ou 'speckle'.")
    return imagem_ruido

def suaviza_imagem(imagem, tipo_suavizacao):
    # Converte a imagem para numpy para usar as funções do OpenCV
    imagem = imagem.numpy()
    if tipo_suavizacao == 'media':
        imagem_suavizada = cv2.blur(imagem, (5,5))
    elif tipo_suavizacao == 'mediana':
        imagem_suavizada = cv2.medianBlur(imagem, 5)
    elif tipo_suavizacao == 'gaussiana':
        imagem_suavizada = cv2.GaussianBlur(imagem, (5,5), 0)
    else:
        raise ValueError("Tipo de suavização desconhecido. Escolha entre: 'media', 'mediana' ou 'gaussian'.")
    return imagem_suavizada

#Função para aplicar a convolução com nucleo sobel na imagem de escolha do usuário
def convolucao(imagem, nucleo):

    #Converte a imagem para um tensor PyTorch
    imagem = torch.from_numpy(imagem)
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

#função para adicionar a detecção de bordas a imagem
def detecta_bordas(imagem, tipo_bordas):
    imagem = cv2.convertScaleAbs(imagem)
    if tipo_bordas == 'sobel':
        # Cria a matriz de sober vertical
        matriz_sobel_v = torch.tensor([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
        convolucao_sobel_v = convolucao(imagem, matriz_sobel_v)
        return convolucao_sobel_v
    elif tipo_bordas == 'laplaciano':
        imagem_bordas = cv2.Laplacian(imagem, cv2.CV_64F)
    elif tipo_bordas == 'canny':
        imagem_bordas = cv2.Canny(imagem, 100, 200)
    else:
        raise ValueError("Tipo de detecção de bordas desconhecido. Escolha entre: 'sobel', 'laplaciano' ou 'canny'.")
    return imagem_bordas

#Função para mostrar as imagens
def mostra_imagens(imagem_original, imagem_ruido, imagem_suavizada, imagem_bordas):
    fig, axs = plt.subplots(2, 2, figsize=(20, 15))

    axs[0, 0].imshow(imagem_original, cmap='gray')
    axs[0, 0].set_title('Imagem Original')
    axs[0, 0].axis('off')

    axs[0, 1].imshow(imagem_ruido, cmap='gray')
    axs[0, 1].set_title('Imagem com Ruído')
    axs[0, 1].axis('off')

    axs[1, 0].imshow(imagem_suavizada, cmap='gray')
    axs[1, 0].set_title('Imagem Suavizada')
    axs[1, 0].axis('off')

    axs[1, 1].imshow(imagem_bordas, cmap='gray', vmin=0, vmax=255)
    axs[1, 1].set_title('Imagem com Detecção de Bordas')
    axs[1, 1].axis('off')

    plt.show()
#Função para obter a escolha do usuário e fazer a verificação da entrada
def obter_entrada_usuario(texto, opcoes):
    print(texto)
    for i, opcao in enumerate(opcoes, 1):
        print(f"{i}- {opcao}")
    while True:
        entrada_usuario = input()
        try:
            escolha_usuario = int(entrada_usuario)
            if 1 <= escolha_usuario <= len(opcoes):
                return opcoes[escolha_usuario - 1]
            else:
                print("Entrada inválida. Por favor, insira um número dentro do intervalo.")
        except ValueError:
            print("Entrada inválida. Por favor, insira um número.")

#Recebe a imagem de escolha do usuário
nome_imagem = input('Digite o nome da imagem para adicionar ruído:\n')
img = recebe_imagem(nome_imagem)

#Recebe a escolha do usuário para o tipo de ruído
tipo_ruido = obter_entrada_usuario('Informe a opção que tenha o ruído que deseja adicionar a imagem:', ['gaussiano', 'salt and pepper', 'speckle'])
img_ruido = adiciona_ruido(img, tipo_ruido)

#Recebe a escolha do usuário para o tipo de suavização 
tipo_suavizacao = obter_entrada_usuario('Informe a opção que tenha a suavização que deseja aplicar a imagem:', ['media', 'mediana', 'gaussiana'])
img_suavizada = suaviza_imagem(img_ruido, tipo_suavizacao)

#Recebe a escolha do usuário para o tipo de detecção de bordas
tipo_bordas = obter_entrada_usuario('Informe a opção que tenha a borda que deseja aplicar a imagem:', ['sobel', 'laplaciano', 'canny'])
img_bordas = detecta_bordas(img_suavizada, tipo_bordas)

#Mostra as imagens
mostra_imagens(img, img_ruido, img_suavizada, img_bordas)


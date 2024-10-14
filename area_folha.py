import cv2
import numpy as np

#função para aplicar mascara e transformar a imagem em preto e branco
def transform_image(image_path):
    img = cv2.imread(image_path)

    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(hsv, (36, 70, 20), (70, 255, 255))

    imask = mask > 0
    green_img = np.zeros_like(img, np.uint8)
    green_img[imask] = img[imask]
    
    gray = cv2.cvtColor(green_img, cv2.COLOR_BGR2GRAY)
    _, threshold = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY)

    return img, green_img, threshold   

#calcula area da folha
def calculate_leaf_area(threshold):
    
    contours, _ = cv2.findContours(threshold, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    largest_contour = max(contours, key=cv2.contourArea)
    leaf_area = cv2.contourArea(largest_contour)
    return leaf_area

#folha antes
img_antes, green_img_antes, threshold_antes = transform_image("folha_antes_teste.tif")
area_antes = calculate_leaf_area(threshold_antes)
print("Área da folha antes: {:.2f} square pixels".format(area_antes))

#folha depois
img_depois, green_img_depois, threshold_depois = transform_image("folha_depois_teste.tif")
area_depois = calculate_leaf_area(threshold_depois)
print("Área da folha depois: {:.2f} square pixels".format(area_depois))

diferenca = area_antes - area_depois
print("Diferença de área: {:.2f} square pixels".format(diferenca))



#mostra a imagem original, a imagem com a máscara aplicada e a imagem em preto e branco
def show_images(img1, green_img1, threshold1, img2, green_img2, threshold2):
   
    # Redimensiona todas as imagens para terem o mesmo tamanho
    image1 = cv2.resize(img1, (500, 500))
    image2 = cv2.resize(green_img1, (500, 500))
    image3 = cv2.resize(threshold1, (500, 500))
    image4 = cv2.resize(img2, (500, 500))
    image5 = cv2.resize(green_img2, (500, 500))
    image6 = cv2.resize(threshold2, (500, 500))

    # Converte as imagens de threshold para imagens coloridas
    image3_color = cv2.cvtColor(image3, cv2.COLOR_GRAY2BGR)
    image6_color = cv2.cvtColor(image6, cv2.COLOR_GRAY2BGR)

    # Cria uma matriz de imagens 2x3
    img_top = np.hstack((image1, image2, image3_color))
    img_bottom = np.hstack((image4, image5, image6_color))
    img_final = np.vstack((img_top, img_bottom))

    # Mostra a imagem final
    cv2.namedWindow('Imagens', cv2.WINDOW_NORMAL)
    cv2.resizeWindow('Imagens', 900, 700)
    cv2.imshow("Imagens", img_final)    
    cv2.waitKey(0)
    cv2.destroyAllWindows()
  
show_images(img_antes, green_img_antes, threshold_antes, img_depois, green_img_depois, threshold_depois)




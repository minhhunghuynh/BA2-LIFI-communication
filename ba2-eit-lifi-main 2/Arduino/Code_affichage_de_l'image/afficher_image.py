from PIL import Image
import numpy as np


""" Cette fonction prends deux arguments qui sont des fichiers. un fichier contenant les données binaire (datafile) à décrypter, 
et le deuxième qui contient le résultat de la traduction du premier fichier """

def lire_image(datafile, output_image_receive):
    with open(datafile, 'rb') as file:
        binary_data = file.read()

    # Récupérer la largeur et la hauteur (2 octets chacun)
    width = int.from_bytes(binary_data[:2], byteorder='big')
    height = int.from_bytes(binary_data[2:4], byteorder='big')



    # Récupérer les données des pixels (L*H*3 octets)
    flat_pixel_data = binary_data[4:]

    # Convertir les données en tableau numpy et redimensionner
    pixel_data = np.frombuffer(flat_pixel_data, dtype=np.uint8).reshape((height, width, 3))

    # Créer une nouvelle image à partir des données
    image = Image.fromarray(pixel_data, 'RGB')

    # Sauvegarder l'image en format JPEG
    image.save(output_image_receive, format='JPEG')
    image.show()

# Utiliser la fonction pour lire, redimensionner et sauvegarder l'image en JPEG pour faire un appel de fonction
lire_image('image_data.bin', 'output_image.jpg')
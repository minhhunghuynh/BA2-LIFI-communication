def display_image_from_list(data):
    # Vérifier le préambule
    preamble = data[:3]
    if bytes(preamble) != b'IMG':
        raise ValueError('Préambule incorrect')

    # Lire les dimensions de l'image
    width = data[3]
    height = data[4]

    # Lire la palette de couleurs
    palette = []
    index = 5
    for i in range(256):
        r = data[index]
        g = data[index + 1]
        b = data[index + 2]
        palette.append((r, g, b))
        index += 3

    # Lire les pixels de l'image
    pixels = []
    for i in range(width * height):
        color_index = data[index]
        pixels.append(palette[color_index])
        index += 1

    # Créer une image vide de dimensions height x width avec 3 canaux de couleur (RGB)
    img = np.zeros((height, width, 3), dtype=np.uint8)

    # Remplir l'image avec les pixels reçus
    for y in range(height):
        for x in range(width):
            img[y, x] = pixels[y * width + x]

    # Afficher l'image
    plt.imshow(img)
    plt.title(f"Image {width}x{height}")
    plt.axis('off')  # Masquer les axes
    plt.show()

# Appeler la fonction pour afficher l'image
display_image_from_list(decimal_data)

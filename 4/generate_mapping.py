import sys

import numpy as np
import cv2


if __name__ == '__main__':
    in_file = sys.argv[1]
    output_file = sys.argv[2]
    doc = None
    input_img = cv2.imread(in_file)
    if input_img.shape[0] != 3 and input_img.shape[1] != 256:
        print('Wrong Map Image, it should by 3 by 256 pixels')
        exit(1)
    map_image = np.zeros((3, 256)).astype(int)
    for i in range(input_img.shape[0]):
        for j in range(input_img.shape[1]):
            map_image[2-i][j] = input_img[i][j][2-i]

    list_strings = []
    for i in range(map_image.shape[0]):
        list_strings.append('{' + ','.join(map(str, map_image[i].tolist())) + '}')
    generated_string = '{{' + ','.join(list_strings) + '}}'

    with open(output_file, 'w') as fp:
        fp.write('#include <array>\n')
        fp.write(f'std::array<std::array<int, 256>, 3> map_image {generated_string};')

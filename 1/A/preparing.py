#!/usr/bin/env python3
import sys

if __name__ == '__main__':
    output_file = sys.argv[1]
    header_text = '''
    namespace TP {
        int add_2(int value) {
            return value + 2;
        }
    };
    '''
    with open(output_file, 'w') as fp:
        fp.write(header_text)

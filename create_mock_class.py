#!/usr/bin/env python3

import regex


interface_name = 'IBackend'
implementer_name = 'BackendMockTest'


implementer_h = open(implementer_name + '.h', 'w')
implementer_cpp = open(implementer_name + '.cpp', 'w')
interface_h = open(interface_name + '.h', 'r')

temp = interface_h.read().splitlines()

# Create headerfile:
for line in temp:
    line = regex.sub('= 0;', 'override;', line)
    line = regex.sub('IBackend', 'MockBackend', line)
    line = regex.sub('IBACKEND', 'MOCKBACKEND', line) # ignore case how!?
    implementer_h.write(line + "\n")

# create cpp file
pattern=r'virtual\s([\w:]+)\s+(\w+)(\((\w+\s\w+)?\))'
for line in temp:
    if regex.search(pattern, line):
        m = regex.search(pattern, line)

        scoped_function_name = '{} {}{}{}'.format(m[1], 'BackendMock::', m[2], m[3])
        return_value = m[1]
        if return_value == 'bool':
            body = '{return true;}'
        elif return_value == 'void':
            body = '{ }'
        elif return_value == 'double':
            body = '{return 123.456;}'
        elif return_value == 'int':
            body = '{return 7331;}'
        elif return_value == 'std::string':
            body = '{return "abcd";}'

        implemented_function = scoped_function_name + body
        implementer_cpp.write(implemented_function + "\n")
        # print(implemented_function)

        
        

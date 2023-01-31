# -*- encoding: utf-8 -*-

import os
import sys

from setuptools import setup, find_packages
from os.path import exists

if sys.version_info[:2] < (3, 5):
   raise RuntimeError('Requires Python 3.5 or higher')

here = os.path.abspath(os.path.dirname(__file__))
try:
    README = open(os.path.join(here, 'README.rst')).read()
    CHANGES = open(os.path.join(here, 'CHANGES.txt')).read()
except IOError:
    README = CHANGES = ''

setup(
    name='tcpfilewriter',
    version="0.0.1",
    description='Connect to a TCP port and send a file through it',
    author='aog',
    author_email='<example@example.com>',
    packages=find_packages(),
    install_requires= [],
    tests_require=[],
    entry_points={
        'console_scripts': [
            'tcpfilewriter = tcpfilewriter:main'
        ]
    },
)

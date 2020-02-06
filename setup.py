#!/usr/bin/python3

from distutils.core import setup, Extension

ext = Extension(
    'botlib.sonar',
    libraries = ['wiringPi', 'pigpio'],
    sources = ['sonarmodule.c', 'sonic.c']
)

setup(
    name = 'ultrasonic',
    version = '0.0.1',
    description = 'A library for accessing HC-SR04 Ultrasonic sensors utilizing a Octosonar v2.1 board.',
    author = 'Jannik Beibl',
    ext_modules = [ext]
)

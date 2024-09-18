from setuptools import setup, find_packages
import platform

install_requires = ['pyserial']
if platform.system() == 'Linux':
    install_requires.append('pyudev')
elif platform.system() == 'Windows':
    install_requires.append('pywinusb')

setup(
    name='port_scanner',
    version='0.1',
    packages=find_packages(),
    install_requires=install_requires,
)

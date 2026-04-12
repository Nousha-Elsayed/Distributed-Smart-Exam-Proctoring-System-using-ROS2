from setuptools import find_packages
from setuptools import setup

setup(
    name='exam_proctoring_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('exam_proctoring_interfaces', 'exam_proctoring_interfaces.*')),
)

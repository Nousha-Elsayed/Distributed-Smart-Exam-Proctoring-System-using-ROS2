from setuptools import find_packages, setup

package_name = 'exam_proctoring_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='menna',
    maintainer_email='menna_elsayed33@icloud.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'camera_streamer    = exam_proctoring_pkg.camera_streamer:main',
            'face_detector      = exam_proctoring_pkg.face_detector:main',
            'depth_estimator    = exam_proctoring_pkg.depth_estimator:main',
            'behavior_node = exam_proctoring_pkg.behavior_node:main',

        ],
    },
)

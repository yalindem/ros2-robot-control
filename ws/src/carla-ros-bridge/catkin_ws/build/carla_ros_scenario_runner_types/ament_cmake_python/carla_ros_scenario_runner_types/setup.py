from setuptools import find_packages
from setuptools import setup

setup(
    name='carla_ros_scenario_runner_types',
    version='0.1.0',
    packages=find_packages(
        include=('carla_ros_scenario_runner_types', 'carla_ros_scenario_runner_types.*')),
)

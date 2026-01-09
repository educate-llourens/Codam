#!/usr/bin/env python3

class GardenError(Exception):
    def __init__(self, plant_name: str):
        self.plant_name: str = plant_name
        self.message: str = "Caught a garden error: "


class PlantError(GardenError):
    def __init__(self, plant_name):
        super().__init__(plant_name)
        self.message: str = "Caught PlantError: The "
        + plant_name + "plant is wilting!"


class WaterError(GardenError):
    def __init__(self, plant_name):
        super().__init__(plant_name)
        self.message: str = "Caught WaterError: The "
        + plant_name + "Not enough water in the tank!"


def test_custom_error_types() -> None:
    try:
        
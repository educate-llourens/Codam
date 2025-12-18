#!/usr/bin/env python3

class Plant:
    def __init__(self, plant_name: str, plant_height: int,
                 plant_age: int) -> None:
        self.plant_name = plant_name
        self.plant_height = plant_height
        self.plant_age = plant_age

    def grow(self) -> None:
        self.plant_height += 1
    
    def set_height(self) -> None:
        


class FloweringPlant(Plant):
    def __init__(self, plant_name, plant_height, plant_age):
        super().__init__(plant_name, plant_height, plant_age)


class PrizeFlower(FloweringPlant):
    def __init__(self, plant_name, plant_height, plant_age):
        super().__init__(plant_name, plant_height, plant_age)


class GardenManager:
    def __init__(self, garden_name: str) -> None:
        self.garden_name: str = garden_name
        self.plants: list[Plant] = []

    @classmethod
    def create_garden_network(cls,
                              garden_names: list[str]
                              ) -> list['GardenManager']:
        gardens: list[GardenManager] = []
        i: int = 0
        while i < len(garden_names):
            garden = cls(garden_names[i])
            gardens.append(garden)
            i += 1
        return gardens

    def add_plant(self, plant_name: str, plant_height: int,
                  plant_age: int) -> None:
        new_plant: Plant = Plant(plant_name, plant_height, plant_age)
        self.plants.append(new_plant)
